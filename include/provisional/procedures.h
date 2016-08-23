#ifndef _PROCEDURES_
#define _PROCEDURES_

#define PROCEDURE1(A,B,C) \
    if(imgOutPrevL[B]) \
        lab = imgOutPrevL[B]; \
    else if(imgOutPrevL[A]) { \
        lab = imgOutPrevL[A]; \
        if(imgOutPrevL[C]) \
            merge(lab,imgOutPrevL[C]); \
    } \
    else if(imgOutPrevL[C]) \
        lab = imgOutPrevL[C]; \
    else { \
        NEW_LABEL \
    } \
    imgOutL[B] = lab;

#define PROCEDURE2(A,B,C) \
    if(!imgOutPrevL[B] && imgOutPrevL[C]) \
        merge(lab,imgOutPrevL[C]); \
    imgOutL[B] = lab;

#define PROCEDURE3(A,B,C,D) \
    if(imgOutPrevL[B]) { \
        lab = imgOutPrevL[B]; \
        if(!imgOutPrevL[C] && imgOutPrevL[D]) \
            merge(lab,imgOutPrevL[D]); \
    } \
    else if(imgOutPrevL[A]) { \
        lab = imgOutPrevL[A]; \
        if(imgOutPrevL[C]) \
            merge(lab,imgOutPrevL[C]); \
        else if(imgOutPrevL[D]) \
            merge(lab,imgOutPrevL[D]); \
    } \
    else if(imgOutPrevL[C]) \
        lab = imgOutPrevL[C]; \
    else if(imgOutPrevL[D]) \
        lab = imgOutPrevL[D]; \
    else { \
        NEW_LABEL \
    } \
    imgOutL[B] = lab; \
    imgOutL[C] = lab;

#define PROCEDURE4(A,B,C,D) \
    if(imgOutPrevL[C]) { \
        if(!imgOutPrevL[B]) \
            merge(lab,imgOutPrevL[C]); \
    } \
    else if(imgOutPrevL[D]) \
        merge(lab,imgOutPrevL[D]); \
    imgOutL[B] = lab; \
    imgOutL[C] = lab;

#endif
