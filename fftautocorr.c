/* 
 * This file is part of fftautocorr
 * Licensed under a 3-clause BSD style licnese
 */

/*
 * Main implementation file.
 */

#include <math.h>
#include "fftautocorr.h"

/* the result of rfft is stored as:
 * x[k] = c[2*k] + 1j*c[2*k+1] if 1 <= k < N/2 
 * x[k] = conj(x[N-k]) if k > N/2 
 * x[0] = c[0]; x[N/2] = c[1] */
static void rfft_forward_p2(double * restrict c, int log2len,
                            double * restrict pool) {
    /* len of c is 1 << log2len */
    const size_t halflen = 1 << (log2len - 1);
    size_t t;
    double *ec;
    double *oc;
    if(log2len == 0) {
        return;
    }
    if(log2len == 1) {
        double tmp = c[0];
        c[0] = c[0] + c[1];
        c[1] = tmp - c[1];
        return;
    }
    /* halflen >= 2, len(c) >= 4 */
    ec = pool;
    oc = pool + halflen;
    for(t = 0; t < halflen; t++) {
        ec[t] = c[2*t];
        oc[t] = c[2*t+1];
    }
    rfft_forward_p2(ec, log2len - 1, c);
    rfft_forward_p2(oc, log2len - 1, c+halflen);
    c[0] = ec[0] + oc[0];
    c[1] = ec[0] - oc[0];
    for(t = 2; t < halflen; t += 2) {
        /* k = t/2 */
        /* x[k] = e[k] + exp(-2*pi*i*k/N) * o[k] */
        c[t] = ec[t] + oc[t] * cos(M_PI * t / halflen / 2)
                + oc[t+1] * sin(M_PI * t / halflen / 2);
        c[t+1] = ec[t+1] + oc[t+1] * cos(M_PI * t / halflen / 2)
                  - oc[t] * sin(M_PI * t / halflen / 2);
        /* x[N/2-k] = conj(x[N/2+k])
         *     conj(e[k] - exp(-2*pi*i*k/N) * o[k]) */
        c[2*halflen-t] = ec[t] - oc[t] * cos(M_PI * t / halflen / 2)
                          - oc[t+1] * sin(M_PI * t / halflen / 2);
        c[2*halflen-t+1] = -ec[t+1] + oc[t+1] * cos(M_PI * t / halflen / 2)
                            - oc[t] * sin(M_PI * t / halflen / 2);
    }
    c[halflen] = ec[1];
    c[halflen+1] = -oc[1];
}

int rfft_forward(double * restrict c, int log2len) {
    double * pool = (double *) malloc(sizeof(double) * (1 << log2len));
    if(pool == NULL) {
        return -1;
    }
    rfft_forward_p2(c, log2len, pool);
    free(pool);
    return 0;
}

int fftautocorr(double *in, size_t len) {
    return 0;
}

