/* 
 * This file is part of fftautocorr
 * Licensed under a 3-clause BSD style licnese
 */

#ifndef FFTAUTOCORR_H
#define FFTAUTOCORR_H

#include <stdlib.h>

struct autocorr_plan_i;
typedef struct autocorr_plan_i * autocorr_plan;
autocorr_plan make_autocorr_plan(size_t length);
void destroy_autocorr_plan(autocorr_plan plan);
size_t mem_len(autocorr_plan plan);
int autocorr(autocorr_plan plan, double c[]);

#endif /* ifndef FFTAUTOCORR_H */
