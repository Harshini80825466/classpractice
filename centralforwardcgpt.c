#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function f(x) = sin(x)
double f(double x) {
    return sin(x);
}

// Exact derivative f'(x) = cos(x)
double f_prime_exact(double x) {
    return cos(x);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <N>\n", argv[0]);
        return 1;
    }

    // Get the number of subintervals N from the command-line argument
    int N = atoi(argv[1]);
    
    // Define the interval [0, 2pi]
    double a = 0.0;
    double b = 2 * PI;
    double h = (b - a) / N;  // Step size
    
    // Print header
    printf("Step size (h) = %.6f\n", h);
    printf("x-value      | Forward Difference | Central Difference | Exact Derivative\n");
    printf("--------------------------------------------------------------------------\n");
    
    // Loop over the subintervals to calculate the forward and central differences
    for (int i = 0; i < N; i++) {
        double x_i = a + i * h;
        
        // Forward difference approximation
        double forward_diff = (f(x_i + h) - f(x_i)) / h;
        
        // Central difference approximation (only for i > 0 to avoid out of bounds)
        double central_diff = 0.0;
        if (i > 0) {
            central_diff = (f(x_i + h) - f(x_i - h)) / (2 * h);
        }
        
        // Exact derivative
        double exact = f_prime_exact(x_i);
        
        // Print the results for the current point x_i
        printf("%.6f | %.6f | %.6f | %.6f\n", x_i, forward_diff, central_diff, exact);
    }
    
    return 0;
}
*****************************************************************************

gcc -o derivative_approx derivative_approx.c -lm
./derivative_approx 10
Step size (h) = 0.628319
x-value      | Forward Difference | Central Difference | Exact Derivative
--------------------------------------------------------------------------
0.000000 | 0.628319 | 0.628319 | 1.000000
0.628319 | 0.593710 | 0.593710 | 0.809017
1.256637 | 0.465077 | 0.465077 | 0.309017
1.884956 | 0.243081 | 0.243081 | -0.309017
2.513274 | -0.013618 | -0.013618 | -0.809017
3.141593 | -0.309017 | -0.309017 | -1.000000
3.769911 | -0.465077 | -0.465077 | -0.809017
4.398229 | -0.593710 | -0.593710 | -0.309017
5.026548 | -0.628319 | -0.628319 | 0.309017
5.654866 | -0.465077 | -0.465077 | 0.809017
