#include <stdio.h>
#include <stdlib.h>
#include <cblas.h>  // For BLAS functions

int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc != 2) {
        printf("Usage: %s <length of vectors n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);  // Length of the vectors

    if (n <= 0) {
        printf("Error: n must be a positive integer.\n");
        return 1;
    }

    // Allocate memory for the vectors x and y
    double *x = (double *)malloc(n * sizeof(double));
    double *y = (double *)malloc(n * sizeof(double));

    if (!x || !y) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize vectors x and y based on the formulas
    for (int i = 0; i < n; i++) {
        x[i] = (i % 2 == 0) ? 1.0 : -1.0;  // x[i] = (-1)^i
        y[i] = (i % 2 == 0) ? -1.0 : 1.0;  // y[i] = (-1)^(i+1)
    }

    // Compute the dot product using the BLAS ddot function
    double result = cblas_ddot(n, x, 1, y, 1);

    // Print the result
    printf("Dot product: %f\n", result);

    // Free memory
    free(x);
    free(y);

    return 0;
}
