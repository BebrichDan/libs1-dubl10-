#ifndef LAB_MATRIX_H
#define LAB_MATRIX_H

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;

matrix getMemMatrix(int nRows, int nCols);

void freeMemMatrix(matrix *m);


#endif //LAB_MATRIX_H