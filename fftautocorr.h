/* 
 *  This file is part of fftautocorr
 *
 *  Copyright (C) 2020 CareF
 *  \author CareF 
 *  Licensed under a 3-clause BSD style license - see LICENSE.md
 */

#ifndef FFTAUTOCORR_H
#define FFTAUTOCORR_H

#include <stdlib.h>

struct auto_plan_i;
typedef struct auto_plan_i * autocorr_plan;
autocorr_plan make_autocorr_plan(size_t length);
void destroy_autocorr_plan(autocorr_plan plan);
size_t mem_len(autocorr_plan plan);
int autocorr(double data[], size_t length);
int autocorr_p(autocorr_plan plan, double data[]);
int autocorr_mem(autocorr_plan plan, double data[], double *mempool);

#endif /* ifndef FFTAUTOCORR_H */
