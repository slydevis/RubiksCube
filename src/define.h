#ifndef __DEFINE_H__

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

#endif /* __DEFINE_H__ */
