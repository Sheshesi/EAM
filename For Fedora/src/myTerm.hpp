#pragma once
#include <cstdio>
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#define ERROR_CODE -1
#define SUCCESS_CODE 0

enum colors {
    DEFAULT,
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    LIGHT_GRAY,
    DARK_GRAY,
    LIGHT_RED,
    LIGHT_GREEN,
    LIGHT_YELLOW,
    LIGHT_BLUE,
    LIGHT_MAGENTA,
    LIGHT_CYAN,
    WHITE
};

int mt_getscreensize(int& rows, int& cols) {
    struct winsize w {};
    if (!ioctl(STDOUT_FILENO, TIOCGWINSZ, &w)) {
        rows = w.ws_row;
        cols = w.ws_col;
        return SUCCESS_CODE;
    }
    else
        return ERROR_CODE;
}

int mt_gotoXY(int x, int y) {
    int rows, cols;
    mt_getscreensize(rows, cols);
    if (((x >= 0) && (y >= 0)) || ((x <= rows)) && (y <= cols)) {
        printf("\E[%d;%dH", y, x);
        return SUCCESS_CODE;
    }
    else {
        printf("\E[%d;%dH", rows, cols);
        return ERROR_CODE;
    }
}

int mt_setfgcolor(colors color) {
    switch (color) {
    case DEFAULT: {
        printf("\E[39m");
        break;
    }
    case BLACK: {
        printf("\E[30m");
        break;
    }
    case RED: {
        printf("\E[31m");
        break;
    }
    case GREEN: {
        printf("\E[32m");
        break;
    }
    case YELLOW: {
        printf("\E[33m");
        break;
    }
    case BLUE: {
        printf("\E[34m");
        break;
    }
    case MAGENTA: {
        printf("\E[35m");
        break;
    }
    case CYAN: {
        printf("\E[36m");
        break;
    }
    case LIGHT_GRAY: {
        printf("\E[37m");
        break;
    }
    case DARK_GRAY: {
        printf("\E[90m");
        break;
    }
    case LIGHT_RED: {
        printf("\E[91m");
        break;
    }
    case LIGHT_GREEN: {
        printf("\E[92m");
        break;
    }
    case LIGHT_YELLOW: {
        printf("\E[93m");
        break;
    }
    case LIGHT_BLUE: {
        printf("\E[94m");
        break;
    }
    case LIGHT_MAGENTA: {
        printf("\E[95m");
        break;
    }
    case LIGHT_CYAN: {
        printf("\E[96m");
        break;
    }
    case WHITE: {
        printf("\E[97m");
        break;
    }
    default:
        return ERROR_CODE;
    }
    return SUCCESS_CODE;
}

int mt_setbgcolor(colors color) {
    switch (color) {
    case DEFAULT: {
        printf("\E[49m");
        break;
    }
    case BLACK: {
        printf("\E[40m");
        break;
    }
    case RED: {
        printf("\E[41m");
        break;
    }
    case GREEN: {
        printf("\E[42m");
        break;
    }
    case YELLOW: {
        printf("\E[43m");
        break;
    }
    case BLUE: {
        printf("\E[44m");
        break;
    }
    case MAGENTA: {
        printf("\E[45m");
        break;
    }
    case CYAN: {
        printf("\E[46m");
        break;
    }
    case LIGHT_GRAY: {
        printf("\E[47m");
        break;
    }
    case DARK_GRAY: {
        printf("\E[100m");
        break;
    }
    case LIGHT_RED: {
        printf("\E[101m");
        break;
    }
    case LIGHT_GREEN: {
        printf("\E[102m");
        break;
    }
    case LIGHT_YELLOW: {
        printf("\E[103m");
        break;
    }
    case LIGHT_BLUE: {
        printf("\E[104m");
        break;
    }
    case LIGHT_MAGENTA: {
        printf("\E[105m");
        break;
    }
    case LIGHT_CYAN: {
        printf("\E[106m");
        break;
    }
    case WHITE: {
        printf("\E[107m");
        break;
    }
    default:
        return ERROR_CODE;
    }
    return SUCCESS_CODE;
}

int mt_clrscr() {
    mt_setbgcolor(DEFAULT);
    mt_setfgcolor(DEFAULT);
    printf("\E[H\E[J");
    return 1;
}