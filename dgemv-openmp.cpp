#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

const char* dgemv_desc = "OpenMP dgemv.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */

void my_dgemv(int n, double* A, double* x, double* y) {

      #pragma omp parallel for private(i, k) shared (A, x, y)


      // int nthreads = omp_get_num_threads();
      // int thread_id = omp_get_thread_num();
      // printf("Hello world: thread %d of %d checking in. \n", thread_id, nthreads);

      omp_set_num_threads(omp_get_num_procs());
      //Then add our MVM
      for (int i = 0; i < n; i++){
          for(int k = 0; k < n; k++){
            //
           //Row major order:
           //prod[i][j] += A[i][k] * B[k][j]
           //Column major order:
           //prod[i][j] += A[k][j] * B[i][k]
           y[i] = y[i] + A[i*n + k] * x[k];
          }
      }


   // insert your dgemv code here. you may need to create additional parallel regions,
   // and you may want to comment out the above parallel code block that prints out
   // nthreads and thread_id so as to not taint your timings

}
