#ifndef _eBOS_
#define _eBOS_

#include "unionFind.h"
#include "mytime.h"
#include "global.h"
#include "declarations.h"
#include "labelingBlocks.h"
#include "halfPass.h"

void ebos() {
    DEF_VARS_ROWS2_COLS
    PIXEL O, P;
    LABEL lab; DECLARING_LAB_ARRAY
    DECLARE_RUN1D
    IMG_IN_PREV_LINE
    IMG_IN_LINE
    IMG_IN_NEXT_LINE
    IMG_OUT_PREV_LINE
    IMG_OUT_LINE
    IMG_OUT_NEXT_LINE

    INIT_UNION_FIND
    INIT_RUN1D_Q_SIZE
    INIT_ALG
    INIT_TIME

    //scanning phase
    for (FOR_ROWS) {
        for (FOR_COLS2) {
            O = PIXEL_O; P = PIXEL_P; 
            //n=0
            if (P) { //n=0, p=1
                if (O) { //n=0, o=1, p=1
                    if (PIXEL_R) {
                        ePROCEDURE1aeR1
                    } else {
                        rSTART(j)
                        ePROCEDURE1aeR0
                    }
                    LABELING_CASE_E
                }
#ifdef IMPROVED
                else if (PIXEL_R && PIXEL_S) { //n=0, o=0, p=1, s=1, r=1
                    ePROCEDURE1fR1
                    LABELING_CASE_F
                } else { //n=0, o=0, p=1, s=1, r=0 OR n=0, o=0, p=1, s=0
                    rSTART(j)
                    ePROCEDURE1fR0g
                    LABELING_CASE_FG
                }
#else
                else if (PIXEL_S) { //n=0, o=0, p=1, s=1
                    if (PIXEL_R) {
                        ePROCEDURE1fR1
                    } else {
                        rSTART(j)
                        ePROCEDURE1fR0g
                    }
                    LABELING_CASE_F
                } else { //n=0, o=0, p=1, s=0
                    rSTART(j)
                    ePROCEDURE1fR0g
                    LABELING_CASE_G
                }
#endif
                
                j += 2; O = PIXEL_O; P = PIXEL_P; 
                //n=1
                while (P) { //n=1, p=1
                    if (O || //n=1, o=1, p=1
                            PIXEL_S) { //n=1, o=0, p=1, s=1
                        ePROCEDURE2aef
                        LABELING_CASE_EF
                    } else { //n=1, o=0, p=1, s=0
                        rSTART(j)
                        ePROCEDURE2g
                        LABELING_CASE_G
                    }
                    j += 2; O = PIXEL_O; P = PIXEL_P;
                }
                //n=1, p=0
                if (O) { //n=1, o=1, p=0
                    ePROCEDURE2aef
                    LABELING_CASE_A
                } else if (PIXEL_S) { //n=1, o=0, p=0, s=1
                    ePROCEDURE2bd
                    LABELING_CASE_B
                } else if (PIXEL_T) { //n=1, o=0, p=0, s=0, t=1
                    rSTART(j)
                    ePROCEDURE2c
                    LABELING_CASE_C
                } else { //n=1, o=0, p=0, s=0, t=0
                    ePROCEDURE2bd
                }
            }
            else { //n=0, p=0
                if (O) { //n=0, o=1, p=0
                    if (PIXEL_R) {
                        ePROCEDURE1aeR1
                    } else {
                        rSTART(j)
                        ePROCEDURE1aeR0
                    }
                    LABELING_CASE_A
                } else if (PIXEL_S) { //n=0, o=0, p=0, s=1
                    if (!PIXEL_R) {
                        rSTART(j)
                        ePROCEDURE1bR0c
                    }
                    LABELING_CASE_B
                } else if (PIXEL_T) { //n=0, o=0, p=0, s=0, t=1
                    rSTART(j)
                    ePROCEDURE1bR0c
                    LABELING_CASE_C
                }
                //n=0, o=0, p=0, s=0, t=0 NADA A FAZER
            }
        }
    }
    //analysis phase
    FLATTEN
    //labeling phase
    LABELING2x2_ONE_AND_HALF_SCAN_HALF_STRIPE

    FINIT_TIME
    FREE_UNION_FIND
    FREE_RUN1D
}

#endif
