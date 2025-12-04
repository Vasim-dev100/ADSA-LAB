#include <stdio.h>
#include <math.h>

#define MAX 10

int main() {
    int n, P[MAX];
    double A[MAX][MAX], L[MAX][MAX] = {0}, U[MAX][MAX] = {0};

    printf("Enter size of matrix: ");
    scanf("%d", &n);

    printf("Enter matrix A (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &A[i][j]);

    for (int i = 0; i < n; i++) P[i] = i;

    // LUP decomposition
    for (int k = 0; k < n; k++) {
        int pivot = k;
        double max = fabs(A[k][k]);
        for (int i = k + 1; i < n; i++) {
            if (fabs(A[i][k]) > max) {
                max = fabs(A[i][k]);
                pivot = i;
            }
        }
        if (pivot != k) {
            for (int j = 0; j < n; j++) {
                double temp = A[k][j];
                A[k][j] = A[pivot][j];
                A[pivot][j] = temp;
            }
            int t = P[k]; P[k] = P[pivot]; P[pivot] = t;
        }
        for (int i = k + 1; i < n; i++) {
            A[i][k] /= A[k][k];
            for (int j = k + 1; j < n; j++)
                A[i][j] -= A[i][k] * A[k][j];
        }
    }

    // Extract L and U
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j) { L[i][j] = A[i][j]; U[i][j] = 0; }
            else if (i == j) { L[i][j] = 1; U[i][j] = A[i][j]; }
            else { L[i][j] = 0; U[i][j] = A[i][j]; }
        }
    }

    // Print results
    printf("\nL matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%6.2f ", L[i][j]);
        printf("\n");
    }

    printf("\nU matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%6.2f ", U[i][j]);
        printf("\n");
    }

    printf("\nP (permutation order):\n");
    for (int i = 0; i < n; i++) printf("%d ", P[i]);
    printf("\n");

    return 0;
}
