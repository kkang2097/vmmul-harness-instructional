const char* dgemv_desc = "Basic implementation of matrix-vector multiply.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */
void my_dgemv(int n, double* A, double* x, double* y) {
   // insert your code here: implementation of basic matrix multiply

   //Then add our triple for-loop
   for (int i = 0; i < n; i++){
       for(int k = 0; k < n; k++){
         //
        //Row major order:
        //prod[i][j] += A[i][k] * B[k][j]
        //Column major order:
        //prod[i][j] += A[k][j] * B[i][k]
        y[i] = y[i] + A[i*n + k] * x[i];
       }
   }


}
