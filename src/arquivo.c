#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "arquivo.h"
#include "global.h"

#define LINE_NUM_CHAR 10000

void read_image(char *path) {
    FILE *f = fopen(path, "rb");
    read_image_file(f);
    fclose(f);
}

void read_image_file(FILE *f) {
    int i, j, w, h, k, fLen;
    char line[LINE_NUM_CHAR], magic[3], prox[50] = {0}, *buf, b;
    PIXEL *imgInL;
    fseek(f, 0, SEEK_END);
    fLen = ftell(f);
    fseek(f, 0, SEEK_SET);
    //lendo cabecalho
    fgets(line, LINE_NUM_CHAR, f);
    sscanf(line, "%s", magic);
    if (sscanf(&line[2], "%s", prox) && prox[0] != '#' && prox[0] != '\0')
        sscanf(&line[2], "%d %d", &width, &height);
    else {
        //lendo lines com comentarios
        while (fgets(line, LINE_NUM_CHAR, f) && line[0] == '#');
        sscanf(line, "%d %d", &width, &height);
    }
    //alocando memoria da imagem
    INIT_IMAGEIN
    //lendo dados da imagem e calculando o numero de objetos
    numObjects = 0;
    fLen -= ftell(f);
    buf = (char *) malloc(fLen * sizeof (char));
    fLen = fread(buf, sizeof (char), fLen, f);
    imgInL = imgIn[0];
    if (magic[1] == '1') { //P1
        for (i = 0, j = 0; i < fLen; ++i) {
            switch (buf[i]) {
                case '0':
                    imgInL[j] = 0;
                    ++j;
                    break;
                case '1':
                    imgInL[j] = 1;
                    ++j;
                    ++numObjects;
            }
        }
    } else if (magic[1] == '4') { //P4
        w = width >> 3;
        h = width & 7;
        k = 0;
        for (i = 0, j = 0; i < fLen; ++i) {
            b = buf[i];
            if (k < w) {
                k += h != 0;
                imgInL[j] = (b & 128) != 0;
                numObjects += imgInL[j++];
                imgInL[j] = (b & 64) != 0;
                numObjects += imgInL[j++];
                imgInL[j] = (b & 32) != 0;
                numObjects += imgInL[j++];
                imgInL[j] = (b & 16) != 0;
                numObjects += imgInL[j++];
                imgInL[j] = (b & 8) != 0;
                numObjects += imgInL[j++];
                imgInL[j] = (b & 4) != 0;
                numObjects += imgInL[j++];
                imgInL[j] = (b & 2) != 0;
                numObjects += imgInL[j++];
                imgInL[j] = (b & 1) != 0;
                numObjects += imgInL[j++];
            } else {
                for (k = 0; k < h; ++k) {
                    imgInL[j] = (b & 128) != 0;
                    numObjects += imgInL[j++];
                    b <<= 1;
                }
                k = 0;
            }
        }
    }
    free(buf);
    //colocando as bordas
    w = width - BORDER_SIZE;
    h = height - BORDER_SIZE;
    memset(imgIn[0], 0, BORDER_SIZE * width * sizeof (PIXEL));
    memset(imgIn[h], 0, BORDER_SIZE * width * sizeof (PIXEL));
    for (i = BORDER_SIZE; i < h; ++i) {
        imgInL = imgIn[i];
        for (j = 0; j < BORDER_SIZE; ++j)
            imgInL[j] = 0;
        for (j = w; j < width; ++j)
            imgInL[j] = 0;
    }
}

void print_labels(char *path) {
    FILE *f = fopen(path, "w");
    print_labels_file(f);
    fclose(f);
}

void print_labels_file(FILE *f) {
    int i, j;
    LABEL *imgOutL;
    //imprimindo cabecalho
    fprintf(f, "P2\n");
    fprintf(f, "%d %d\n", width, height);
    fprintf(f, "%d\n", lastLabel);
    //imprimindo dados da imagem
    for (i = 0; i < height; ++i) {
        imgOutL = imgOut[i];
        for (j = 0; j < width; ++j)
            fprintf(f, "%4d ", imgOutL[j]);
//          fprintf(f, "%4d ", (imgOut[i][j]<0)?0:imgOut[i][j]);
        fprintf(f, "\n");
    }
}
