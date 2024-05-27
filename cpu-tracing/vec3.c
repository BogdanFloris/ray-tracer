#include "vec3.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

char* vec3_to_string(char* buffer, vec3* a) {
    sprintf(buffer, "[%f, %f, %f]", a->e[0], a->e[1], a->e[2]);
    return buffer;
}

bool vec3_equal(vec3* a, vec3* b) {
    for (int i = 0; i < 3; i++) {
        if (a->e[i] != b->e[i]) {
            return false;
        }
    }
    return true;
}

double vec3_length(vec3* a) {
    return sqrt(vec3_length_squared(a));
}

double vec3_length_squared(vec3* a) {
    return a->e[0] * a->e[0] + a->e[1] * a->e[1] + a->e[2] * a->e[2];
}

vec3* vec3_add(vec3* result, vec3* a, vec3* b) {
    for (int i = 0; i < 3; i++) {
        result->e[i] = a->e[i] + b->e[i];
    }
    return result;
}

vec3* vec3_sub(vec3* result, vec3* a, vec3* b) {
    for (int i = 0; i < 3; i++) {
        result->e[i] = a->e[i] - b->e[i];
    }
    return result;
}

vec3* vec3_mul(vec3* result, vec3* a, vec3* b) {
    for (int i = 0; i < 3; i++) {
        result->e[i] = a->e[i] * b->e[i];
    }
    return result;
}

vec3* vec3_div(vec3* result, vec3* a, vec3* b) {
    for (int i = 0; i < 3; i++) {
        result->e[i] = a->e[i] / b->e[i];
    }
    return result;
}

vec3* vec3_mul_scalar(vec3* result, vec3* a, double t) {
    for (int i = 0; i < 3; i++) {
        result->e[i] = a->e[i] * t;
    }
    return result;
}

vec3* vec3_div_scalar(vec3* result, vec3* a, double t) {
    for (int i = 0; i < 3; i++) {
        result->e[i] = a->e[i] / t;
    }
    return result;
}

double vec3_dot(vec3* a, vec3* b) {
    double result = 0;
    for (int i = 0; i < 3; i++) {
        result += a->e[i] * b->e[i];
    }
    return result;
}

vec3* vec3_cross(vec3* result, vec3* a, vec3* b) {
    result->e[0] = a->e[1] * b->e[2] - a->e[2] * b->e[1];
    result->e[1] = a->e[2] * b->e[0] - a->e[0] * b->e[2];
    result->e[2] = a->e[0] * b->e[1] - a->e[1] * b->e[0];
    return result;
}

vec3* vec3_unit(vec3* result, vec3* a) {
    double length = vec3_length(a);
    return vec3_div_scalar(result, a, length);
}

void test_vec3() {
    printf("Running tests for vec3...\n");
    vec3 a = {.e = {1, 2, 3}};
    vec3 b = {.e = {4, 5, 6}};
    vec3 result = {.e = {0, 0, 0}};

    vec3_add(&result, &a, &b);
    assert(vec3_equal(&result, &(vec3){.e = {5, 7, 9}}));

    vec3_sub(&result, &a, &b);
    assert(vec3_equal(&result, &(vec3){.e = {-3, -3, -3}}));

    vec3_mul(&result, &a, &b);
    assert(vec3_equal(&result, &(vec3){.e = {4, 10, 18}}));

    vec3_div(&result, &a, &b);
    assert(vec3_equal(&result, &(vec3){.e = {0.25, 0.4, 0.5}}));

    vec3_mul_scalar(&result, &a, 2);
    assert(vec3_equal(&result, &(vec3){.e = {2, 4, 6}}));

    vec3_div_scalar(&result, &a, 2);
    assert(vec3_equal(&result, &(vec3){.e = {0.5, 1, 1.5}}));

    double dot = vec3_dot(&a, &b);
    assert(dot == 32);

    vec3_cross(&result, &a, &b);
    assert(vec3_equal(&result, &(vec3){.e = {-3, 6, -3}}));

    vec3_unit(&result, &a);
    assert(vec3_equal(&result, &(vec3){.e = {1 / sqrt(14), 2 / sqrt(14), 3 / sqrt(14)}}));

    printf("vec3 tests passed!\n");
}
