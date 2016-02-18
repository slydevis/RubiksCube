#ifndef __DEFINE_H__
#define __DEFINE_H__

typedef struct face {
    int color;
    int finalPos;
} face;

typedef struct face* miniCube;

#define color(param) printf("\033[%sm", param);

/************************************
 *           Save status
 ************************************/

// If you want save rotation set this variable
#define SAVE_ROT 1
#define NOT_SAVE_ROT 0
int save;

/************************************
 *    Console color identifiers
 ************************************/

#define PRINT_COLOR_BLACK "30"
#define PRINT_COLOR_RED "31"
#define PRINT_COLOR_GREEN "32"
#define PRINT_COLOR_YELLOW "33"
#define PRINT_COLOR_BLUE "34"
#define PRINT_COLOR_WHITE "37"

/************************************
 *      Face color identifiers
 ************************************/

#define COLOR_NONE 10
#define COLOR_RED 11
#define COLOR_BLUE 12
#define COLOR_YELLOW 13
#define COLOR_WHITE 14
#define COLOR_GREEN 15
#define COLOR_ORANGE 16

/************************************
 *           Cube size
 ************************************/

#define N 3

/************************************
 *       Windows parameters
 ************************************/

#define SCREEN_HEIGHT 480
#define SCREEN_WIDTH 640
#define FACE_SIZE 30

/************************************
 *      Rotation direction id
 ************************************/

#define DIRECTION_NORMAL 0
#define DIRECTION_REVERSE 1

/************************************
 *         Side identifier
 ************************************/

#define SIDE_LEFT 0
#define SIDE_FRONT 1
#define SIDE_UPPER 2
#define SIDE_BOTTOM 3
#define SIDE_RIGHT 4
#define SIDE_BEHIND 5

/************************************
 *        Extension string
 ************************************/

#define EXTENSION_JSON ".json"
#define EXTENSION_ROT ".rot"

/************************************
 *   JSON translation vocabulary
 ************************************/

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
#define JSON_NONE "UNDEFINED"

/************************************
 *        Open file option
 ************************************/

#define OPEN_READ "r"
#define OPEN_WRITE "w"
#define OPEN_APPEND "a"
#define OPEN_ALL "r+"

#define RAND_SIZE 99
#define MAX_BACKTRACK 99

#endif /* __DEFINE_H__ */
