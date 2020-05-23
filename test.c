#include "fftautocorr.h"
#include <fftw3.h>
#include <time.h>
#include <math.h>

#define ERR 1E-10

int main(int argc, char *argv[]) {
    fftw_plan p;
    int L = 20;
    int N = 1 << L;
    double *in = fftw_malloc(N * sizeof(double));
    fftw_complex *out = fftw_malloc((N/2+1) * sizeof(fftw_complex));
    clock_t t0 = clock(), t;
    p = fftw_plan_dft_r2c_1d(N, in, out, FFTW_ESTIMATE);
    t = clock();
    printf("FFTW planning time: %g s\n", (t-t0)/(double)CLOCKS_PER_SEC);

    printf("Testing rfft_forward_p2:\n");
    for(int i=0; i<N; i++) {
        in[i] = (double)rand() / (double)(RAND_MAX);
        /* printf("%f\n", in[i]); */
    }
    t0 = clock();
    fftw_execute(p);
    t = clock();
    printf("FFTW executing: %g s\n", (t-t0)/(double)CLOCKS_PER_SEC);
    t0 = clock();
    rfft_forward(in, L);
    t = clock();
    printf("rfft_forward executing: %g s\n", (t-t0)/(double)CLOCKS_PER_SEC);

    if(fabs(out[0][0] - in[0]) > ERR || fabs(out[0][1]) > ERR) {
        printf("Test failed 0, diff=%g, %g\n", 
                out[0][0] - in[0], out[0][1]);
        return 1;
    }
    N = N/2;
    for(int i=1; i < N; i++) {
        if(fabs(out[i][0] - in[2*i]) > ERR || 
            fabs(out[i][1] - in[2*i+1]) > ERR) {
            printf("Test failed %d, diff = %g, %g\n", i,
                   out[i][0] - in[2*i], out[i][1] -in[2*i+1]);
            return 1;
        }
    }
    if(fabs(out[N][0] - in[1]) > ERR || fabs(out[N][1]) > ERR) {
        printf("Test failed N/2, diff = %g, %g\n", 
               out[N][0] - in[1], out[N][1]);
        return 1;
    }
    printf("Succeed.\n");

    fftw_free(in);
    fftw_free(out);
    return 0;
}