#include "util.h"
#include "define.h"

void printError(char* str) {
    color(PRINT_COLOR_RED);
    printf("Error : %s\n", str);
    color(PRINT_COLOR_WHITE);
    exit(EXIT_FAILURE);
}

int getFinalColorId(int id) {
    switch(id) {
        case SIDE_LEFT:
            return COLOR_GREEN;
        case SIDE_FRONT:
            return COLOR_ORANGE;
        case SIDE_UPPER:
            return COLOR_YELLOW;
        case SIDE_BOTTOM:
            return COLOR_WHITE;
        case SIDE_RIGHT:
            return COLOR_BLUE;
        case SIDE_BEHIND:
            return COLOR_RED;
        default:
            return COLOR_NONE;
    }
}
