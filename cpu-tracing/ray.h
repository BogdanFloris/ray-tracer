#ifndef RAY_H
#define RAY_H

#include "vec3.h"

typedef struct {
    point3 orig;
    vec3 dir;
} ray;

point3* ray_at(point3* result, ray* ray, double t);

void test_ray();

#endif // RAY_H
