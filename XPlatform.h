/**
 * Provides cross platform alternatives of some conio.h functions
 * Adopted from https://github.com/kozlek/xplatform
 */

#ifndef XPLATFORM_H
#define XPLATFORM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

#if defined (_WIN32) || defined (_WIN64)
#define WINDOWS

#include <windows.h>
#include <conio.h>

#elif defined (__APPLE__) || defined (__MACH__) || defined (__unix__)

#define UNIX

#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <fcntl.h>

#endif

#if defined WINDOWS

#define COLOR_BLACK 0
#define COLOR_RED 12
#define COLOR_GREEN 2
#define COLOR_JAUNE 14
#define COLOR_BLUE 9
#define COLOR_MAGENTA 13
#define COLOR_CYAN 11
#define COLOR_WHITE 15

#elif defined UNIX

#define COLOR_BLACK 30
#define COLOR_RED 31
#define COLOR_GREEN 32
#define COLOR_JAUNE 33
#define COLOR_BLUE 34
#define COLOR_MAGENTA 35
#define COLOR_CYAN 36
#define COLOR_WHITE 37

#endif

void gotoxy(int x, int y);

int kbhit();

#ifdef __cplusplus
}
#endif

#endif /* XPLATFORM_H */