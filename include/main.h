#include "global.h"
#include "arquivo.h"
#include "mytime.h"

void FUNCTION();

int main(int argc, char *argv[]) {
    int i;
    char in[200], out[200];

    if (argc == 2) {
        sprintf(in, "%s%s", DIR, argv[1]);
        read_image(in);
        INIT_IMAGEOUT
        FUNCTION();
        FREE_IMAGE
    } else if (argc == 3) {
        sprintf(in, "%s%s", DIR, argv[1]);
        sprintf(out, "%s%s", DIR, argv[2]);
        read_image(in);
        INIT_IMAGEOUT
        FUNCTION();
        print_labels(out);
        FREE_IMAGE
    }

    printf("%.6lf ", totaltime);
    return 0;
}
/*
int main(int argc, char *argv[]) {
    int i, j;
    char in[] = "../../images/artificial/image8192_0.40.pbm";

    for (j = 0; j < 50; ++j) {
        read_image(in);
        INIT_IMAGEOUT
        FUNCTION();
        FREE_IMAGE
    }

    return 0;
}
*/