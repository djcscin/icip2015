#ifndef _HCS_
#define _HCS_

#include "unionFind.h"
#include "mytime.h"
#include "global.h"
#include "declarations.h"

void hcs() {
    DEF_VARS_ROWS2_COLS
    LABEL lab; DECLARING_LAB_ARRAY
#ifdef _LABELING_BLOCKS_
    IMG_IN_PREV_LINE
#endif
    IMG_IN_LINE
    IMG_IN_NEXT_LINE
    IMG_OUT_PREV_LINE
    IMG_OUT_LINE
    IMG_OUT_NEXT_LINE

    INIT_UNION_FIND
    INIT_ALG
    INIT_TIME

    //scanning phase
    for (FOR_ROWS) {
        for (FOR_COLS1) {
            if (imgInL[j]) {
                hPROCEDURE1a
                ++j;
                while (imgInL[j]) {
                    hPROCEDURE2a
                    ++j;
                }
#ifdef IMPROVED
                hPROCEDURE2bc
#else                
                if (imgInNextL[j]) {
                    hPROCEDURE2b
                }
#endif
            } else if (imgInNextL[j]) {
                hPROCEDURE1b
            }
        }
    }
    //analysis phase
    FLATTEN
    //labeling phase
    LABELING_HCS

    FINIT_TIME
    FREE_UNION_FIND
}

#endif
