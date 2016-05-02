/* PROGRAM Jacobi Barrier */

#define n 32
#define numiter 1 /*Number of iterations*/
float A[n+2][n+2], B[n+2][n+2];
int i,j,k;
int count;

spinlock Arrival, Departure;

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
  count = 0; /* Initialize "count" and spinlocks */
  Unlock(Arrival);
  Lock(Departure);
}
