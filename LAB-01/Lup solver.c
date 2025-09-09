#include <stdio.h>
#include <math.h>

#define MAX 10   // max matrix size

void LUPDecompose(double A[MAX][MAX], int P[MAX], int n) {
    for (int i = 0; i < n; i++) P[i] = i;
    for (int k = 0; k < n; k++) {
        int pivot = k;
        double max = fabs(A[k][k]);
        for (int i = k+1; i < n; i++) {
            if (fabs(A[i][k]) > max) {
                max = fabs(A[i][k]);
                pivot = i;
            }
        }
        if (pivot != k) { // swap rows in A
            for (int j = 0; j < n; j++) {
                double temp = A[k][j];
                A[k][j] = A[pivot][j];
                A[pivot][j] = temp;
            }
            int t = P[k]; P[k] = P[pivot]; P[pivot] = t;
        }
        for (int i = k+1; i < n; i++) {
            A[i][k] /= A[k][k];
            for (int j = k+1; j < n; j++)
                A[i][j] -= A[i][k] * A[k][j];
        }
    }
}

void solve(double A[MAX][MAX], double b[MAX], int P[MAX], double x[MAX], int n) {
    double y[MAX];
    for (int i = 0; i < n; i++) { // forward
        y[i] = b[P[i]];
        for (int j = 0; j < i; j++)
            y[i] -= A[i][j] * y[j];
    }
    for (int i = n-1; i >= 0; i--) { // backward
        x[i] = y[i];
        for (int j = i+1; j < n; j++)
            x[i] -= A[i][j] * x[j];
        x[i] /= A[i][i];
    }
}

int main() {
    int n;
    double A[MAX][MAX], b[MAX], x[MAX];
    int P[MAX];

    printf("Enter size of matrix: ");
    scanf("%d", &n);

    printf("Enter matrix A (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &A[i][j]);

    printf("Enter vector b (%d values):\n", n);
    for (int i = 0; i < n; i++) scanf("%lf", &b[i]);

    LUPDecompose(A, P, n);
    solve(A, b, P, x, n);

    printf("Solution x:\n");
    for (int i = 0; i < n; i++)
        printf("x[%d] = %.2f\n", i+1, x[i]);

    return 0;
}
