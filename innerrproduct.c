
#include <stdio.h>
#include <stdlib.h>
#include <cblas.h> 
 // For BLAS functions
#include <time.h>
int main(int argc, char *argv[]) {
    clock_t start, end;
    double time_taken;
    
    // Check if the correct number of arguments is provided
    if (argc != 3) {
        printf("Usage: %s <length of vectors n> <method (1 for loop, 2 for BLAS)>\n", argv[0]);
        return 1;
    }

    // Parse the command-line arguments
    int n = atoi(argv[1]); // Length of the vectors
    int lib = atoi(argv[2]); // Method (1 for loop, 2 for BLAS)

    // Validate the input length
    if (n <= 0) {
        printf("Error: n must be a positive integer.\n");
        return 1;
    }

    // Allocate memory for the vectors
    double *x = malloc(sizeof(double) * n);
    double *y = malloc(sizeof(double) * n);
    if (x == NULL || y == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize vectors x and y based on the formulas
    for (int i = 0; i < n; i++) {
        x[i] = (i % 2 == 0) ? 1.0 : -1.0;  // x[i] = (-1)^i
        y[i] = (i % 2 == 0) ? -1.0 : 1.0;  // y[i] = (-1)^(i+1)
    }

    // Start the clock to measure time
    start = clock();

    double dotprod = 0.0;

    // Compute the dot product
    if (lib == 1) {
        // Manual loop version (no BLAS)
        for (int i = 0; i < n; i++) {
            dotprod += (x[i] * y[i]);
        }
    } else if (lib == 2) {
        // BLAS library version
        dotprod = cblas_ddot(n, x, 1, y, 1);
    } else {
        // Invalid method selection
        printf("Invalid method selection. Use 1 for loop or 2 for BLAS.\n");
        free(x);
        free(y);
        return 1;
    }

    // Stop the clock after the computation
    end = clock();

    // Calculate time taken for the computation
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Output the result
    printf("Dot product method: %s\n", lib == 1 ? "loop" : "library");
    printf("Dot product result: %lf\n", dotprod);
    printf("This task took %f seconds to execute\n", time_taken);

    // Free allocated memory
    free(x);
    free(y);

    return 0;
}




























