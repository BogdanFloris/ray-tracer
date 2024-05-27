#include <assert.h>
#include <stdio.h>

#include "ray.h"
#include "vec3.h"

point3* ray_at(point3* result, ray* ray, double t) {
    return vec3_add(result, &ray->orig, vec3_mul_scalar(result, &ray->dir, t));
}

void test_ray() {
    printf("Running tests for ray...\n");
    point3 result;
    ray r = {.orig = {.e = {1, 2, 3}}, .dir = {.e = {4, 5, 6}}};
    ray_at(&result, &r, 2);
    assert(result.e[0] == 9);
    assert(result.e[1] == 12);
    assert(result.e[2] == 15);
    printf("ray tests passed!\n");
}
