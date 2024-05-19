#include <unistd.h>
#include <stdio.h>
#include "../data_structures/matrix/matrix.h"

matrix readMatrixFromStream(FILE *fp, int n, int *res)
{
    matrix matrix = getMemMatrix(n, n);

    int x, count;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            count = fscanf(fp, "%d", &x);

            if (count == 0)
            {
                *res = 0;
                return matrix;
            }
            matrix.values[i][j] = x;
        }
    }
    *res = 1;
    return matrix;
}

void rowsToColumnsInMatrix(char *filePath)
{
    FILE *fp = fopen(filePath, "r");

    if (fp == NULL)
    {
        fprintf(stderr, "file cannot be opened");
        exit(1);
    }

    int n, res;
    fscanf(fp, "%d", &n);

    matrix matrix = readMatrixFromStream(fp, n, &res);

    fclose(fp);

    FILE *fw = fopen(filePath, "w+");

    if (fw == NULL)
    {
        fprintf(stderr, "file cannot be opened");
        exit(1);
    }

    fprintf(fp, "%d\n", n);
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            fprintf(fw, "%d ", matrix.values[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fw);
    freeMemMatrix(&matrix);
}

size_t readFileToBuff(char *filePath, char *buff, size_t buffSize) {
    FILE *f = fopen(filePath, "r");
    size_t size = fread(buff, sizeof(char), buffSize, f);
    fclose(f);
    buff[size] = '\0';

    return size;
}