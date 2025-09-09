#include <stdio.h>

int main() {
    int a, b, c, d; // Matrix A
    int e, f, g, h; // Matrix B
    int M1, M2, M3, M4, M5, M6, M7;
    int C11, C12, C21, C22;

    printf("Enter elements of 2x2 Matrix A:\n");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    printf("Enter elements of 2x2 Matrix B:\n");
    scanf("%d %d %d %d", &e, &f, &g, &h);

    // Strassen's 7 multiplications
    M1 = (a + d) * (e + h);
    M2 = (c + d) * e;
    M3 = a * (f - h);
    M4 = d * (g - e);
    M5 = (a + b) * h;
    M6 = (c - a) * (e + f);
    M7 = (b - d) * (g + h);

    // Result matrix C
    C11 = M1 + M4 - M5 + M7;
    C12 = M3 + M5;
    C21 = M2 + M4;
    C22 = M1 - M2 + M3 + M6;

    printf("\nResultant Matrix C (A x B):\n");
    printf("%d %d\n", C11, C12);
    printf("%d %d\n", C21, C22);

    return 0;
}
