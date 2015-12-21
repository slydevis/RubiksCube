#ifndef __DEFINE_H__
#define __DEFINE_H__

#include <SDL/SDL.h>

#define color(param) printf("\033[%sm", param)
#define clearScreen() printf("\033[H\033[2J");

#define PRINT_COLOR_BLACK "30"
#define PRINT_COLOR_RED "31"
#define PRINT_COLOR_GREEN "32"
#define PRINT_COLOR_YELLOW "33"
#define PRINT_COLOR_BLUE "34"
#define PRINT_COLOR_WHITE "37"

#define COLOR_NONE 10
#define COLOR_RED 11
#define COLOR_BLUE 12
#define COLOR_YELLOW 13
#define COLOR_WHITE 14
#define COLOR_GREEN 15
#define COLOR_ORANGE 16

#define N 3

#define SCREEN_HEIGHT 480
#define SCREEN_WIDTH 640
#define FACE_SIZE 30

typedef struct {
	SDL_Surface* screen;
	int color;
} face;

#define SIDE_LEFT 0
#define SIDE_FRONT 1
#define SIDE_UPPER 2
#define SIDE_BOTTOM 3
#define SIDE_RIGHT 4
#define SIDE_BEHIND 5

#define EXTENSION_JSON ".json"

#define JSON_LEFT "LEFT"
#define JSON_RIGHT "RIGHT"
#define JSON_FRONT "FRONT"
#define JSON_UPPER "UPPER"
#define JSON_BOTTOM "BOTTOM"
#define JSON_BEHIND "BEHIND"
#define JSON_RED "RED"
#define JSON_BLUE "BLUE"
#define JSON_YELLOW "YELLOW"
#define JSON_WHITE "WHITE"
#define JSON_GREEN "GREEN"
#define JSON_ORANGE "ORANGE"

#define OPEN_READ "r"
#define OPEN_WRITE "w"
#define OPEN_APPEND "a"
#define OPEN_ALL "r+"

#endif /* __DEFINE_H__ */
