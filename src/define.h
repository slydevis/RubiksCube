#ifndef __DEFINE_H__

#include <SDL/SDL.h>

#define color(param) printf("\033[%sm", param)

#define PRINT_COLOR_BLACK "30"
#define PRINT_COLOR_RED "31"
#define PRINT_COLOR_GREEN "32"
#define PRINT_COLOR_YELLOW "33"
#define PRINT_COLOR_BLUE "34"
#define PRINT_COLOR_WHITE "37"

#define COLOR_NONE 0
#define COLOR_RED 1
#define COLOR_BLUE 2
#define COLOR_YELLOW 3
#define COLOR_WHITE 4
#define COLOR_GREEN 5
#define COLOR_ORANGE 6

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

#endif /* __DEFINE_H__ */
