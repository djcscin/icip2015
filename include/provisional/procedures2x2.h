#ifndef _PROCEDURES2x2_
#define _PROCEDURES2x2_

#include "blocks.h"

#define _ePROCEDURE1aeR1(_PIXEL_H,_PIXEL_I,_PIXEL_J,_LABEL_H,_LABEL_I,_LABEL_J) \
    if(_PIXEL_I) \
        merge(lab,_LABEL_I); \
    else if(_PIXEL_J) { \
        merge(lab,_LABEL_J); \
        if(_PIXEL_H) \
            merge(lab,_LABEL_H); \
    } \
    else if(_PIXEL_H) \
        merge(lab,_LABEL_H);

#define _ePROCEDURE1aeR0(_PIXEL_H,_PIXEL_I,_PIXEL_J,_LABEL_H,_LABEL_I,_LABEL_J) \
    if(_PIXEL_I) \
        lab = _LABEL_I; \
    else if(_PIXEL_J) { \
        lab = _LABEL_J; \
        if(_PIXEL_H) \
            merge(lab,_LABEL_H); \
    } \
    else if(_PIXEL_H) \
        lab = _LABEL_H; \
    else { \
        NEW_LABEL \
    }

#define _ePROCEDURE1bR0c NEW_LABEL

#define _ePROCEDURE1fR1_BLOCKS \
    if(PIXEL_I || PIXEL_J) \
        merge(lab,LABEL_BLOCK_B);

#define _ePROCEDURE1fR1_PIXELS \
    if(LABEL_I) \
        merge(lab,LABEL_I); \
    else if(LABEL_J) \
        merge(lab,LABEL_J);

#define _ePROCEDURE1fR0g_BLOCKS \
    if(PIXEL_I || PIXEL_J) \
        lab = LABEL_BLOCK_B; \
    else { \
        NEW_LABEL \
    }

#define _ePROCEDURE1fR0g_PIXELS \
    if(LABEL_I) \
        lab = LABEL_I; \
    else if(LABEL_J) \
        lab = LABEL_J; \
    else { \
        NEW_LABEL \
    }

#define _ePROCEDURE2aef(_PIXEL_H,_PIXEL_I,_PIXEL_J,_LABEL_I,_LABEL_J) \
    if(_PIXEL_I) { \
        if(!_PIXEL_H) \
            merge(lab,_LABEL_I); \
    } \
    else if(_PIXEL_J) { \
        merge(lab,_LABEL_J); \
    }

#define _ePROCEDURE2bd(_PIXEL_H,_PIXEL_I,_LABEL_I) \
    if(!_PIXEL_H && _PIXEL_I) \
        merge(lab,_LABEL_I);

#define _ePROCEDURE2c(_PIXEL_H,_PIXEL_I,_LABEL_I) \
    _ePROCEDURE2bd(_PIXEL_H,_PIXEL_I,_LABEL_I) \
    NEW_LABEL

#define _ePROCEDURE2g(_PIXEL_H,_PIXEL_I,_PIXEL_J,_LABEL_I,_LABEL_J) \
    if(_PIXEL_I) { \
        if(!_PIXEL_H) \
            merge(lab,_LABEL_I); \
    } \
    else if(_PIXEL_J) \
        lab = _LABEL_J; \
    else { \
        NEW_LABEL \
    }


#define _PROCEDURE1a(_PIXEL_H,_PIXEL_I,_PIXEL_J,_PIXEL_R,_LABEL_H,_LABEL_I,_LABEL_J) \
    if(_PIXEL_R) { \
        _ePROCEDURE1aeR1(_PIXEL_H,_PIXEL_I,_PIXEL_J,_LABEL_H,_LABEL_I,_LABEL_J) \
    } else { \
        _ePROCEDURE1aeR0(_PIXEL_H,_PIXEL_I,_PIXEL_J,_LABEL_H,_LABEL_I,_LABEL_J) \
    }

#define _PROCEDURE1b(_PIXEL_R) \
    if(!_PIXEL_R) { \
        NEW_LABEL \
    }

#define _PROCEDURE2a(_PIXEL_I,_PIXEL_J,_LABEL_J) \
    if(!_PIXEL_I && _PIXEL_J) \
        merge(lab,_LABEL_J);

#endif
