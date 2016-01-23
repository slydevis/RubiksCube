#ifndef __TEST_H__

#include "../define.h"

void executeTest();
void testCube(void (*f)(miniCube cube[6][N][N]), char* fileInitPath, char* fileResultPath);
void test(int (*f)(), void (*init)(), int result);

#endif /* __TEST_H__ */
