/* Parallel Jacobi Relaxation program in C* language */

#define n 32 /* Size of the array*/
#define numiter 1 /*Number of iterations*/
float A[n+2][n+2], B[n+2][n+2];
int i,j,k;

main() {
    /* Initialize array values */
    for(i=0;i <= n+1;i++) {
        for(j=0;j<=n+1;j++) {
            cin >> A[i][j];
        }
    }

    B = A;
    /* Perform only one iteration */
    for(k=1;k<= numiter;k++) {
        /* 1. In the 2X2 matrix create a new process for each row */
        forall i=1 to n do {
          int j;
          for(j=1;j<=n;j++) {
            B[i][j] = (A[i-1][j] + A[i+1][j] + A[i][j-1] + A[i][j+1])/4;
          }
        }

        /*
         * 2. Copy new values back to A row by row.
         * Why it should be row by row instead of A = B ???
         */
        forall i=1 to n do
          A[i] = B[i];
    }

}
