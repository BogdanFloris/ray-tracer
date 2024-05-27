#ifndef VEC3_H
#define VEC3_H

#include <stdbool.h>

typedef struct vec3 {
    double e[3];
} vec3, point3;

char* vec3_to_string(char* buffer, vec3* a);
bool vec3_equal(vec3* a, vec3* b);
double vec3_length(vec3* a);
double vec3_length_squared(vec3* a);
vec3* vec3_add(vec3* result, vec3* a, vec3* b);
vec3* vec3_sub(vec3* result, vec3* a, vec3* b);
vec3* vec3_mul(vec3* result, vec3* a, vec3* b);
vec3* vec3_div(vec3* result, vec3* a, vec3* b);
vec3* vec3_mul_scalar(vec3* result, vec3* a, double t);
vec3* vec3_div_scalar(vec3* result, vec3* a, double t);
double vec3_dot(vec3* a, vec3* b);
vec3* vec3_cross(vec3* result, vec3* a, vec3* b);
vec3* vec3_unit(vec3* result, vec3* a);

void test_vec3();

#endif // VEC3_H
