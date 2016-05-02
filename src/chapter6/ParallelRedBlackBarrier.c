/* Parallel Red Black Relaxation with Barrier program in C* language */

#define n 32 /* Size of the array*/
#define numiter 1000 /*Number of iterations*/

float A[n+2][n+2], B[n+2][n+2];
int i,j,k;
int count;

spinlock Arrival, Departure;

/* Global Barrier */
void Barrier() {

  /* Arrival Phase - Count processes as they arrive */
  Lock(Arrival);
    count = count + 1;
  if(count < n)
    Unlock(Arrival);
  else
    Unlock(Departure);

  /* Departure Phase - Count processes as they leave */
  Lock(Departure);
    count = count - 1;
  if(count > 0)
    Unlock(Departure); /* continue Departure Phase */
  else
    Unlock(Arrival);  /* end of Depature phase */
  }


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
            /*   ------- Black -------*/
            for(j=1;j<=n;j+2) {
              B[i][j] = (A[i-1][j] + A[i+1][j] + A[i][j-1] + A[i][j+1])/4;
            }
            /*
             * Copy new values back to A row by row.
             * Why it should be row by row instead of A = B ???
             */
            Barrier();
              A[i] = B[i];
            Barrier();

            /* -------- Red ---------*/
            for(j=1;j<=n;j+2) {
              B[i][j] = (A[i-1][j] + A[i+1][j] + A[i][j-1] + A[i][j+1])/4;
            }
            /*
             *  Copy new values back to A row by row.
             * Why it should be row by row instead of A = B ???
             */
            Barrier();
              A[i] = B[i];
            Barrier();

          }

      }

  }

  /*
   * Results:
   * Sequential computation time : 8.1856786
   * Parallel computation time : 5.1435600
   * Speed up:  1.94857s
  */
