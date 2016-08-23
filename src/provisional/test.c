#define ITERATIONS 50
#define NUM_ALG 8
#define ALG_NUM_CHAR 10
#define DATABASE_SIZE 2
#define FILE_NUM_CHAR 25

char func[NUM_ALG][ALG_NUM_CHAR] = {
    "BTS", "eBTSb", "eBTSp", "BBDT", "sBBDT", "HCS", "BOS", "eBOS"
};

char database[DATABASE_SIZE][2][FILE_NUM_CHAR] = {
    { "document3x3.txt", "resultsDoc.txt" },
    { "artificial2013.txt", "resultsArt.txt" }
};

#include "test.h"
