#include <iostream>
#include <string>
#include <exception>
#include <utility>
#include <math.h>

#include "stack/Stack.cpp"


struct ParseError : public std::exception
{
    std::string msg;

    explicit ParseError(std::string msg) {
        this->msg = std::move(msg);
    }

    const char * what () const noexcept override
    {
        return this->msg.c_str();
    }
};

enum TokenType {
    OPERATOR,
    NUMBER,
    PARENTHESIS,
};

struct Token {
    std::string text;
    TokenType type{};
};

class Stream {
    std::string str;

public:
    int p;

    explicit Stream(const std::string &str) {
        this->str = str;
        this->p = 0;
    }

    char seek() {
        if (!this->isEOS())
            return this->str[this->p++];
        return '\0';
    }

    char peek() {
        if (!this->isEOS())
            return this->str[this->p];
        return '\0';
    }

    static bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*'|| c == '/' || c == '^';
    }

    Token* seekToken() {
        if (this->isEOS()) return nullptr;
        auto token = new Token();
        token->text = "";

        char t = this->seek();

        if (isdigit(t)) {
            token->text += t;
            token->type = TokenType::NUMBER;
        } else if (Stream::isOperator(t)) {
            token->text += t;
            token->type = TokenType::OPERATOR;
        } else if (t == '(' || t == ')') {
            token->text += t;
            token->type = TokenType::PARENTHESIS;
        } else {
            this->throwError("Invalid expression");
        }

        return token;
    }

    bool isEOS() {
        return this->p >= this->str.size();
    }

    void throwError(const std::string& msg) {
        std::string temp = "\n";
        temp += this->str;
        temp += "\n";
        for (int i = 1; i < this->p; i++) {
            temp += " ";
        }
        temp += "^\n";
        temp += msg;
        throw ParseError(temp);
    }

    void reset() {
        this->p = 0;
    }
};

class ExpressionParser {
private:
    Stream stream;

    std::string buildOperands(Stack<std::string> operands, Stack<std::string> operators) {
        while (operands.size() > 1 && operators.size() > 0) {
            std::string op2 = operands.pop();
            std::string op1 = operands.pop();
            std::string op = operators.pop();
            operands.push(op1 + op2 + op);
        }
        if (operators.size() > 0 || operands.size() > 1) {
            throw ParseError("Invalid expression");
        }
        return operands.pop();
    }

    std::string _toPostfix(bool deep=false) {
        Stack<std::string> operands;
        Stack<std::string> operators;
        Token* tk = this->stream.seekToken();

        while (tk != nullptr) {
            if (tk->type == PARENTHESIS) {
                if (tk->text == ")") {
                    if (!deep) {
                        this->stream.throwError("Brackets mismatch");
                    }

                    return this->buildOperands(operands, operators);
                }
                if (tk->text == "(") {
                    operands.push(this->_toPostfix(true));
                }
            }
            else if (tk->type == NUMBER) {
                operands.push(tk->text);
            } else if (tk->type == OPERATOR) {
                while (operators.size() != 0 &&
                       ExpressionParser::getPrecedence(operators.peek()[0])
                       > ExpressionParser::getPrecedence(tk->text[0])
                        ) {
                    std::string op2 = operands.pop();
                    std::string op1 = operands.pop();
                    std::string op = operators.pop();
                    operands.push(op1 + op2 + op);
                }
                operators.push(tk->text);
            }

            tk = this->stream.seekToken();
        }

        return this->buildOperands(operands, operators);
    }

    static int getPrecedence(char op) {
        switch (op) {
            case '+':
            case '-':
                return 1;

            case '*':
            case '/':
                return 2;

            case '^':
                return 3;

            default:
                return 0;
        }
    }

    static int operate(char op, int op1, int op2) {
        switch (op) {
            case '+':
                return op1 + op2;
            case '-':
                return op1 - op2;
            case '*':
                return op1 * op2;
            case '/':
                return op1 / op2;
            case '^':
                return pow(op1,  op2);
            default:
                return 0;
        }
    }

public:
    explicit ExpressionParser(const std::string &expression)
            : stream(expression) {}

    std::string toPostfix() {
        return this->_toPostfix();
    }

    std::string evaluate() {
        Stack<std::string> operands;
        this->stream.reset();
        std::string postfix = this->toPostfix();

        std::string::iterator ch;
        for (ch = postfix.begin(); ch < postfix.end(); ch++) {
            if (isdigit(*ch)) {
                operands.push(std::string(1, *ch));
            } else if (Stream::isOperator(*ch)) {
                int op2 = std::stoi(operands.pop());
                int op1 = std::stoi(operands.pop());
                operands.push(std::to_string(ExpressionParser::operate(*ch, op1, op2)));
            }
        }

        return operands.pop();
    }
};

int main() {
    ExpressionParser parser("(2*3)+(4*5))");
    std::cout << parser.toPostfix() << "\n";
    std::cout << parser.evaluate() << "\n";
    return 0;
};