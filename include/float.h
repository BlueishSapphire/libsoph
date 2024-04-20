#ifndef SOPH_FLOAT_H
#define SOPH_FLOAT_H

#include <float.h>

typedef float float32_t;
typedef double float64_t;

typedef float32_t f32;
typedef float64_t f64;

#define VEC2(T) struct { T x; T y; }
#define VEC3(T) struct { T x; T y; T z; }
#define VEC4(T) struct { T w; T x; T y; T z; }

typedef VEC2(f32) vec2f32;
typedef VEC3(f32) vec3f32;
typedef VEC4(f32) vec4f32;

typedef VEC2(f64) vec2f64;
typedef VEC3(f64) vec3f64;
typedef VEC4(f64) vec4f64;

#define EPSILON FLT_EPSILON

#endif // SOPH_FLOAT_H
