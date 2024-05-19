#ifndef LAB_FILE_IO_H
#define LAB_FILE_IO_H

#include "../data_structures/matrix/matrix.h"
#include <stdio.h>

#define MAX_LINE_SIZE 1024
char fileReadBuffer[MAX_LINE_SIZE];

matrix readMatrixFromStream(FILE *fp, int n, int *res);

void rowsToColumnsInMatrix(char *filePath);

size_t readFileToBuff(char *filePath, char *buff, size_t buffSize);


#endif //LAB_FILE_IO_H