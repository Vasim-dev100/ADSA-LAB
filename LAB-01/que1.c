#include <stdio.h>
#include <math.h>

#define NUM_FUNCS 12

typedef struct {
    char name[30];
    double value;
} FuncVal;

// Functions inline
double getValue(int id, double n) {
    switch(id) {
        case 0: return n * log2(n);
        case 1: return 12 * sqrt(n);
        case 2: return 1.0 / n;
        case 3: return pow(n, log2(n));      // n^(log2 n)
        case 4: return 100 * n * n + 6 * n;
        case 5: return pow(n, 0.51);
        case 6: return n * n - 324;
        case 7: return 50 * sqrt(n);
        case 8: return 2 * pow(n, 3);
        case 9: return pow(3, n);     
        case 11:return log2(n);
    }
    return 0;
}

char *names[NUM_FUNCS] = {
    "n*log2(n)",
    "12*sqrt(n)",
    "1/n",
    "n^(log2(n))",
    "100*n^2+6n",
    "n^0.51",
    "n^2-324",
    "50*sqrt(n)",
    "2*n^3",
    "3^n",
    "log2(n)"
};

void sort(FuncVal arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i].value > arr[j].value) {
                FuncVal temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    long Nlarge = 1024;   // Large n to compare
    FuncVal arr[NUM_FUNCS];

    // Fill array
    for(int i=0; i<NUM_FUNCS; i++) {
        arr[i].value = getValue(i, Nlarge);
        snprintf(arr[i].name, sizeof(arr[i].name), "%s", names[i]);
    }

    // Sort by value
    sort(arr, NUM_FUNCS);

    // Print in order
    printf("Functions in increasing order of growth (n = %ld):\n", Nlarge);
    for(int i=0; i<NUM_FUNCS; i++) {
        printf("%d. %s\n", i+1, arr[i].name);
    }

    return 0;
}
