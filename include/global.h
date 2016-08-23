#ifndef _GLOBAL_
#define _GLOBAL_

#include <string.h>
#include <stdlib.h>

typedef int PIXEL;
typedef int LABEL;

PIXEL **imgIn;
LABEL **imgOut;
LABEL lastLabel, numProvLabel;
int height, width, numObjects;

#define DIR "../../images/" 
#define BORDER_SIZE 2
//#define CHECK_ANSWER
//#define ALLOCA

#if defined(_MSC_VER) || defined(__MINGW32__)
    #define FOLDER ""
    #if defined(ALLOCA)
        #define ALLOCATE(X) _alloca(X);
        #define DEALLOCATE(X)
    #else
        #define ALLOCATE(X) malloc(X);
        #define DEALLOCATE(X) free(X);
    #endif
#else
    #define FOLDER "./"
    #if defined(ALLOCA)
        #define ALLOCATE(X) alloca(X);
        #define DEALLOCATE(X)
    #else
        #define ALLOCATE(X) malloc(X);
        #define DEALLOCATE(X) free(X);
    #endif
#endif

#define INIT_ALG \
    lastLabel = 0; \
    memset(imgOut[0], 0, height*width*sizeof(LABEL));

#define INIT_IMAGEIN \
    imgIn = (PIXEL **)malloc(height*sizeof(PIXEL *)); \
    imgIn[0] = (PIXEL *)malloc(height*width*sizeof(PIXEL));	\
    for(i=1; i<height; ++i) \
        imgIn[i] = imgIn[i-1] + width;

#define FREE_IMAGEIN \
    free(imgIn[0]); \
    free(imgIn);

#define INIT_IMAGEOUT \
    imgOut = (LABEL **)malloc(height*sizeof(LABEL *)); \
    imgOut[0] = (LABEL *)malloc(height*width*sizeof(LABEL)); \
    for(i=1; i<height; ++i) \
        imgOut[i] = imgOut[i-1] + width;

#define FREE_IMAGEOUT \
    free(imgOut[0]); \
    free(imgOut);

#define SWAP(TYPE,VARIABLE1,VARIABLE2) \
{ \
    TYPE const tmp = VARIABLE1; \
    VARIABLE1 = VARIABLE2; \
    VARIABLE2 = tmp; \
}

#if defined(CHECK_ANSWER)

    #include <stdio.h>
    #define PRINT_ERROR \
    { \
        puts("-1.0"); \
        FREE_IMAGEIN \
        FREE_IMAGEOUT \
        return 0; \
    }

    #define CHECK_NEIGHBOOR(imgIn, imgOut, i, neighboor) \
        if((imgIn[i] == imgIn[neighboor])^(imgOut[i] == imgOut[neighboor])) \
            PRINT_ERROR

    #define CHECK \
    { \
        PIXEL *imgInL = imgIn[0]; \
        LABEL *imgOutL = imgOut[0]; \
        const int ie = width*height; \
        for(i=0; i<ie; ++i) \
        { \
            if(imgInL[i]) \
            { \
                CHECK_NEIGHBOOR(imgInL, imgOutL, i, i-width-1); \
                CHECK_NEIGHBOOR(imgInL, imgOutL, i, i-width); \
                CHECK_NEIGHBOOR(imgInL, imgOutL, i, i-width+1); \
                CHECK_NEIGHBOOR(imgInL, imgOutL, i, i-1); \
            } \
            else if(imgOutL[i]) \
                PRINT_ERROR \
        } \
    }

    #define FREE_IMAGE CHECK FREE_IMAGEIN FREE_IMAGEOUT
#else
    #define FREE_IMAGE FREE_IMAGEIN FREE_IMAGEOUT
#endif

#if defined(__GNUC__) || defined(__MINGW32__)
    #define _INLINE inline __attribute__((gnu_inline))
    #define INLINE inline __attribute__((gnu_inline)) __attribute__((always_inline))
    #define NOINLINE __attribute__((noinline))
    #define _FASTCALL __attribute__((fastcall))
    #define _STDCALL __attribute__((stdcall))
    #define _POPEN popen
    #define _PCLOSE pclose
#elif defined(_MSC_VER)
    #define _INLINE __inline
    #define INLINE __forceinline
    #define NOINLINE __declspec(noinline)
    #define _FASTCALL __fastcall
    #define _STDCALL __stdcall
    #define _POPEN _popen
    #define _PCLOSE _pclose
#endif

#endif
