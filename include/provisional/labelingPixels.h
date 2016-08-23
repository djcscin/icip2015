#ifndef _LABELING_PIXELS_
#define _LABELING_PIXELS_

#include "procedures2x2.h"

#define ePROCEDURE1aeR1 _ePROCEDURE1aeR1(LABEL_H,LABEL_I,LABEL_J,LABEL_H,LABEL_I,LABEL_J)
#define ePROCEDURE1aeR0	_ePROCEDURE1aeR0(LABEL_H,LABEL_I,LABEL_J,LABEL_H,LABEL_I,LABEL_J)
#define ePROCEDURE1bR0c _ePROCEDURE1bR0c
#define ePROCEDURE1fR1 	_ePROCEDURE1fR1_PIXELS
#define ePROCEDURE1fR0g	_ePROCEDURE1fR0g_PIXELS

#define ePROCEDURE2aef 	_ePROCEDURE2aef(LABEL_H,LABEL_I,LABEL_J,LABEL_I,LABEL_J)
#define ePROCEDURE2bd 	_ePROCEDURE2bd(LABEL_H,LABEL_I,LABEL_I)
#define ePROCEDURE2c 	_ePROCEDURE2c(LABEL_H,LABEL_I,LABEL_I)
#define ePROCEDURE2g 	_ePROCEDURE2g(LABEL_H,LABEL_I,LABEL_J,LABEL_I,LABEL_J)


#define LABELING_CASE_A \
    LABEL_O = lab; \
    LABEL_S = *lb[PIXEL_S]; \
    LABEL_T = *lb[PIXEL_T];

#define LABELING_CASE_B \
    LABEL_S = lab; \
    LABEL_T = *lb[PIXEL_T];

#define LABELING_CASE_C LABEL_T = lab;

#define LABELING_CASE_E \
    LABEL_O = lab; \
    LABEL_P = lab; \
    LABEL_S = *lb[PIXEL_S]; \
    LABEL_T = *lb[PIXEL_T];

#define LABELING_CASE_F \
    LABEL_P = lab; \
    LABEL_S = lab; \
    LABEL_T = *lb[PIXEL_T];

#define LABELING_CASE_G \
    LABEL_P = lab; \
    LABEL_T = *lb[PIXEL_T];

#define LABELING_CASE_FG \
    LABEL_P = lab; \
    LABEL_S = *lb[PIXEL_S]; \
    LABEL_T = *lb[PIXEL_T];


//HCS
#define hLABELING_CASE_A \
    imgOutL[j] = lab; \
    imgOutNextL[j] = *lb[imgInNextL[j]];

#define hLABELING_CASE_B imgOutNextL[j] = lab;

#define hPROCEDURE1a \
    _PROCEDURE1a(LABEL_H,LABEL_I,LABEL_J,LABEL_R,LABEL_H,LABEL_I,LABEL_J) \
    hLABELING_CASE_A

#define hPROCEDURE1b \
    _PROCEDURE1b(LABEL_R) \
    hLABELING_CASE_B

#define hPROCEDURE2a \
    _PROCEDURE2a(LABEL_I,LABEL_J,LABEL_J) \
    hLABELING_CASE_A

#define hPROCEDURE2b hLABELING_CASE_B

#define hPROCEDURE2bc imgOutNextL[j] = *lb[imgInNextL[j]];

#endif
