#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "color.h"
#include "ray.h"
#include "vec3.h"

static const char TARGET_FILE[] = "target/image.ppm";

color* ray_color(color* c, ray* r) {
    // blue to white gradient
    vec3 unit_direction;
    vec3_unit(&unit_direction, &r->dir);
    double a = 0.5 * (unit_direction.e[1] + 1.0);
    color white = {.e = {1.0, 1.0, 1.0}};
    color blue = {.e = {0.5, 0.7, 1.0}};
    color white_blend;
    vec3_mul_scalar(&white_blend, &white, 1.0 - a);
    color blue_blend;
    vec3_mul_scalar(&blue_blend, &blue, a);
    vec3_add(c, &white_blend, &blue_blend);
    return c;
}

int main() {
    // Image
    const double aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = (int)(image_width / aspect_ratio);
    assert(image_height >= 1);

    // Camera
    const double focal_length = 1.0;
    const double viewport_height = 2.0;
    const double viewport_width =
        viewport_height * ((double)image_width / image_height);
    point3 camera_center = {.e = {0, 0, 0}};

    // Calculate the vectors across the horizontal and down the vertical
    // viewport edges.
    vec3 viewport_u = {.e = {viewport_width, 0, 0}};
    vec3 viewport_v = {.e = {0, -viewport_height, 0}};

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    vec3 pixel_delta_u;
    vec3_div_scalar(&pixel_delta_u, &viewport_u, image_width);
    vec3 pixel_delta_v;
    vec3_div_scalar(&pixel_delta_v, &viewport_v, image_height);

    // Calculate the location of the upper left pixel.
    vec3 viewport_u_halved;
    vec3_div_scalar(&viewport_u_halved, &viewport_u, 2);

    vec3 viewport_v_halved;
    vec3_div_scalar(&viewport_v_halved, &viewport_v, 2);

    vec3 focal_vec = {.e = {0, 0, focal_length}};
    vec3 viewport_upper_left;
    vec3_sub(&viewport_upper_left, &camera_center, &focal_vec);
    vec3_sub(&viewport_upper_left, &viewport_upper_left, &viewport_u_halved);
    vec3_sub(&viewport_upper_left, &viewport_upper_left, &viewport_v_halved);

    point3 pixel00_loc;
    vec3_add(&pixel00_loc, &pixel_delta_u, &pixel_delta_v);
    vec3_mul_scalar(&pixel00_loc, &pixel00_loc, 0.5);
    vec3_add(&pixel00_loc, &pixel00_loc, &viewport_upper_left);

    FILE* fp = fopen(TARGET_FILE, "w");
    if (fp == NULL) {
        perror("fopen() failed");
        return EXIT_FAILURE;
    }

    // Render
    static const char* header = "P3\n%d %d\n255\n";
    fprintf(fp, header, image_width, image_height);

    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            vec3 pixel_delta_u_i;
            vec3_mul_scalar(&pixel_delta_u_i, &pixel_delta_u, i);

            vec3 pixel_delta_v_j;
            vec3_mul_scalar(&pixel_delta_v_j, &pixel_delta_v, j);

            vec3 pixel_center;
            vec3_add(&pixel_center, &pixel00_loc, &pixel_delta_u_i);
            vec3_add(&pixel_center, &pixel_center, &pixel_delta_v_j);

            vec3 ray_direction;
            vec3_sub(&ray_direction, &pixel_center, &camera_center);

            ray r = {.orig = camera_center, .dir = ray_direction};
            color pixel_color;
            ray_color(&pixel_color, &r);
            write_color(fp, &pixel_color);
        }
    }
    fclose(fp);
    return EXIT_SUCCESS;
}
