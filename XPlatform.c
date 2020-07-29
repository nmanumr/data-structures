#include "XPlatform.h"

#ifdef WINDOWS

void gotoxy(int x, int y) {
    COORD Coord;
    Coord.X = x;
    Coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coord);
}

int kbhit() {
    return _kbhit();
}

#else

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y + 1, x + 1);
}

int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF)
    {
        return ch;
    }

    return 0;
}

#endif