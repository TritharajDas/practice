#include <stdio.h>

void multiplyMatrices(int row1, int col1, int A[row1][col1], int row2, int col2, int B[row2][col2], int result[row1][col2]) {
    // Initializing the result matrix to 0
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
        }
    }

    // Performing matrix multiplication
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void printMatrix(int row, int col, int matrix[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void takeInput(int row, int col, int matrix[row][col]) {
    printf("Enter elements of the matrix (%d x %d):\n", row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

int main() {
    int row1, col1, row2, col2;

    // Taking dimensions of Matrix A from the user
    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &row1, &col1);

    // Taking dimensions of Matrix B from the user
    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &row2, &col2);

    // Check if multiplication is possible
    if (col1 != row2) {
        printf("Error: Matrix multiplication not possible, columns of A must equal rows of B.\n");
        return 1;
    }

    // Declaring the matrices
    int A[row1][col1], B[row2][col2], result[row1][col2];

    // Taking input for Matrix A
    takeInput(row1, col1, A);

    // Taking input for Matrix B
    takeInput(row2, col2, B);

    // Multiplying A and B
    multiplyMatrices(row1, col1, A, row2, col2, B, result);

    // Printing the result
    printf("Resultant Matrix:\n");
    printMatrix(row1, col2, result);

    return 0;
}
