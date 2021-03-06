#ifndef PREPROCESS_H
#define PREPROCESS_H

#include "ELM.h"

#include "PPParams.h"

extern float X_t[N_FEATURE];

#ifdef DS_TEST
extern float X_t_Processed[N_TEST][N_FEATURE];
#endif // DS_TEST

#ifdef STANDARD_SCALING
//int normalize_std(float* X, float* s_x, float* u_x);
int scale_std(float* X);
#elif defined(MINMAX_SCALING)
int scale_mm(float* X);
#endif

float* PCA_transform(float* X);

float* preprocess(float* X);

#endif

