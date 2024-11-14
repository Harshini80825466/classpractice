#include <stdio.h>
#include <stdlib.h>
#include <cblas.h> 
 // For BLAS functions
#include <time.h>



int main(int argc, char * argv[]) {
  clock_t start, end;
  double cpu_time_used;

  
  start = clock();
  int n = atoi(argv[1]);
    // Check if the number of arguments is correct
    if (argc != 2) {
        printf("Usage: %s <length of vectors n>\n", argv[0]);
        return 1;
    }

   // Length of the vectors

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

    double dotprod;
    
  
    for (int i = 0; i < n; i++) {
       dotprod += (x[i] * y[i]);
    }
  
 





  //
  printf("dot product without blas function %lf\n", dotprod);
  
   cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  // print the result
   printf("This task took %f seconds to execute \n", cpu_time_used);

    free(x);
    free(y);


  return 0.;
}

    
