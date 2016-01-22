#ifndef __FILE_H__

#include "define.h"

FILE* openFile(char* path, char* mode);
void closeFile(FILE* file);
char* toUpper(char* str);
int translateWord(char* word);
void readJSON(char * path, int tmp[6][N][N]);
char* getExtension(char* path);
void saveCube(int cube[6][N][N]);

#endif /* __FILE_H__ */
