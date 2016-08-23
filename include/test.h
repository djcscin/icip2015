#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "arquivo.h"
#include "global.h"

#define NUM_CHAR 100

double times[NUM_ALG];
int order[NUM_ALG] = {0};

int read(char *, char *);
double execute(char *, char *, char *);

int main() {
    int i, j;
    char keep;
    srand(time(NULL));
    for (i = 0; i < NUM_ALG; ++i)
        order[i] = i;
    for (i = 0, keep = 1; i < ITERATIONS && keep; ++i)
        for (j = 0, keep = 0; j < DATABASE_SIZE; ++j)
            keep |= read(database[j][0], database[j][1]);
    return 0;
}

int read(char *in, char *out) {
    int t, i, j, k = 1;
    FILE *fin, *inImage, *fout;
    static char inDir[2 * NUM_CHAR], outDir[2 * NUM_CHAR];
    static char inImg[NUM_CHAR];

    sprintf(inDir, "%s%s", DIR, in);
    if ((fin = fopen(inDir, "r")) == NULL) {
        printf("Input file %s cannot be found!\n\n", inDir);
        return 0;
    }

    sprintf(outDir, "%s%s", DIR, out);
    if ((fout = fopen(outDir, "a")) == NULL) {
        printf("Output file %s cannot be created!\n\n", outDir);
        fclose(fin);
        fclose(fout);
        return 0;
    }

    while (fscanf(fin, "%s", inImg) != EOF) {
        sprintf(inDir, "%s%s", DIR, inImg);
        if ((inImage = fopen(inDir, "rb")) == NULL) {
            printf("Input file %s cannot be found!\n\n", inDir);
            fclose(fin);
            fclose(fout);
            return 0;
        }
        read_image_file(inImage);
        fclose(inImage);
        FREE_IMAGEIN

        for (j = 0; j < NUM_ALG; ++j) {
            i = ((float) rand()) / RAND_MAX * (NUM_ALG - 0.001f);
            if (i >= NUM_ALG) puts("error!");
            t = order[j];
            order[j] = order[i];
            order[i] = t;
        }

        for (j = 0; j < NUM_ALG; ++j) {
            i = order[j];
            times[i] = execute(func[i], inImg, "");
        }
        for (j = 0; j < NUM_ALG; ++j)
            fprintf(fout, "%.6lf,", times[j]);
        fprintf(fout, "%d,%d,%d,%d\n", height, width, numObjects, k);

        ++k;
    }

    fclose(fin);
    fclose(fout);
    return 1;
}

double execute(char *func, char *in, char *out) {
    FILE *f;
    double time = 0.0;
    static char cmd[2 * NUM_CHAR + ALG_NUM_CHAR];
    sprintf(cmd, "%s%s %s %s", FOLDER, func, in, out);
    f = _POPEN(cmd, "r");
    fscanf(f, "%lf", &time);
    _PCLOSE(f);
    return time;
}
