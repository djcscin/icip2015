#ifndef _HALF_PASS_
#define _HALF_PASS_

#include <stdlib.h>

#define DECLARE_RUN1D       int run_head, run_tail = -1, *run_se;
#define INIT_RUN1D          run_se = (int *)malloc(height*(width+1)*sizeof(int));
#define INIT_RUN1D_H_SIZE   run_se = (int *)malloc(height*(width+1)*sizeof(int)/2);
#define INIT_RUN1D_Q_SIZE   run_se = (int *)malloc(height*(width+1)*sizeof(int)/4);
#define FREE_RUN1D          free(run_se);

#define rSTART(X)           run_se[++run_tail] = X;
#define rEND(X)             run_se[++run_tail] = X;

#define DECLARE_RUN2D       int run_head, run_tail = -1, *run_rse;
#define INIT_RUN2D          run_rse = (int *)malloc(height*(width+1)*sizeof(int)*3/2);
#define INIT_RUN2D_H_SIZE   run_rse = (int *)malloc(height*(width+1)*sizeof(int)*3/4);
#define INIT_RUN2D_Q_SIZE   run_rse = (int *)malloc(height*(width+1)*sizeof(int)*3/8);
#define FREE_RUN2D          free(run_rse);

#define rSTART2D(I,X)       run_rse[++run_tail] = I; run_rse[++run_tail] = X;
#define rEND2D(I,X)         run_rse[++run_tail] = X;

#endif
