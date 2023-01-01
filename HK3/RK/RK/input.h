#ifndef _INPUT_H
#define _INPUT_H

int input_matrix(int*** matrix, int* row, int* col, FILE* f);
void free_matrix(int** matrix, const int row);

#endif // !_INPUT_H
