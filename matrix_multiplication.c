#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 100

int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
int rowA, colA, rowB, colB;

typedef struct {
    int row, col;
} MatrixIndex;

void *multiplyElement(void *arg) {
    MatrixIndex *index = (MatrixIndex *)arg;
    int sum = 0;
    for (int i = 0; i < colA; i++) {
        sum += A[index->row][i] * B[i][index->col];
    }
    C[index->row][index->col] = sum;
    free(arg);
    pthread_exit(NULL);
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter dimensions of Matrix A (rows cols): ");
    scanf("%d %d", &rowA, &colA);

    printf("Enter dimensions of Matrix B (rows cols): ");
    scanf("%d %d", &rowB, &colB);

    if (colA != rowB) {
        printf("Matrix multiplication not possible! Columns of A must match rows of B.\n");
        return 1;
    }

    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < rowA; i++)
        for (int j = 0; j < colA; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < rowB; i++)
        for (int j = 0; j < colB; j++)
            scanf("%d", &B[i][j]);

    pthread_t threads[MAX][MAX];

    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            MatrixIndex *data = (MatrixIndex *)malloc(sizeof(MatrixIndex));
            data->row = i;
            data->col = j;
            pthread_create(&threads[i][j], NULL, multiplyElement, (void *)data);
        }
    }

    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            pthread_join(threads[i][j], NULL);
        }
    }

    printf("Resultant Matrix C:\n");
    printMatrix(C, rowA, colB);

    return 0;
}