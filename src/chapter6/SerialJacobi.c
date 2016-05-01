/* Sequential Jacobi Relaxation program in C* language */

#define n 32 /* Size of the array*/
#define numiter 20 /*Number of iterations*/
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

    for(k=0;k<=n+1;k++) {
        
    }

    /**/

}
