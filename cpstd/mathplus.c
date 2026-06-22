#include <mathplus.h>

int vec2f_cmp(vec2f a, vec2f b) { return a.x == b.x && a.y == b.y; }

vec2f vec2f_add(vec2f a, vec2f b) { return (vec2f){a.x + b.x, a.y + b.y}; }
vec2f vec2f_sub(vec2f a, vec2f b) { return (vec2f){a.x - b.x, a.y - b.y}; }
vec2f vec2f_mul(vec2f a, vec2f b) { return (vec2f){a.x * b.x, a.y * b.y}; }
vec2f vec2f_div(vec2f a, vec2f b) { return (vec2f){a.x / b.x, a.y / b.y}; }

vec2f vec2f_float_add(vec2f a, float b) { return (vec2f){a.x + b, a.y + b}; }
vec2f vec2f_float_sub(vec2f a, float b) { return (vec2f){a.x - b, a.y - b}; }
vec2f vec2f_float_mul(vec2f a, float b) { return (vec2f){a.x * b, a.y * b}; }
vec2f vec2f_float_div(vec2f a, float b) { return (vec2f){a.x / b, a.y / b}; }

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

float vec2f_dot(vec2f a, vec2f b) { return (a.x * b.x) + (a.y * b.y); }

float vec2f_length(vec2f a) { return sqrtf((a.x * a.x) + (a.y * a.y)); }

vec2f vec2f_clamp(vec2f v, vec2f n, vec2f m) {
    return (vec2f){math_clamp(v.x, n.x, m.x), math_clamp(v.y, n.y, m.y)};
}

vec2f vec2f_norm(vec2f v) {
    return (vec2f){v.x / sqrtf((v.x * v.x) + (v.y * v.y)),
                   v.y / sqrtf((v.x * v.x) + (v.y * v.y))};
}

void mat4f_identity(mat4f *m) {
    for (unsigned int j = 0; j < 4; j++) {
        for (unsigned int i = 0; i < 4; i++) {
            m->data[i][j] = i == j ? 1.0f : 0.0f;
        }
    }
}

void mat4f_translate(mat4f *m, vec3f *v) {
    m->data[3][0] += (m->data[0][0] * v->x) + (m->data[1][0] * v->y) +
                     (m->data[2][0] * v->z);
    m->data[3][1] += (m->data[0][1] * v->x) + (m->data[1][1] * v->y) +
                     (m->data[2][1] * v->z);
    m->data[3][2] += (m->data[0][2] * v->x) + (m->data[1][2] * v->y) +
                     (m->data[2][2] * v->z);
    m->data[3][3] += (m->data[0][3] * v->x) + (m->data[1][3] * v->y) +
                     (m->data[2][3] * v->z);
}

void mat4f_rotate(mat4f *m, float angle_rad, vec3f *axis) {
    float c = cosf(angle_rad);
    float s = sinf(angle_rad);
    float t = 1.0f - c;

    float x = axis->x;
    float y = axis->y;
    float z = axis->z;

    mat4f rot;
    mat4f_identity(&rot);

    rot.data[0][0] = (t * x * x) + c;
    rot.data[0][1] = (t * x * y) + (s * z);
    rot.data[0][2] = (t * x * z) - (s * y);

    rot.data[1][0] = (t * x * y) - (s * z);
    rot.data[1][1] = (t * y * y) + c;
    rot.data[1][2] = (t * y * z) + (s * x);

    rot.data[2][0] = (t * x * z) + (s * y);
    rot.data[2][1] = (t * y * z) - (s * x);
    rot.data[2][2] = (t * z * z) + c;

    mat4f result;
    mat4f_identity(&result);
    for (unsigned int col = 0; col < 4; col++) {
        for (unsigned int row = 0; row < 4; row++) {
            float sum = 0.0f;
            for (unsigned int k = 0; k < 4; k++) {
                sum += m->data[k][row] * rot.data[col][k];
            }
            result.data[col][row] = sum;
        }
    }
    *m = result;
}

void mat4f_scale(mat4f *m, vec3f *v) {
    m->data[0][0] *= v->x;
    m->data[1][1] *= v->y;
    m->data[2][2] *= v->z;
}

vec4f mat4f_mul_vec4f(mat4f *m, vec4f v) {
    vec4f out;
    for (unsigned int i = 0; i < 4; i++) {
        out.data[i] = (m->data[i][0] * v.data[0]) +
                      (m->data[i][1] * v.data[1]) +
                      (m->data[i][2] * v.data[2]) + (m->data[i][3] * v.data[3]);
    }
    return out;
}

void mat4f_mul(mat4f *a, mat4f *b, mat4f *dest) {
    mat4f_identity(dest);
    for (unsigned int col = 0; col < 4; col++) {
        for (unsigned int row = 0; row < 4; row++) {
            float sum = 0.0f;
            for (unsigned int k = 0; k < 4; k++) {
                sum += a->data[k][row] * b->data[col][k];
            }
            dest->data[col][row] = sum;
        }
    }
}

void mat4f_ortho(mat4f *m, float left, float right, float bottom, float top,
                 float near, float far) {
    mat4f_identity(m);
    m->data[0][0] = 2.0f / (right - left);
    m->data[1][1] = 2.0f / (top - bottom);
    m->data[2][2] = -2.0f / (far - near);
    m->data[3][0] = -(right + left) / (right - left);
    m->data[3][1] = -(top + bottom) / (top - bottom);
    m->data[3][2] = -(far + near) / (far - near);
}

static float minor_mat3f_det(float data[4][4], unsigned int r, unsigned int c) {
    float sub[3][3];
    unsigned int si = 0;
    for (int i = 0; i < 4; i++) {
        if (i == r) {
            continue;
        }
        unsigned int sj = 0;
        for (unsigned int j = 0; j < 4; j++) {
            if (j == c) {
                continue;
            }
            sub[si][sj++] = data[i][j];
        }
        si++;
    }
    return (sub[0][0] * (sub[1][1] * sub[2][2] - sub[1][2] * sub[2][1])) -
           (sub[0][1] * (sub[1][0] * sub[2][2] - sub[1][2] * sub[2][0])) +
           (sub[0][2] * (sub[1][0] * sub[2][1] - sub[1][1] * sub[2][0]));
}

float mat4f_det(mat4f *m) {
    float det = 0.0f;
    for (unsigned int j = 0; j < 4; j++) {
        float cofactor = minor_mat3f_det(m->data, 0, j);
        if (j % 2 != 0) {
            cofactor = -cofactor;
        }
        det += m->data[0][j] * cofactor;
    }
    return det;
}

void mat4f_inv(mat4f *m, mat4f *out) {
    float cofactors[4][4];
    for (unsigned int i = 0; i < 4; i++) {
        for (unsigned int j = 0; j < 4; j++) {
            float c = minor_mat3f_det(m->data, i, j);
            if ((i + j) % 2 != 0) {
                c = -c;
            }
            cofactors[i][j] = c;
        }
    }
    float det = 0.0f;
    for (unsigned int j = 0; j < 4; j++) {
        det += m->data[0][j] * cofactors[0][j];
    }
    float inv_det = 1.0f / det;
    for (unsigned int i = 0; i < 4; i++) {
        for (unsigned int j = 0; j < 4; j++) {
            out->data[i][j] = cofactors[j][i] * inv_det;
        }
    }
}
