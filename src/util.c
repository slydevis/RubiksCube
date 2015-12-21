#include "util.h"
#include "define.h"

void printError(char* str) {
	color(PRINT_COLOR_RED);
	printf("Error : %s\n", str);
	color(PRINT_COLOR_WHITE);
	exit(EXIT_FAILURE);
}
