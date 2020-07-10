#include <iostream>
#include <string>

#include "stack/Stack.cpp"

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

    bool isEOS() {
        return this->p + 1 >= this->str.size();
    }

    void printError(const std::string error) {
        std::cout << this->str << std::endl;
        for (int i = 1; i < this->p; i++) {
            std::cout << " ";
        }
        std::cout << "^" << std::endl;
        std::cout << error << std::endl;
    }
};

class ExpressionParser {
private:
    Stream stream;
    Stack<char> stack;
    SingleLinkedList<int> openingBrackets;
    SingleLinkedList<int> closingBrackets;

public:
    explicit ExpressionParser(const std::string &expression)
            : stream(expression),
              openingBrackets(3, '[', '(', '{'),
              closingBrackets(3, ']', ')', '}') {}

    bool isValid() {
        char ch = this->stream.seek();
        while (ch != '\0') {
            int closingBracketIndex = closingBrackets.indexOf(ch);
            int openingBracketIndex = openingBrackets.indexOf(ch);

            if (openingBracketIndex > -1) {
                stack.push(ch);
            } else if (closingBracketIndex > -1) {
                char x = stack.pop();
                if (x != openingBrackets.get(closingBracketIndex)) {
                    this->stream.printError("Error: brackets mismatch");
                    return false;
                }
            }
            ch = this->stream.seek();
        }

        if (this->stack.size() > 0) {
            std::cout << this->stream.p;
            return false;
        }

        return true;
    }
};

int main() {
    ExpressionParser parser("1+(3/4([)])");
    parser.isValid();
    return 0;
};