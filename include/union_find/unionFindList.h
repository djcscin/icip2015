#ifndef _UNION_FIND_LIST_
#define _UNION_FIND_LIST_

#include "unionFind.h"

LABEL *tail;
LABEL *next;

#define INIT_UNION_FIND \
{ \
    const int size_p = UNION_FIND_SIZE; \
    rep = (LABEL *)malloc(3*size_p*sizeof(LABEL)); \
    rep[0] = 0; \
    next = rep + size_p; \
    next[0] = 0; \
    tail = next + size_p; \
    tail[0] = 0; \
}

#define FREE_UNION_FIND	free(rep);

#define MAKE \
{ \
    LABEL lab = ++lastLabel; \
    rep[lab] = lab; \
    tail[lab] = lab; \
    next[lab] = -1; \
}

#define MERGE(La,Lb) \
{ \
    next[tail[La]] = Lb; \
    tail[La] = tail[Lb]; \
    do \
    { \
        rep[Lb] = La; \
        Lb = next[Lb]; \
    } while (Lb > 0); \
}

#define UNION(La,Lb) \
{ \
    LABEL Ra = rep[La]; \
    LABEL Rb = rep[Lb]; \
    if(Ra != Rb) \
    { \
        if(Ra < Rb) \
            MERGE(Ra, Rb) \
        else \
            MERGE(Rb, Ra) \
    } \
}

#define FLATTEN \
    numProvLabel = lastLabel;\
    lastLabel = 0; \
    for(lab=1; lab<=numProvLabel; ++lab) \
    { \
        if(rep[lab] == lab) \
            rep[lab] = ++lastLabel; \
        else \
            rep[lab] = rep[rep[lab]]; \
    }

DEFINE_UNION_FIND

#endif
