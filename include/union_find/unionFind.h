#ifndef _UNION_FIND_
#define _UNION_FIND_

#include "declarations.h"

LABEL *rep;

#define UNION_FIND_SIZE (((width+1)/2)*((height+1)/2) + 1)

#define	DEFINE_UNION_FIND \
    static NOINLINE void merge(LABEL arg0, LABEL arg1) UNION(arg0,arg1) \
    static INLINE void make(void) MAKE

#define NEW_LABEL \
    make(); \
    lab = lastLabel; \

#define LABELING \
    for(FOR_CELLS1) \
        imgOutL[i] = rep[imgOutL[i]];

#define LABELING_ONE_AND_HALF_SCAN_FULL_RUN \
    for(run_head=0; run_head<run_tail; run_head+=2) \
        for(i=run_se[run_head], k=run_se[run_head+1], lab=rep[imgOutL[i]]; i<k; ++i) \
            imgOutL[i] = lab;

#define LABELING_ONE_AND_HALF_SCAN_HALF_RUN \
    run_se[++run_tail] = _end; \
    for(run_head=0, k=run_se[0]; run_head<run_tail; ) \
        for(i=k, k=run_se[++run_head], lab=rep[imgOutL[i]]; i<k && imgOutL[i]; ++i) \
            imgOutL[i] = lab;

#define LABELING_ROS \
    for(run_head=0; run_head<run_tail; ++run_head) \
        for(lab=rep[run_lb[run_head]], i=run_s[run_head], k=run_e[run_head]; i<=k; ++i) \
            imgOutL[i] = lab;

#define DECLARING_LAB_ARRAY \
    LABEL _lb0 = 0; \
    LABEL * const lb[2] = {&_lb0, &lab};

#define LABELING_A_BLOCK2x1 \
    imgOutL[j] = *lb[imgInL[j]]; \
    imgOutNextL[j] = *lb[imgInNextL[j]];

#define LABELING_A_BLOCK2x2 \
    LABEL_O = *lb[PIXEL_O]; \
    LABEL_P = *lb[PIXEL_P]; \
    LABEL_S = *lb[PIXEL_S]; \
    LABEL_T = *lb[PIXEL_T];

#define LABELING2x1 \
    for(FOR_ROWS) \
        for(FOR_COLS1) { \
            lab = hLABEL_BLOCK_E; \
            if(lab) { \
                lab = rep[lab]; \
                LABELING_A_BLOCK2x1 \
            } \
        }

#define LABELING2x1_LUT \
    for(FOR_ROWS) \
        for(FOR_COLS1) { \
            lab = rep[hLABEL_BLOCK_E]; \
            LABELING_A_BLOCK2x1 \
        }

#define LABELING2x2 \
    for(FOR_ROWS) \
        for(FOR_COLS2) { \
            lab = LABEL_BLOCK_E; \
            if(lab) { \
                lab = rep[lab]; \
                LABELING_A_BLOCK2x2 \
            } \
        }

#define LABELING2x2_LUT \
    for(FOR_ROWS) \
        for(FOR_COLS2) { \
            lab = rep[LABEL_BLOCK_E]; \
            LABELING_A_BLOCK2x2 \
        }

#define LABELING2x2_ONE_AND_HALF_SCAN_FULL_STRIPE \
    for(run_head=0; run_head<run_tail; run_head+=2) \
        for(j=run_se[run_head], i=run_se[run_head+1], lab=rep[LABEL_BLOCK_E]; j<i; j+=2) { \
            LABELING_A_BLOCK2x2 \
        }

#define LABELING2x2_ONE_AND_HALF_SCAN_HALF_STRIPE \
    run_se[++run_tail] = _end; \
    for(run_head=0, i=run_se[0]; run_head<run_tail; ) { \
        for(j=i, i=run_se[++run_head], lab=rep[LABEL_BLOCK_E]; j<i && LABEL_BLOCK_E; j+=2) { \
            LABELING_A_BLOCK2x2 \
        } \
    }

#define LABELING2x2_ONE_AND_HALF_SCAN_BLOCKS \
    for(blocks_head=-1; blocks_head<blocks_tail;) { \
        POP_BLOCKS1D(j) \
        lab = rep[LABEL_BLOCK_E]; \
        LABELING_A_BLOCK2x2 \
    }

#endif
