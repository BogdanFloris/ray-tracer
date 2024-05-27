#include "color.h"

void write_color(FILE* fp, color* color) {
    int ir = (int)(255.999 * color->e[0]);
    int ig = (int)(255.999 * color->e[1]);
    int ib = (int)(255.999 * color->e[2]);
    fprintf(fp, "%d %d %d\n", ir, ig, ib);
}
