#ifndef _BTS_
#define _BTS_

#include "unionFind.h"
#include "mytime.h"
#include "global.h"
#include "declarations.h"
#include "procedures.h"

void bts() {
    DEF_VARS_CELLS
    PIXEL F, G;
    LABEL lab;
    IMG_IN_LINE
    IMG_OUT_PREV_LINE
    IMG_OUT_LINE
    
    INIT_UNION_FIND
    INIT_ALG
    INIT_TIME

    //scanning phase
    for (FOR_CELLS1) {
        F = imgInL[i++]; G = imgInL[i];
        //NESSE PONTO SABEMOS QUE O PIXEL ANTERIOR FAZ PARTE DO BACKGROUND
        if (G) { //e=0, g=1
            if (F) { //e=0, f=1, g=1
                PROCEDURE3(i - 2, i - 1, i, i + 1)
            } else { //e=0, f=0, g=1
                PROCEDURE1(i - 1, i, i + 1) //PROCEDURE 1 com g
            }
            ++i; F = imgInL[i++]; G = imgInL[i];
            //A PARTIR DESSE PONTO SABEMOS QUE O PIXEL ANTERIOR FAZ PARTE DO FOREGROUND
            while (G) { //e=1, g=1
                if (F) { //e=1, f=1, g=1
                    PROCEDURE4(i - 2, i - 1, i, i + 1)
                } else { //e=1, f=0, g=1
                    PROCEDURE1(i - 1, i, i + 1) //PROCEDURE 1 com g
                }
                ++i; F = imgInL[i++]; G = imgInL[i];
            }
            //e=1, g=0
            if (F) { //e=1, f=1, g=0
                PROCEDURE2(i - 2, i - 1, i)//PROCEDURE 2 com f
            } //e=1, f=0, g=0 NADA A FAZER
        }
        //NESSE PONTO SABEMOS QUE O PIXEL ANTERIOR FAZ PARTE DO BACKGROUND
        else { //e=0, g=0
            if (F) { //e=0, f=1, g=0
                PROCEDURE1(i - 2, i - 1, i) //PROCEDURE 1 com f
            } //e=0, f=0, g=0 NADA A FAZER
        }
    }
    //analysis phase
    FLATTEN
    //labeling phase
    LABELING
    
    FINIT_TIME
    FREE_UNION_FIND
}

#endif
