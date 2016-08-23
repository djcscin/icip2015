#ifndef _MYTIME_
#define _MYTIME_

double totaltime;

#if defined(_MSC_VER) || defined(__MINGW32__)

#include <windows.h>

__int64 freq,start,stop;

#define INIT_TIME \
	QueryPerformanceFrequency((LARGE_INTEGER *)&freq); \
	QueryPerformanceCounter((LARGE_INTEGER *)&start);

#define FINIT_TIME \
	QueryPerformanceCounter((LARGE_INTEGER *)&stop); \
	totaltime = 1000*(double)(stop-start) / (double)(freq);
	
#else

#include <time.h>

struct timespec start,stop;

#define INTERVAL_TIME(time,start,stop) \
	time = 1e3*(double)(stop.tv_sec-start.tv_sec) + (double)(stop.tv_nsec-start.tv_nsec)/1e6;

#define INIT_TIME  clock_gettime(CLOCK_MONOTONIC, &start);

#define FINIT_TIME \
	clock_gettime(CLOCK_MONOTONIC, &stop); \
	INTERVAL_TIME(totaltime,start,stop)

#endif

#endif
