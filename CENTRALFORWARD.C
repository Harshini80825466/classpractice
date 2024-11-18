#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
  void diff_forward(double* u, int N, double dx, double* du)

  Computes a forward finite difference approximation for du/dx

  Inputs: 
  u: pointer for input array
  N: length of the array
  dx: the space step size
  du: pointer to output array

  Outputs: 
  du: contains the forward finite difference approximation
*/
void diff_forward(double* u, int N, double dx, double* du) {
    int i;
    // Forward difference for the first point
    du[0] = (u[1] - u[0]) / dx;
    
    // Forward difference for the middle points
    for (i = 1; i < N; ++i) {
        du[i] = (u[i+1] - u[i]) / dx;
    }
}

/*
  void diff_central(double* u, int N, double dx, double* du)

  Computes a central finite difference approximation for du/dx

  Inputs: 
  u: pointer for input array
  N: length of the array
  dx: the space step size
  du: pointer to output array

  Outputs: 
  du: contains the central finite difference approximation
*/
void diff_central(double* u, int N, double dx, double* du) {
    int i;
    // Central difference for the first and last points can be done using forward/backward differences
    du[0] = (u[1] - u[0]) / dx;  // Forward difference at the start
    du[N-1] = (u[N-1] - u[N-2]) / dx;  // Backward difference at the end

    // Central difference for the middle points
    for (i = 1; i < N-1; ++i) {
        du[i] = (u[i+1] - u[i-1]) / (2 * dx);
    }
}

/*
  void init(double* u, int N, double dx)

  Initializes the data array with the sin function

  Inputs: 
  u: pointer to array where values will be stored
  N: length of the array
  dx: the space step size

  Outputs: 
  u: contains data for a sin function
*/
void init(double* u, int N, double dx) {
    int i;
    for (i = 0; i < N+1; ++i)  // N+1 because we need N+1 points from 0 to N inclusive
        u[i] = sin(i * dx);
}

/*
  int main(int argc, char* argv[])

  Function tests the forward and central difference methods

  Inputs: argc should be 2
  argv[1] is the integer length of the data array
  
  Outputs: Prints the approximation and error for both methods
*/
int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <N>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);

    double* u = (double*)malloc((N+1) * sizeof(double));  // N+1 points
    double* du_forward = (double*)malloc(N * sizeof(double));  // N points for forward difference
    double* du_central = (double*)malloc(N * sizeof(double));  // N points for central difference
    double dx = M_PI / N;

    // Initialize the sin function values
    init(u, N, dx);  

    // Compute forward and central differences
    diff_forward(u, N, dx, du_forward);
    diff_central(u, N, dx, du_central);

    // Print results
    printf("\nIndex  x_value   Forward_diff  Central_diff  Exact_derivative  Forward_error  Central_error\n");
    printf("---------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < N; ++i) {
        double x = i * dx;
        double exact_derivative = cos(x);  // Exact derivative of sin(x) is cos(x)
        double forward_error = du_forward[i] - exact_derivative;
        double central_error = du_central[i] - exact_derivative;
        
        printf("%d   %.6f   %.6f   %.6f   %.6f   %.6f   %.6f\n", 
               i, x, du_forward[i], du_central[i], exact_derivative, forward_error, central_error);
    }

    free(u);
    free(du_forward);
    free(du_central);

    return 0;
}
*************************************************************
$ gcc -o derivative_approx derivative_approx.c -lm
$ ./derivative_approx 10
Index  x_value   Forward_diff  Central_diff  Exact_derivative  Forward_error  Central_error
---------------------------------------------------------------------------------------------
0   0.000000   0.309017   0.309017   1.000000   -0.690983   -0.690983
1   0.314159   0.278634   0.278634   0.951057   -0.672423   -0.672423
2   0.628319   0.222518   0.222518   0.809017   -0.586499   -0.586499
3   0.942478   0.160634   0.160634   0.587785   -0.427151   -0.427151
4   1.256637   0.104080   0.104080   0.309017   -0.204938   -0.204938
5   1.570796   0.047350   0.047350   0.000000   0.047350   0.047350
6   1.884956   -0.014902   -0.014902   -0.309017   0.294115   0.294115
7   2.199115   -0.074370   -0.074370   -0.587785   0.513415   0.513415
8   2.513274   -0.136254   -0.136254   -

