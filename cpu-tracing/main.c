#include <stdlib.h>
#include <stdio.h>

#include "color.h"

static const char TARGET_FILE[] = "target/image.ppm";

int main() {
    // Image
    int image_width = 256;
    int image_height = 256;

    FILE *fp = fopen(TARGET_FILE, "w");
    if (fp == NULL) {
        perror("fopen() failed");
        return EXIT_FAILURE;
    }

    // Render
    static const char *header = "P3\n%d %d\n255\n";
    fprintf(fp, header, image_width, image_height);

    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            double r = (double)i / (image_width - 1);
            double g = (double)j / (image_height - 1);
            double b = 0.0;
            color color = {.e = {r, g, b}};
            write_color(fp, &color);
        }
    }
    fclose(fp);
    return EXIT_SUCCESS;
}
