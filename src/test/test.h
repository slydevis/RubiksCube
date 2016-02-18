#ifndef __TEST_H__

#include "../define.h"

void test(int (*f)(), void (*init)(), int result);
void testCube(void (*f)(miniCube cube[6][N][N]), char* fileInitPath, char* fileResultPath);
void executeTest();

#endif /* __TEST_H__ */
