#include <ctime>
#include <cstdlib>
#include <malloc.h>
#include <iostream>

#include "XPlatform.h"

#define terminalWidth 78
#define terminalHeight 15

using namespace std;

void delay(int interval) {
    clock_t start_time = clock();
    while (clock() < start_time + interval * 1000);
}

int random(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

template<typename T>
int indexOf(T el, T *arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == el) return i;
    }
    return -1;
}

template<typename T>
int removeRight(T el, T *arr, int size) {
    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] == el)  {
            arr[i] = 32;
            return i;
        };
    }
    return -1;
}

class TypingTutor {
private:
    int lives{};
    int *characters;
    int interval;
    
    void generateLine() {
        int charsPerLine = random(2, 5);
        for (int i = 0; i < charsPerLine; i++) {
            int pos;
            do {
                pos = random(0, terminalWidth - 1);
            } while (this->characters[pos] != 32 || this->characters[pos - 1] != 32 || this->characters[pos + 1] != 32);
            this->characters[pos] = random('a', 'z');
        }
    }

    void scroll() {
        for (int i = terminalHeight - 1; i > 0; i--) {
            for (int j = 0; j < terminalWidth; j++) {
                this->characters[i * terminalWidth + j] = this->characters[(i - 1) * terminalWidth + j];
                this->characters[(i - 1) * terminalWidth + j] = 32;
            }
        }
    }

    void draw() {
        gotoxy(0, 0);
        cout << "╔";
        for (int j = 0; j < terminalWidth; j++) {
            cout << "═";
        }
        cout << "╗\n";
        for (int i = 0; i < terminalHeight; i++) {
            cout << "║";
            for (int j = 0; j < terminalWidth; j++) {
                cout << (char) this->characters[i * terminalWidth + j];
            }
            cout << "║" << endl;
        }
        cout << "╚";
        for (int j = 0; j < terminalWidth; j++) {
            cout << "═";
        }
        cout << "╝\n";
    }

public:

    void setup() {
        srand(time(nullptr));
        this->lives = 5;
        this->characters = (int *) malloc(sizeof(int) * terminalWidth * terminalHeight);
        this->interval = 1000;

        for (int i = 0; i < terminalHeight; i++) {
            for (int j = 0; j < terminalWidth; j++) {
                this->characters[i * terminalWidth + j] = 32;
            }
        }
    }

    void loop() {
        this->scroll();
        this->generateLine();
        this->draw();

        clock_t start_time = clock();
        while (clock() < start_time + 1000 * this->interval) {
            fflush(stdin);
            int k = kbhit();
            if ((k >= 'a' && k <= 'z') || (k >= '0' && k <= '9')) {
                removeRight<int>(k, this->characters, terminalHeight * terminalWidth);
                this->draw();
            }
        }

        loop();
    }
};

int main() {
    TypingTutor game{};
    game.setup();
    game.loop();
}
