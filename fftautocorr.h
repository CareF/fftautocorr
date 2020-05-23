/* 
 * This file is part of fftautocorr
 * Licensed under a 3-clause BSD style licnese
 */

#ifndef FFTAUTOCORR_H
#define FFTAUTOCORR_H

#include <stdlib.h>

int fftautocorr(double *in, size_t len);
int rfft_forward(double * c, int log2len);

#endif /* ifndef FFTAUTOCORR_H */
