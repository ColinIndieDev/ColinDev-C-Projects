#include "../include/cpstd/mathplus.h"

uint64_t math_fibonacci(uint64_t n) {
    return (uint64_t)((pow((1 + sqrt(5)) * 0.5, (double)n) - pow((1 - sqrt(5)) * 0.5, (double)n)) / sqrt(5));
}

uint64_t math_qpow(int base, uint32_t exp) {
    uint64_t result = 1;
    for (;;) {
        if (exp & 1) {
            result *= base;
        }
        exp >>= 1;
        if (!exp) {
            break;
        }
        base *= base;
    }
    return result;
}

float math_qsqrt(float x) {
   union {
       int i; 
       float f;
   } u;
   u.i = 0x5F375A86 - (*(int*)&x >> 1);
   return (3 - x * u.f * u.f) * x * u.f * 0.5f;
}

float math_rad(float deg) {
    return deg * (float)(MATH_PI / 180.0);
}

int vec2f_cmp(vec2f a, vec2f b) { 
    return a.x == b.x && a.y == b.y; 
}
vec2f vec2f_add(vec2f a, vec2f b) { 
    return (vec2f){a.x + b.x, a.y + b.y}; 
}
vec2f vec2f_sub(vec2f a, vec2f b) { 
    return (vec2f){a.x - b.x, a.y - b.y}; 
}
vec2f vec2f_mul(vec2f a, vec2f b) { 
    return (vec2f){a.x * b.x, a.y * b.y}; 
}
vec2f vec2f_div(vec2f a, vec2f b) { 
    return (vec2f){a.x / b.x, a.y / b.y}; 
}
vec2f vec2f_float_add(vec2f a, float b) { 
    return (vec2f){a.x + b, a.y + b}; 
}
vec2f vec2f_float_sub(vec2f a, float b) { 
    return (vec2f){a.x - b, a.y - b}; 
}
vec2f vec2f_float_mul(vec2f a, float b) { 
    return (vec2f){a.x * b, a.y * b}; 
}
vec2f vec2f_float_div(vec2f a, float b) { 
    return (vec2f){a.x / b, a.y / b}; 
}
float vec2f_dist(vec2f a, vec2f b) {
    float x = math_abs(a.x - b.x);
    float y = math_abs(a.y - b.y);

    return sqrtf((x * x) + (y * y));
}
float vec2f_dist2(vec2f a, vec2f b) {
    float x = math_abs(a.x - b.x);
    float y = math_abs(a.y - b.y);

    return (x * x) + (y * y);
}
float vec2f_dot(vec2f a, vec2f b) {
    return (a.x * b.x) + (a.y * b.y); 
}
float vec2f_length(vec2f a) { 
    return sqrtf((a.x * a.x) + (a.y * a.y)); 
}
vec2f vec2f_clamp(vec2f v, vec2f n, vec2f m) {
    return (vec2f){math_clamp(v.x, n.x, m.x), math_clamp(v.y, n.y, m.y)};
}
vec2f vec2f_norm(vec2f v) {
    return (vec2f){v.x / sqrtf((v.x * v.x) + (v.y * v.y)),
                   v.y / sqrtf((v.x * v.x) + (v.y * v.y))};
}

vec3f vec3f_sub(vec3f a, vec3f b) { 
    return (vec3f){a.x - b.x, a.y - b.y, a.z - b.z}; 
}
vec3f vec3f_scale(vec3f v, float s) { 
    return (vec3f){v.x * s, v.y * s, v.z * s}; 
}
vec3f vec3f_add(vec3f a, vec3f b) { 
    return (vec3f){a.x + b.x, a.y + b.y, a.z + b.z}; 
}
float vec3f_dot(vec3f a, vec3f b) { 
    return a.x * b.x + a.y * b.y + a.z * b.z; 
}
vec3f vec3f_cross(vec3f a, vec3f b) { 
    return (vec3f){a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}
float vec3f_length(vec3f v) { 
    return sqrtf(vec3f_dot(v, v)); 
}
vec3f vec3f_norm(vec3f v) { 
    float l = vec3f_length(v); 
    return (l > 0) ? vec3f_scale(v, 1.0f / l) : (vec3f){0, 0, 0}; 
}

void mat4f_identity(mat4f *m) {
    memset(*m, 0, sizeof(float) * 16);
    (*m)[0]  = 1.0f;
    (*m)[5]  = 1.0f;
    (*m)[10] = 1.0f;
    (*m)[15] = 1.0f;
}
void mat4f_translate(mat4f *m, vec3f v) {
    (*m)[12] += ((*m)[0] * v.x) + ((*m)[4] * v.y) + ((*m)[8] * v.z);
    (*m)[13] += ((*m)[1] * v.x) + ((*m)[5] * v.y) + ((*m)[9] * v.z);
    (*m)[14] += ((*m)[2] * v.x) + ((*m)[6] * v.y) + ((*m)[10] * v.z);
    (*m)[15] += ((*m)[3] * v.x) + ((*m)[7] * v.y) + ((*m)[11] * v.z);
}
void mat4f_scale(mat4f *m, vec3f v) {
    (*m)[0] *= v.x; 
    (*m)[1] *= v.x; 
    (*m)[2] *= v.x; 
    (*m)[3] *= v.x;
    (*m)[4] *= v.y; 
    (*m)[5] *= v.y; 
    (*m)[6] *= v.y; 
    (*m)[7] *= v.y;
    (*m)[8] *= v.z; 
    (*m)[9] *= v.z; 
    (*m)[10] *= v.z; 
    (*m)[11] *= v.z;
}
void mat4f_mul(mat4f *a, mat4f *b, mat4f *dest) {
    mat4f result;
    for (unsigned int c = 0; c < 4; c++) {
        for (unsigned int r = 0; r < 4; r++) {
            result[(c * 4) + r] =  ((*a)[(0 * 4) + r] * (*b)[(c * 4) + 0]) + ((*a)[(1 * 4) + r] * (*b)[(c * 4) + 1]) +
                                   ((*a)[(2 * 4) + r] * (*b)[(c * 4) + 2]) + ((*a)[(3 * 4) + r] * (*b)[(c * 4) + 3]);
        }
    }
    memcpy(*dest, result, sizeof(mat4f));
}
void mat4f_rotate(mat4f *m, float angle_rad, vec3f axis) {
    float c = cosf(angle_rad);
    float s = sinf(angle_rad);
    float t = 1.0f - c;

    float x = axis.x;
    float y = axis.y;
    float z = axis.z;

    mat4f rot;
    mat4f_identity(&rot);

    rot[0] = (t * x * x) + c;
    rot[1] = (t * x * y) + (s * z);
    rot[2] = (t * x * z) - (s * y);

    rot[4] = (t * x * y) - (s * z);
    rot[5] = (t * y * y) + c;
    rot[6] = (t * y * z) + (s * x);

    rot[8] = (t * x * z) + (s * y);
    rot[9] = (t * y * z) - (s * x);
    rot[10] = (t * z * z) + c;

    mat4f_mul(m, &rot, m);
}
vec4f mat4f_mul_vec4f(mat4f *m, vec4f v) {
    vec4f out;
    out.data[0] = ((*m)[0] * v.data[0]) + ((*m)[4] * v.data[1]) + ((*m)[8] * v.data[2]) + ((*m)[12] * v.data[3]);
    out.data[1] = ((*m)[1] * v.data[0]) + ((*m)[5] * v.data[1]) + ((*m)[9] * v.data[2]) + ((*m)[13] * v.data[3]);
    out.data[2] = ((*m)[2] * v.data[0]) + ((*m)[6] * v.data[1]) + ((*m)[10] * v.data[2]) + ((*m)[14] * v.data[3]);
    out.data[3] = ((*m)[3] * v.data[0]) + ((*m)[7] * v.data[1]) + ((*m)[11] * v.data[2]) + ((*m)[15] * v.data[3]);
    return out;
}
void mat4f_ortho(mat4f *m, float left, float right, float bottom, float top, float near, float far) {
    memset((*m), 0, sizeof(float) * 16);

    (*m)[0]  =  2.0f / (right - left);
    (*m)[5]  =  2.0f / (top - bottom);
    (*m)[10] = -2.0f / (far - near);
    (*m)[12] = -(right + left) / (right - left);
    (*m)[13] = -(top + bottom) / (top - bottom);
    (*m)[14] = -(far + near) / (far - near);
    (*m)[15] = 1.0f;    
}
void mat4f_perspective(mat4f *m, float near, float far, float fov, float aspect) {
    memset((*m), 0, sizeof(float) * 16);
    
    (*m)[0]  = 1.0f / (aspect * tanf(fov * 0.5f));
    (*m)[5]  = 1.0f / (tanf(fov * 0.5f));
    (*m)[10] = -(far + near) / (far - near);   
    (*m)[11] = -1.0f;
    (*m)[14] = -(2.0f * far * near) / (far - near);   
}
void mat4f_look_at(mat4f *m, vec3f eye, vec3f center, vec3f up) {
    vec3f zaxis = vec3f_norm(vec3f_sub(eye, center));
    vec3f xaxis = vec3f_norm(vec3f_cross(up, zaxis));
    vec3f yaxis = vec3f_cross(zaxis, xaxis);

    (*m)[0]  = xaxis.x;
    (*m)[1]  = yaxis.x;
    (*m)[2]  = zaxis.x;
    (*m)[3]  = 0.0f;

    (*m)[4]  = xaxis.y;
    (*m)[5]  = yaxis.y;
    (*m)[6]  = zaxis.y;
    (*m)[7]  = 0.0f;

    (*m)[8]  = xaxis.z;
    (*m)[9]  = yaxis.z;
    (*m)[10] = zaxis.z;
    (*m)[11] = 0.0f;

    (*m)[12] = -vec3f_dot(xaxis, eye);
    (*m)[13] = -vec3f_dot(yaxis, eye);
    (*m)[14] = -vec3f_dot(zaxis, eye);
    (*m)[15] = 1.0f;
}
static float minor_mat3f_det(const float *data, unsigned int r, unsigned int c) {
    float sub[3][3];
    unsigned int si = 0;
    for (unsigned int i = 0; i < 4; i++) {
        if (i == r) {
            continue;
        }
        unsigned int sj = 0;
        for (unsigned int j = 0; j < 4; j++) {
            if (j == c) {
                continue;
            }
            sub[si][sj++] = data[(j * 4) + i];
        }
        si++;
    }
    return (sub[0][0] * (sub[1][1] * sub[2][2] - sub[1][2] * sub[2][1])) - (sub[0][1] * (sub[1][0] * sub[2][2] - sub[1][2] * sub[2][0])) +
           (sub[0][2] * (sub[1][0] * sub[2][1] - sub[1][1] * sub[2][0]));
}
float mat4f_det(mat4f *m) {
    float det = 0.0f;
    for (unsigned int j = 0; j < 4; j++) {
        float cofactor = minor_mat3f_det((*m), 0, j);
        if (j % 2 != 0) {
            cofactor = -cofactor;
        }
        det += (*m)[(j * 4) + 0] * cofactor;
    }
    return det;
}
float mat4f_get_float(mat4f *m, unsigned int c, unsigned int r) {
    return (*m)[c * 4 + r];
}
void mat4f_inv(mat4f *m, mat4f *out) {
    float cofactors[4][4];
    for (unsigned int i = 0; i < 4; i++) {
        for (unsigned int j = 0; j < 4; j++) {
            float c = minor_mat3f_det((*m), i, j);
            if ((i + j) % 2 != 0) c = -c;
            cofactors[i][j] = c;
        }
    }
    
    float det = 0.0f;
    for (unsigned int j = 0; j < 4; j++) {
        det += (*m)[(j * 4) + 0] * cofactors[0][j];
    }
    
    float inv_det = 1.0f / det;
    for (unsigned int i = 0; i < 4; i++) {
        for (unsigned int j = 0; j < 4; j++) {
            (*out)[(i * 4) + j] = cofactors[i][j] * inv_det;
        }
    }
}
void mat4f_transpose(mat4f *m, mat4f *out) {
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            (*out)[r * 4 + c] = (*m)[c * 4 + r];
        }
    }
}
