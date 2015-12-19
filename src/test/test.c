#include "stdio.h"
#include "stdlib.h"
#include "stdarg.h"
#include "test.h"
#include "../define.h"

/* Launch test for a function without argument */
void test(int (*f)(), void (*init)(), int result) {
	int res;
	(*init)();
	res = (*f)();

	printf("Run test : ");
	if(res == 0) {
		color(PRINT_COLOR_GREEN);
		printf("OK\n");
		color(PRINT_COLOR_WHITE);
	}
	else {
		color(PRINT_COLOR_RED);
		printf("FAIL ! \n");
		color(PRINT_COLOR_WHITE);
		exit(EXIT_FAILURE);
	}
}

void executeTest() {
	printf("===> Test Unit : \n");
	printf("===> DONE\n");
}
