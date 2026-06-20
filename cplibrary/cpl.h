#pragma once

#define _GNU_SOURCE

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <malloc.h>
#include <pthread.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#ifdef CPL_IMPLEMENTATION
#define CPM_IMPL
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define MINIAUDIO_IMPLEMENTATION
#define ENET_IMPLEMENTATION
#endif

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <emscripten/html5.h>
#endif

#include "stb_image.h"
#include <ft2build.h>
#include FT_FREETYPE_H
#include "stb_image_write.h"
#include <enet.h>
#include <miniaudio.h>

#include "../cpstd/cpmath.h"
#include "../cpstd/cpvec.h"

// {{{ Key Inputs

#define MOUSE_BUTTON_1 0
#define MOUSE_BUTTON_2 1
#define MOUSE_BUTTON_3 2
#define MOUSE_BUTTON_4 3
#define MOUSE_BUTTON_5 4
#define MOUSE_BUTTON_6 5
#define MOUSE_BUTTON_7 6
#define MOUSE_BUTTON_8 7
#define MOUSE_BUTTON_LAST MOUSE_BUTTON_8
#define MOUSE_BUTTON_LEFT MOUSE_BUTTON_1
#define MOUSE_BUTTON_RIGHT MOUSE_BUTTON_2
#define MOUSE_BUTTON_MIDDLE MOUSE_BUTTON_3

#define KEY_SPACE 32
#define KEY_APOSTROPHE 39
#define KEY_COMMA 44
#define KEY_MINUS 45
#define KEY_PERIOD 46
#define KEY_SLASH 47
#define KEY_0 48
#define KEY_1 49
#define KEY_2 50
#define KEY_3 51
#define KEY_4 52
#define KEY_5 53
#define KEY_6 54
#define KEY_7 55
#define KEY_8 56
#define KEY_9 57
#define KEY_SEMICOLON 59
#define KEY_EQUAL 61
#define KEY_A 65
#define KEY_B 66
#define KEY_C 67
#define KEY_D 68
#define KEY_E 69
#define KEY_F 70
#define KEY_G 71
#define KEY_H 72
#define KEY_I 73
#define KEY_J 74
#define KEY_K 75
#define KEY_L 76
#define KEY_M 77
#define KEY_N 78
#define KEY_O 79
#define KEY_P 80
#define KEY_Q 81
#define KEY_R 82
#define KEY_S 83
#define KEY_T 84
#define KEY_U 85
#define KEY_V 86
#define KEY_W 87
#define KEY_X 88
#define KEY_Y 89
#define KEY_Z 90
#define KEY_LEFT_BRACKET 91
#define KEY_BACKSLASH 92
#define KEY_RIGHT_BRACKET 93
#define KEY_GRAVE_ACCENT 96
#define KEY_WORLD_1 161
#define KEY_WORLD_2 162
#define KEY_ESCAPE 256
#define KEY_ENTER 257
#define KEY_TAB 258
#define KEY_BACKSPACE 259
#define KEY_INSERT 260
#define KEY_DELETE 261
#define KEY_RIGHT 262
#define KEY_LEFT 263
#define KEY_DOWN 264
#define KEY_UP 265
#define KEY_PAGE_UP 266
#define KEY_PAGE_DOWN 267
#define KEY_HOME 268
#define KEY_END 269
#define KEY_CAPS_LOCK 280
#define KEY_SCROLL_LOCK 281
#define KEY_NUM_LOCK 282
#define KEY_PRINT_SCREEN 283
#define KEY_PAUSE 284
#define KEY_F1 290
#define KEY_F2 291
#define KEY_F3 292
#define KEY_F4 293
#define KEY_F5 294
#define KEY_F6 295
#define KEY_F7 296
#define KEY_F8 297
#define KEY_F9 298
#define KEY_F10 299
#define KEY_F11 300
#define KEY_F12 301
#define KEY_F13 302
#define KEY_F14 303
#define KEY_F15 304
#define KEY_F16 305
#define KEY_F17 306
#define KEY_F18 307
#define KEY_F19 308
#define KEY_F20 309
#define KEY_F21 310
#define KEY_F22 311
#define KEY_F23 312
#define KEY_F24 313
#define KEY_F25 314
#define KEY_KP_0 320
#define KEY_KP_1 321
#define KEY_KP_2 322
#define KEY_KP_3 323
#define KEY_KP_4 324
#define KEY_KP_5 325
#define KEY_KP_6 326
#define KEY_KP_7 327
#define KEY_KP_8 328
#define KEY_KP_9 329
#define KEY_KP_DECIMAL 330
#define KEY_KP_DIVIDE 331
#define KEY_KP_MULTIPLY 332
#define KEY_KP_SUBTRACT 333
#define KEY_KP_ADD 334
#define KEY_KP_ENTER 335
#define KEY_KP_EQUAL 336
#define KEY_LEFT_SHIFT 340
#define KEY_LEFT_CONTROL 341
#define KEY_LEFT_ALT 342
#define KEY_LEFT_SUPER 343
#define KEY_RIGHT_SHIFT 344
#define KEY_RIGHT_CONTROL 345
#define KEY_RIGHT_ALT 346
#define KEY_RIGHT_SUPER 347
#define KEY_MENU 348
#define KEY_LAST GLFW_KEY_MENU

// }}}

// {{{ OpenGL Versions

#define OPENGL_VER_1_0 10
#define OPENGL_VER_2_0 20
#define OPENGL_VER_3_0 30
#define OPENGL_VER_3_3 33
#define OPENGL_VER_4_0 40
#define OPENGL_VER_4_1 41
#define OPENGL_VER_4_2 42
#define OPENGL_VER_4_3 43
#define OPENGL_VER_4_4 44
#define OPENGL_VER_4_5 45
#define OPENGL_VER_4_6 46

// }}}

// {{{ Colors

typedef vec4f color;

#define RGB(r, g, b) (color){r, g, b, 255}
#define RGBA(r, g, b, a)                                                       \
    (color) { r, g, b, a }

#define RGB_NORM(r, g, b) (color){(r) * 255, (g) * 255, (b) * 255, 255}
#define RGBA_NORM(r, g, b, a)                                                  \
    (color){(r) * 255, (g) * 255, (b) * 255, (a) * 255}

#define WHITE RGB(255, 255, 255)
#define BLACK RGB(0, 0, 0)
#define RED RGB(255, 0, 0)
#define ORANGE RGB(255, 127, 0)
#define YELLOW RGB(255, 255, 0)
#define LIME_GREEN RGB(0, 255, 0)
#define GREEN RGB(0, 150, 25)
#define BLUE RGB(0, 0, 255)
#define LIGHT_BLUE RGB(0, 255, 255)
#define PURPLE RGB(127, 0, 255)
#define PINK RGB(255, 0, 255)
#define LIGHT_GRAY RGB(200, 200, 200)
#define DARK_GRAY RGB(64, 64, 64)
#define BROWN RGB(150, 76, 0)

// }}}

#ifdef __cplusplus
namespace cpl {
extern "C" {
#endif

// {{{ Logging

typedef enum { LOG_INFO, LOG_WARN, LOG_ERR, LOG_NONE } cpl_log_level;

static void cpl_log(cpl_log_level level, char *msg, ...) {
    va_list args;
    va_start(args, msg);
    switch (level) {
    case LOG_INFO:
        printf("[CPL] [INFO]: ");
        break;
    case LOG_WARN:
        printf("[CPL] [WARNING]: ");
        break;
    case LOG_ERR:
        fprintf(stderr, "[CPL] [ERROR]: ");
        break;
    case LOG_NONE:
        break;
    }
    while ((*msg) != '\0') {
        if ((*msg) == '%') {
            msg++;
            switch ((*msg)) {
            case 'c': {
                int c = va_arg(args, int);
                putchar(c);
                break;
            }
            case 'i': {
                int i = va_arg(args, int);
                if (i < 0) {
                    putchar('-');
                    i = -i;
                }
                if (i == 0) {
                    putchar('0');
                    break;
                }
                if (i / 10) {
                    cpl_log(LOG_NONE, "%i", i / 10);
                }
                putchar((i % 10) + '0');
                break;
            }
            case 's': {
                char *s = va_arg(args, char *);
                fputs(s, stdout);
                break;
            }
            default:
                break;
            }
        } else {
            putchar(*msg);
        }
        msg++;
    }
    va_end(args);
    printf("\n");
}

// }}}

// {{{ Screenshot

static void screenshot(char *path, vec2f screen) {
    static int screenshots_taken = 0;
    int w = (int)screen.x;
    int h = (int)screen.y;
    int s = w * 3;
    u8 pixels[w * h * 3];
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glReadPixels(0, 0, w, h, GL_RGB, GL_UNSIGNED_BYTE, pixels);
    for (int y = 0; y < h / 2; y++) {
        for (int x = 0; x < s; x++) {
            u8 tmp = pixels[(y * s) + x];
            pixels[(y * s) + x] = pixels[((h - 1 - y) * s) + x];
            pixels[((h - 1 - y) * s) + x] = tmp;
        }
    }
    char final[100];
    snprintf(final, sizeof(final), "%sscreenshot%d.png", path,
             screenshots_taken);
    stbi_write_png(final, w, h, 3, pixels, s);
    screenshots_taken++;
}

// }}}

// {{{ Profiler

static unsigned int get_heap_size() {
#ifndef __EMSCRIPTEN__
    struct mallinfo2 mi = mallinfo2();
    return mi.arena;
#else
    return 0;
#endif
}

static unsigned int get_heap_used() {
#ifndef __EMSCRIPTEN__
    struct mallinfo2 mi = mallinfo2();
    return mi.uordblks;
#else
    return 0;
#endif
}

static unsigned int get_heap_free() {
#ifndef __EMSCRIPTEN__
    struct mallinfo2 mi = mallinfo2();
    return mi.fordblks;
#else
    return 0;
#endif
}

static unsigned int get_stack_size() {
#ifndef __EMSCRIPTEN__
    pthread_attr_t attr;
    pthread_getattr_np(pthread_self(), &attr);
    size_t size = 0;
    pthread_attr_getstacksize(&attr, &size);
    pthread_attr_destroy(&attr);
    return size;
#else
    return 0;
#endif
}

static unsigned int get_stack_used() {
#ifndef __EMSCRIPTEN__
    pthread_attr_t attr;
    pthread_getattr_np(pthread_self(), &attr);
    void *base = NULLPTR;
    size_t size = 0;
    pthread_attr_getstack(&attr, &base, &size);
    pthread_attr_destroy(&attr);
    char marker;
    void *cur = &marker;
    return (unsigned int)(base + size - cur);
#else
    return 0;
#endif
}

// }}}

// {{{ OpenGL Debug

static GLenum _check_gl_error(char *path, unsigned int line) {
    GLenum errorCode;
    while ((errorCode = glGetError()) != GL_NO_ERROR) {
        char *error;
        switch (errorCode) {
        case GL_INVALID_ENUM:
            error = "INVALID_ENUM";
            break;
        case GL_INVALID_VALUE:
            error = "INVALID_VALUE";
            break;
        case GL_INVALID_OPERATION:
            error = "INVALID_OPERATION";
            break;
        case GL_STACK_OVERFLOW:
            error = "STACK_OVERFLOW";
            break;
        case GL_STACK_UNDERFLOW:
            error = "STACK_UNDERFLOW";
            break;
        case GL_OUT_OF_MEMORY:
            error = "OUT_OF_MEMORY";
            break;
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            error = "INVALID_FRAMEBUFFER_OPERATION";
            break;
        default:
            error = "UNKNOWN";
            break;
        }
        fprintf(stderr, "[CPL] [ERROR] %s | %s (%d)\n", error, path, line);
    }
    return errorCode;
}

static void check_opengl_error() { _check_gl_error(__FILE__, __LINE__); }

static void APIENTRY _gl_debug_out(GLenum src, GLenum type, unsigned int id,
                                   GLenum severity,
                                   [[maybe_unused]] GLsizei len,
                                   const char *msg,
                                   [[maybe_unused]] const void *usr_prog) {
    if (id == 131169 || id == 131185 || id == 131218 || id == 131204) {
        return;
    }

    fprintf(stderr, "[CPL] [ERROR](%d) %s\n", id, msg);

    fprintf(stderr, "->");
    switch (src) {
    case GL_DEBUG_SOURCE_API:
        fprintf(stderr, "Source: API");
        break;
    case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
        fprintf(stderr, "Source: Window System");
        break;
    case GL_DEBUG_SOURCE_SHADER_COMPILER:
        fprintf(stderr, "Source: Shader Compiler");
        break;
    case GL_DEBUG_SOURCE_THIRD_PARTY:
        fprintf(stderr, "Source: Third Party");
        break;
    case GL_DEBUG_SOURCE_APPLICATION:
        fprintf(stderr, "Source: Application");
        break;
    case GL_DEBUG_SOURCE_OTHER:
        fprintf(stderr, "Source: Other");
        break;
    default:
        fprintf(stderr, "Source: ???");
        break;
    }
    fprintf(stderr, "\n");

    fprintf(stderr, "->");
    switch (type) {
    case GL_DEBUG_TYPE_ERROR:
        fprintf(stderr, "Type: Error");
        break;
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
        fprintf(stderr, "Type: Deprecated Behaviour");
        break;
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
        fprintf(stderr, "Type: Undefined Behaviour");
        break;
    case GL_DEBUG_TYPE_PORTABILITY:
        fprintf(stderr, "Type: Portability");
        break;
    case GL_DEBUG_TYPE_PERFORMANCE:
        fprintf(stderr, "Type: Performance");
        break;
    case GL_DEBUG_TYPE_MARKER:
        fprintf(stderr, "Type: Marker");
        break;
    case GL_DEBUG_TYPE_PUSH_GROUP:
        fprintf(stderr, "Type: Push Group");
        break;
    case GL_DEBUG_TYPE_POP_GROUP:
        fprintf(stderr, "Type: Pop Group");
        break;
    case GL_DEBUG_TYPE_OTHER:
        fprintf(stderr, "Type: Other");
        break;
    default:
        fprintf(stderr, "Type: ???");
        break;
    }
    fprintf(stderr, "\n");

    fprintf(stderr, "->");
    switch (severity) {
    case GL_DEBUG_SEVERITY_HIGH:
        fprintf(stderr, "Severity: HIGH");
        break;
    case GL_DEBUG_SEVERITY_MEDIUM:
        fprintf(stderr, "Severity: MEDIUM");
        break;
    case GL_DEBUG_SEVERITY_LOW:
        fprintf(stderr, "Severity: LOW");
        break;
    case GL_DEBUG_SEVERITY_NOTIFICATION:
        fprintf(stderr, "Severity: NOTIFICTAION");
        break;
    default:
        fprintf(stderr, "Severity: ???");
    }
    fprintf(stderr, "\n");
    fprintf(stderr, "\n");
}

static void enable_opengl_debug() {
    int flags = 0;
    glGetIntegerv(GL_CONTEXT_FLAGS, &flags);

    if (flags & GL_CONTEXT_FLAG_DEBUG_BIT) {
        GLint major = 0;
        GLint minor = 0;
        glGetIntegerv(GL_MAJOR_VERSION, &major);
        glGetIntegerv(GL_MINOR_VERSION, &minor);
        if (major < 4 || (major == 4 && minor < 3)) {
            cpl_log(LOG_WARN, "OpenGL version is older than 4.3 - OpenGL debug "
                              "output disabled!");
            return;
        }

        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(_gl_debug_out, NULLPTR);
        glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0,
                              NULLPTR, GL_TRUE);
    }
}

// }}}

// {{{ Shader

typedef struct {
    unsigned int id;
} shader;

static bool _check_shader_compile_errors(unsigned int shader, char *type) {
    int success = 0;
    char info_cpl_log[1024];

    if (strcmp(type, "PROGRAM") == 0) {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shader, 1024, NULLPTR, info_cpl_log);
            cpl_log(LOG_ERR, "[CPL] [ERROR] Program linking error:\n%s\n",
                    info_cpl_log);
            return false;
        }
    } else {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 1024, NULLPTR, info_cpl_log);
            cpl_log(LOG_ERR, "[CPL] [ERROR] Shader compilation error: %s\n%s\n",
                    type, info_cpl_log);
            return false;
        }
    }
    return true;
}

static char *_read_shader_file(char *path) {
    FILE *f = fopen(path, "rb");
    if (!f) {
        return NULLPTR;
    }

    fseek(f, 0, SEEK_END);
    unsigned int size = ftell(f);
    fseek(f, 0, SEEK_SET);

    char *buffer = malloc(size + 1);
    if (!buffer) {
        fclose(f);
        return NULLPTR;
    }

    unsigned int read = fread(buffer, 1, size, f);
    fclose(f);

    if (read != size) {
        free(buffer);
        return NULLPTR;
    }

    buffer[size] = '\0';
    return buffer;
}

static void create_shader(shader *s, char *vert_path, char *frag_path) {
    char *vert_code = _read_shader_file(vert_path);
    char *frag_code = _read_shader_file(frag_path);

    unsigned int vert = 0;
    unsigned int frag = 0;
    vert = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vert, 1, (const GLchar *const *)&vert_code, NULLPTR);
    glCompileShader(vert);
    _check_shader_compile_errors(vert, "VERTEX");
    frag = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(frag, 1, (const GLchar *const *)&frag_code, NULLPTR);
    glCompileShader(frag);
    _check_shader_compile_errors(frag, "FRAGMENT");
    s->id = glCreateProgram();
    glAttachShader(s->id, vert);
    glAttachShader(s->id, frag);
    glLinkProgram(s->id);
    _check_shader_compile_errors(s->id, "PROGRAM");

    free(vert_code);
    free(frag_code);
    glDeleteShader(vert);
    glDeleteShader(frag);
}

static void use_shader(shader *s) { glUseProgram(s->id); }

static void shader_set_bool(shader *s, char *name, bool val) {
    glUniform1i(glGetUniformLocation(s->id, name), val);
}

static void shader_set_int(shader *s, char *name, int val) {
    glUniform1i(glGetUniformLocation(s->id, name), val);
}

static void shader_set_float(shader *s, char *name, float val) {
    glUniform1f(glGetUniformLocation(s->id, name), val);
}

static void shader_set_rgba(shader *s, char *name, vec4f c) {
    glUniform4f(glGetUniformLocation(s->id, name), c.r / 255.0f, c.g / 255.0f,
                c.b / 255.0f, c.a / 255.0f);
}

static void shader_set_mat4f(shader *s, char *name, mat4f mat) {
    glUniformMatrix4fv(glGetUniformLocation(s->id, name), 1, GL_FALSE,
                       (const GLfloat *)mat.data);
}

static void shader_set_vec2f(shader *s, char *name, vec2f v) {
    glUniform2f(glGetUniformLocation(s->id, name), v.x, v.y);
}

static void shader_set_vec3f(shader *s, char *name, vec3f v) {
    glUniform3f(glGetUniformLocation(s->id, name), v.x, v.y, v.z);
}

// }}}

// {{{ Rectangle

typedef struct {
    vec2f pos;
    vec2f size;
    vec4f color;
    float rot;
    unsigned int vbo, vao, ebo;
} rect;

static void create_rect(rect *r, vec2f pos, vec2f size, vec4f color,
                        float rot) {
    r->pos = pos;
    r->size = size;
    r->color = color;
    r->rot = rot;

    float vertices[12] = {
        size.x, 0.0f,   0.0f, //
        size.x, size.y, 0.0f, //
        0.0f,   size.y, 0.0f, //
        0.0f,   0.0f,   0.0f  //
    };
    unsigned int indices[6] = {
        0, 1, 3, //
        1, 2, 3  //
    };

    glGenVertexArrays(1, &r->vao);
    glGenBuffers(1, &r->vbo);
    glGenBuffers(1, &r->ebo);
    glBindVertexArray(r->vao);
    glBindBuffer(GL_ARRAY_BUFFER, r->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, r->ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
                 GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                          (void *)NULLPTR);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

static void destroy_rect(rect *r) {
    if (r->vao != 0 && glIsVertexArray(r->vao)) {
        glDeleteVertexArrays(1, &r->vao);
        r->vao = 0;
    }
    if (r->vbo != 0 && glIsBuffer(r->vbo)) {
        glDeleteBuffers(1, &r->vbo);
        r->vbo = 0;
    }
    if (r->ebo != 0 && glIsBuffer(r->ebo)) {
        glDeleteBuffers(1, &r->ebo);
        r->ebo = 0;
    }
}

static void draw_rect_raw(shader *s, rect *r) {
    mat4f transform;
    mat4f_identity(&transform);

    mat4f_translate(&transform, &(vec3f){r->pos.x, r->pos.y, 0.0f});
    mat4f_translate(&transform,
                    &(vec3f){r->size.x * 0.5f, r->size.y * 0.5f, 0.0f});
    mat4f_rotate(&transform, cpm_rad(r->rot), &(vec3f){0.0f, 0.0f, 1.0f});
    mat4f_translate(&transform,
                    &(vec3f){-r->size.x * 0.5f, -r->size.y * 0.5f, 0.0f});

    shader_set_mat4f(s, "transform", transform);
    shader_set_rgba(s, "input_color", r->color);

    glBindVertexArray(r->vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULLPTR);
    glBindVertexArray(0);
}

// }}}

// {{{ Triangle

typedef struct {
    vec2f pos;
    vec2f size;
    vec4f color;
    float rot;
    unsigned int vbo, vao;
} triangle;

static void create_triangle(triangle *t, vec2f pos, vec2f size, vec4f color,
                            float rot) {
    t->pos = pos;
    t->size = size;
    t->color = color;
    t->rot = rot;

    float vertices[9] = {
        0.0f,          0.0f,   0.0f, //
        size.x,        0.0f,   0.0f, //
        size.x / 2.0f, size.y, 0.0f  //
    };

    glGenVertexArrays(1, &t->vao);
    glGenBuffers(1, &t->vbo);
    glBindVertexArray(t->vao);
    glBindBuffer(GL_ARRAY_BUFFER, t->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                          (void *)NULLPTR);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

static void destroy_triangle(triangle *t) {
    if (t->vao != 0 && glIsVertexArray(t->vao)) {
        glDeleteVertexArrays(1, &t->vao);
        t->vao = 0;
    }
    if (t->vbo != 0 && glIsBuffer(t->vbo)) {
        glDeleteBuffers(1, &t->vbo);
        t->vbo = 0;
    }
}

static void draw_triangle_raw(shader *s, triangle *t) {
    mat4f transform;
    mat4f_identity(&transform);

    mat4f_translate(&transform, &(vec3f){t->pos.x, t->pos.y, 0.0f});
    mat4f_translate(&transform,
                    &(vec3f){t->size.x * 0.5f, t->size.y * 0.5f, 0.0f});
    mat4f_rotate(&transform, cpm_rad(t->rot), &(vec3f){0.0f, 0.0f, 1.0f});
    mat4f_translate(&transform,
                    &(vec3f){-t->size.x * 0.5f, -t->size.y * 0.5f, 0.0f});

    shader_set_mat4f(s, "transform", transform);
    shader_set_rgba(s, "input_color", t->color);

    glBindVertexArray(t->vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}

// }}}

// {{{ Circle

typedef struct {
    vec2f pos;
    float radius;
    vec4f color;
    unsigned int vao, vbo;
    int vertex_cnt;
} circle;

static void create_circle(circle *c, vec2f pos, float radius, vec4f color) {
    c->pos = pos;
    c->color = color;
    c->radius = radius;

    int segments = CPM_MIN(32, (int)cpm_ceilf(2.0f * CPM_PI * radius / 2.0f));
    u64 vertices_size = ((u64)(segments + 1) * 3) + 3;
    float *vertices = malloc(vertices_size * sizeof(float));
    for (unsigned int i = 0; i < 3; i++) {
        vertices[i] = 0;
    }
    for (unsigned int i = 0; i <= segments; i++) {
        float theta = 2 * CPM_PI / (float)segments * (float)i;
        float x = 0.0f + (radius * cpm_cosf(theta));
        float y = 0.0f + (radius * cpm_sinf(theta));
        vertices[(u64)(i + 1) * 3] = x;
        vertices[((i + 1) * 3) + 1] = y;
        vertices[((i + 1) * 3) + 2] = 0.0f;
    }
    c->vertex_cnt = (int)(vertices_size / 3);
    glGenVertexArrays(1, &c->vao);
    glGenBuffers(1, &c->vbo);
    glBindVertexArray(c->vao);
    glBindBuffer(GL_ARRAY_BUFFER, c->vbo);
    glBufferData(GL_ARRAY_BUFFER, (int)(vertices_size * sizeof(float)),
                 vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                          (void *)NULLPTR);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    free(vertices);
}

static void destroy_circle(circle *c) {
    if (c->vao != 0 && glIsVertexArray(c->vao)) {
        glDeleteVertexArrays(1, &c->vao);
        c->vao = 0;
    }
    if (c->vbo != 0 && glIsBuffer(c->vbo)) {
        glDeleteBuffers(1, &c->vbo);
        c->vbo = 0;
    }
}

static void draw_circle_raw(shader *s, circle *c) {
    mat4f transform;
    mat4f_identity(&transform);
    mat4f_translate(&transform, &(vec3f){c->pos.x, c->pos.y, 0.0f});

    shader_set_mat4f(s, "transform", transform);
    shader_set_rgba(s, "input_color", c->color);

    glBindVertexArray(c->vao);
    glDrawArrays(GL_TRIANGLE_FAN, 0, c->vertex_cnt);
    glBindVertexArray(0);
}

// }}}

// {{{ Line

typedef struct {
    vec2f start, end;
    vec4f color;
    unsigned int vao, vbo;
} line;

static void create_line(line *l, vec2f start, vec2f end, vec4f color) {
    l->start = start;
    l->end = end;
    l->color = color;

    float vertices[6] = {
        start.x, start.y, 0.0f, //
        end.x,   end.y,   0.0f, //
    };

    glGenVertexArrays(1, &l->vao);
    glGenBuffers(1, &l->vbo);
    glBindVertexArray(l->vao);
    glBindBuffer(GL_ARRAY_BUFFER, l->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                          (void *)NULLPTR);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
static void destroy_line(line *l) {
    if (l->vao != 0 && glIsVertexArray(l->vao)) {
        glDeleteVertexArrays(1, &l->vao);
        l->vao = 0;
    }
    if (l->vbo != 0 && glIsBuffer(l->vbo)) {
        glDeleteBuffers(1, &l->vbo);
        l->vbo = 0;
    }
}

static void draw_line_raw(shader *s, line *l) {
    mat4f transform;
    mat4f_identity(&transform);
    mat4f_translate(&transform, &(vec3f){0.0f, 0.0f, 0.0f});

    shader_set_mat4f(s, "transform", transform);
    shader_set_rgba(s, "input_color", l->color);
    glBindVertexArray(l->vao);
    glDrawArrays(GL_LINES, 0, 2);
    glBindVertexArray(0);
}

// }}}

// {{{ Texture & Texture2D

typedef enum { FILTER_LINEAR, FILTER_NEAREST } texture_filtering;

typedef struct {
    unsigned int id;
    vec2f size;
} texture;
typedef struct {
    vec2f pos;
    vec2f size;
    float rot;
    vec4f color;
    texture *tex;
    unsigned int vbo, vao, ebo;
} texture2D;

static void load_texture(texture *t, char *path, texture_filtering filter) {
    glGenTextures(1, &t->id);
    glBindTexture(GL_TEXTURE_2D, t->id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    filter == FILTER_LINEAR ? GL_LINEAR : GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                    filter == FILTER_LINEAR ? GL_LINEAR : GL_NEAREST);
    stbi_set_flip_vertically_on_load(1);
    int width = 0;
    int height = 0;
    int channels = 0;
    u8 *data = stbi_load(path, &width, &height, &channels, 0);
    GLenum format = 0;
    if (channels == 1) {
        format = GL_RED;
    } else if (channels == 3) {
        format = GL_RGB;
    } else if (channels == 4) {
        format = GL_RGBA;
    }
    if (data) {
        t->size.x = (float)width;
        t->size.y = (float)height;
        glTexImage2D(GL_TEXTURE_2D, 0, (int)format, (int)t->size.x,
                     (int)t->size.y, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        cpl_log(LOG_ERR, "Failed to load texture");
    }
    stbi_image_free(data);
}

static void unload_texture(texture *t) {
    if (t->id != 0) {
        glDeleteTextures(1, &t->id);
    }
}

static void create_texture2D(texture2D *t, vec2f pos, vec2f size, float rot,
                             vec4f color, texture *tex) {
    t->pos = pos;
    t->size = size;
    t->rot = rot;
    t->color = color;
    t->tex = tex;

    float vertices[22] = {
        size.x, 0.0f,   0.0f, 1.0f, 1.0f, //
        size.x, size.y, 0.0f, 1.0f, 0.0f, //
        0.0f,   size.y, 0.0f, 0.0f, 0.0f, //
        0.0f,   0.0f,   0.0f, 0.0f, 1.0f  //
    };
    unsigned int indices[6] = {
        0, 1, 3, //
        1, 2, 3  //
    };

    glGenVertexArrays(1, &t->vao);
    glGenBuffers(1, &t->vbo);
    glGenBuffers(1, &t->ebo);
    glBindVertexArray(t->vao);
    glBindBuffer(GL_ARRAY_BUFFER, t->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, t->ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
                 GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
                          (void *)NULLPTR);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
                          (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

static void destroy_texture2D(texture2D *t) {
    if (t->vao != 0 && glIsVertexArray(t->vao)) {
        glDeleteVertexArrays(1, &t->vao);
        t->vao = 0;
    }
    if (t->vbo != 0 && glIsBuffer(t->vbo)) {
        glDeleteBuffers(1, &t->vbo);
        t->vbo = 0;
    }
    if (t->ebo != 0 && glIsBuffer(t->ebo)) {
        glDeleteBuffers(1, &t->ebo);
        t->ebo = 0;
    }
    t->tex = NULLPTR;
}

static void draw_texture2D_raw(shader *s, texture2D *t) {
    mat4f transform;
    mat4f_identity(&transform);

    mat4f_translate(&transform, &(vec3f){t->pos.x, t->pos.y, 0.0f});
    mat4f_translate(&transform,
                    &(vec3f){t->size.x * 0.5f, t->size.y * 0.5f, 0.0f});
    mat4f_rotate(&transform, cpm_rad(t->rot), &(vec3f){0.0f, 0.0f, 1.0f});
    mat4f_translate(&transform,
                    &(vec3f){-t->size.x * 0.5f, -t->size.y * 0.5f, 0.0f});

    shader_set_int(s, "tex", 0);
    shader_set_mat4f(s, "transform", transform);
    shader_set_rgba(s, "input_color", t->color);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, t->tex->id);
    glBindVertexArray(t->vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULLPTR);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

// }}}

// {{{ Text

typedef struct {
    unsigned int id;
    vec2f size;
    vec2f bearing;
    unsigned int advance;
} letter;

typedef struct {
    unsigned int vao, vbo;
    char *name;
    letter *letters;
} font;

static void create_font(font *f, char *path, char *name,
                        texture_filtering filter) {
    FT_Library ft;
    if (FT_Init_FreeType(&ft)) {
        cpl_log(LOG_ERR, "Could not init FreeType Library");
        exit(-1);
    }

    if (access(path, F_OK) == -1) {
        cpl_log(LOG_ERR, "Failed to load %s", name);
        exit(-1);
    }

    FT_Face face;
    if (FT_New_Face(ft, path, 0, &face)) {
        cpl_log(LOG_ERR, "Failed to load font");
        exit(-1);
    }
    FT_Set_Pixel_Sizes(face, 0, 48);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    f->letters = vec_init(f->letters, 128);
    for (u8 c = 0; c < 128; c++) {
        if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
            cpl_log(LOG_ERR, "Failed to load Glyph");
            continue;
        }

        unsigned int tex = 0;
        glGenTextures(1, &tex);
        glBindTexture(GL_TEXTURE_2D, tex);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_R8,
                     (GLsizei)face->glyph->bitmap.width,
                     (GLsizei)face->glyph->bitmap.rows, 0, GL_RED,
                     GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                        filter == FILTER_LINEAR ? GL_LINEAR : GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                        filter == FILTER_LINEAR ? GL_LINEAR : GL_NEAREST);

        letter character = {.id = tex,
                            .size = {(float)face->glyph->bitmap.width,
                                     (float)face->glyph->bitmap.rows},
                            .bearing = {(float)face->glyph->bitmap_left,
                                        (float)face->glyph->bitmap_top},
                            .advance = face->glyph->advance.x};
        vec_push(f->letters, character);
    }
    f->name = name;

    glBindTexture(GL_TEXTURE_2D, 0);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

    glGenVertexArrays(1, &f->vao);
    glGenBuffers(1, &f->vbo);
    glBindVertexArray(f->vao);
    glBindBuffer(GL_ARRAY_BUFFER, f->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULLPTR,
                 GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), NULLPTR);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    FT_Done_Face(face);
    FT_Done_FreeType(ft);
}

static void delete_font(font *f) {
    if (f->vao != 0 && glIsVertexArray(f->vao)) {
        glDeleteVertexArrays(1, &f->vao);
        f->vao = 0;
    }
    if (f->vbo != 0 && glIsBuffer(f->vbo)) {
        glDeleteBuffers(1, &f->vbo);
        f->vbo = 0;
    }
    for (unsigned int i = 0; i < vec_size(f->letters); i++) {
        glDeleteTextures(1, &f->letters[i].id);
    }
    vec_destroy(f->letters);
}

static void draw_text_raw(shader *s, font *f, char *text, vec2f pos,
                          float scale, vec4f color) {
    shader_set_vec3f(s, "text_color", (vec3f){color.r, color.g, color.b});
    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(f->vao);

    for (unsigned int i = 0; i < strlen(text); i++) {
        letter *l = &f->letters[text[i]];

        float x_pos = pos.x + (l->bearing.x * scale);
        float y_pos =
            pos.y + (f->letters['H'].bearing.y - l->bearing.y) * scale;
        float width = l->size.x * scale;
        float height = l->size.y * scale;

        float vertices[6][4] = {{x_pos, y_pos + height, 0.0f, 1.0f},
                                {x_pos, y_pos, 0.0f, 0.0f},
                                {x_pos + width, y_pos, 1.0f, 0.0f},

                                {x_pos, y_pos + height, 0.0f, 1.0f},
                                {x_pos + width, y_pos, 1.0f, 0.0f},
                                {x_pos + width, y_pos + height, 1.0f, 1.0f}};

        glBindTexture(GL_TEXTURE_2D, l->id);
        glBindBuffer(GL_ARRAY_BUFFER, f->vbo);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        pos.x += ((float)(l->advance >> 6)) * scale;
    }
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

static vec2f get_text_size(font *f, char *text, float scale) {
    float width = 0.0f;
    float height = 0.0f;
    float max_above_base = 0.0f;
    float max_below_base = 0.0f;

    for (unsigned int i = 0; i < strlen(text); i++) {

        letter *l = &f->letters[text[i]];
        float h = l->size.y * scale;
        max_above_base = CPM_MAX(max_above_base, l->bearing.y * scale);
        max_below_base = CPM_MAX(max_below_base, (h - (l->bearing.y * scale)));
        width += (float)(l->advance >> 6) * scale;
    }
    height = max_above_base + max_below_base;
    return (vec2f){width, height};
}

// }}}

// {{{ Audio

typedef struct {
    char *path;
    float volume;
    float pitch;
} audio;

static ma_engine _audio_engine;
static ma_sound *_music;
static ma_sound **_active_sounds;
static unsigned int _active_sounds_size;
static unsigned int _active_sounds_cap;

static void audio_init() {
    if (ma_engine_init(NULLPTR, &_audio_engine) != MA_SUCCESS) {
        cpl_log(LOG_ERR, "Failed to init audio!");
        exit(-1);
    }
    _active_sounds_cap = 16;
    _active_sounds_size = 0;
    _active_sounds = malloc(_active_sounds_cap * sizeof(ma_sound *));
    _music = NULLPTR;
}

static audio load_audio(char *path) { return (audio){path, 1.0f, 1.0f}; }

static void audio_update() {
    unsigned int w = 0;
    for (unsigned int i = 0; i < _active_sounds_size; i++) {
        if (ma_sound_is_playing(_active_sounds[i])) {
            _active_sounds[w++] = _active_sounds[i];
        } else {
            ma_sound_uninit(_active_sounds[i]);
            free(_active_sounds[i]);
        }
    }
    _active_sounds_size = w;
}

static void audio_play_sound(audio *a) {
    ma_sound *sound = malloc(sizeof(ma_sound));
    if (ma_sound_init_from_file(&_audio_engine, a->path, MA_SOUND_FLAG_DECODE,
                                NULLPTR, NULLPTR, sound) != MA_SUCCESS) {
        cpl_log(LOG_ERR, "Failed to init sound!");
        free(sound);
        return;
    }
    ma_sound_set_pitch(sound, a->pitch);
    ma_sound_set_volume(sound, a->volume);
    ma_sound_set_looping(sound, MA_FALSE);
    ma_sound_start(sound);

    if (_active_sounds_size >= _active_sounds_cap) {
        _active_sounds_cap *= 2;
        ma_sound **tmp =
            realloc(_active_sounds, _active_sounds_cap * sizeof(ma_sound *));
        if (!tmp) {
            cpl_log(LOG_ERR, "Realloc sounds failed!");
            return;
        }
        _active_sounds = tmp;
    }
    _active_sounds[_active_sounds_size++] = sound;
}

static void audio_play_music(audio *a) {
    if (_music) {
        ma_sound_stop(_music);
        ma_sound_uninit(_music);
        free(_music);
        _music = NULLPTR;
    }
    _music = malloc(sizeof(ma_sound));
    if (ma_sound_init_from_file(&_audio_engine, a->path, MA_SOUND_FLAG_DECODE,
                                NULLPTR, NULLPTR, _music) != MA_SUCCESS) {
        cpl_log(LOG_ERR, "Failed to load music!");
        free(_music);
        _music = NULLPTR;
        return;
    }
    ma_sound_set_pitch(_music, a->pitch);
    ma_sound_set_looping(_music, MA_TRUE);
    ma_sound_start(_music);
}

static void audio_pause_music() {
    if (_music) {
        ma_sound_stop(_music);
    }
}

static void audio_resume_music() {
    if (_music) {
        ma_sound_start(_music);
    }
}

static void audio_stop_music() {
    if (_music) {
        ma_sound_stop(_music);
        ma_sound_seek_to_pcm_frame(_music, 0);
    }
}

static void audio_close() {
    audio_update();
    free(_active_sounds);
    if (_music) {
        ma_sound_stop(_music);
        ma_sound_uninit(_music);
        free(_music);
    }
    ma_engine_uninit(&_audio_engine);
}

// }}}

// {{{ Screen Quad

typedef struct {
    vec2f size;
    unsigned int vbo, vao, rbo, framebuffer, tex_color_buffer;
} screen_quad;

static void create_screen_quad(screen_quad *q, int width, int height) {
    q->size = (vec2f){(float)width, (float)height};

    float vertices[30] = {-1.0f, 1.0f, 0.0f, 0.0f,  1.0f, -1.0f, -1.0f, 0.0f,
                          0.0f,  0.0f, 1.0f, -1.0f, 0.0f, 1.0f,  0.0f,

                          -1.0f, 1.0f, 0.0f, 0.0f,  1.0f, 1.0f,  -1.0f, 0.0f,
                          1.0f,  0.0f, 1.0f, 1.0f,  0.0f, 1.0f,  1.0f};

    glGenVertexArrays(1, &q->vao);
    glGenBuffers(1, &q->vbo);
    glBindVertexArray(q->vao);
    glBindBuffer(GL_ARRAY_BUFFER, q->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
                          (void *)NULLPTR);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
                          (void *)(3 * sizeof(float)));

    glGenFramebuffers(1, &q->framebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, q->framebuffer);

    glGenTextures(1, &q->tex_color_buffer);
    glBindTexture(GL_TEXTURE_2D, q->tex_color_buffer);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (int)q->size.x, (int)q->size.y, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, NULLPTR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D,
                           q->tex_color_buffer, 0);

    glGenRenderbuffers(1, &q->rbo);
    glBindRenderbuffer(GL_RENDERBUFFER, q->rbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, (int)q->size.x,
                          (int)q->size.y);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT,
                              GL_RENDERBUFFER, q->rbo);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        cpl_log(LOG_ERR, "Framebuffer is not complete!");
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

static void screen_quad_resize(screen_quad *q, int width, int height) {
    q->size = (vec2f){(float)width, (float)height};

    glBindTexture(GL_TEXTURE_2D, q->tex_color_buffer);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
                 GL_UNSIGNED_BYTE, NULLPTR);

    glBindRenderbuffer(GL_RENDERBUFFER, q->rbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);

    glBindTexture(GL_TEXTURE_2D, 0);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
}

static void screen_quad_bind(screen_quad *q) {
    glBindFramebuffer(GL_FRAMEBUFFER, q->framebuffer);
}
static void screen_quad_unbind() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

static void screen_quad_draw(screen_quad *q, shader *s) {
    use_shader(s);
    glBindVertexArray(q->vao);
    glBindTexture(GL_TEXTURE_2D, q->tex_color_buffer);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

// }}}

// {{{ Collisions

typedef struct {
    vec2f pos;
    vec2f size;
} rect_collider;
typedef struct {
    vec2f pos;
    vec2f size;
} triangle_collider;
typedef struct {
    vec2f pos;
    float radius;
} circle_collider;

static bool check_collision_rects(rect_collider a, rect_collider b) {
    bool collision_x =
        a.pos.x + a.size.x >= b.pos.x && b.pos.x + b.size.x >= a.pos.x;
    bool collision_y =
        a.pos.y + a.size.y >= b.pos.y && b.pos.y + b.size.y >= a.pos.y;

    return collision_x && collision_y;
}

static bool check_collision_circle_rect(circle_collider a, rect_collider b) {
    vec2f circle_center = a.pos;
    vec2f rect_center =
        vec2f_add(&b.pos, &VEC2F(b.size.x * 0.5f, b.size.y * 0.5f));
    vec2f half_extents = VEC2F(b.size.x * 0.5f, b.size.y * 0.5f);
    vec2f difference = vec2f_sub(&circle_center, &rect_center);
    vec2f clamped = vec2f_clamp(
        &difference, &VEC2F(-half_extents.x, -half_extents.y), &half_extents);
    vec2f closest = vec2f_add(&rect_center, &clamped);
    vec2f delta = vec2f_sub(&closest, &circle_center);

    return vec2f_length(&delta) <= a.radius;
}

static bool check_collision_vec2f_rect(vec2f a, rect_collider b) {
    return b.pos.x < a.x && a.x < b.pos.x + b.size.x && b.pos.y < a.y &&
           a.y < b.pos.y + b.size.y;
}

static bool check_collision_circles(circle_collider a, circle_collider b) {
    vec2f dist = vec2f_sub(&a.pos, &b.pos);
    float distance2 = (dist.x * dist.x) + (dist.y * dist.y);
    float radius_sum = a.radius + b.radius;
    return distance2 <= radius_sum * radius_sum;
}

static bool check_collision_vec2f_circle(vec2f a, circle_collider b) {
    vec2f dist = vec2f_sub(&a, &b.pos);
    float distance2 = (dist.x * dist.x) + (dist.y * dist.y);
    return distance2 <= b.radius * b.radius;
}

// }}}

// {{{ Timing

static unsigned int _nb_frames = 0;
static float _last_time = 0.0f;
static float _last_frame = 0.0f;
static float _dt = 0.0f;
static float _time_scale = 1.0f;
static unsigned int _fps = 0;

static float get_time() {
    static struct timespec start_ts;
    static bool initialized = false;
    struct timespec cur_ts;
    if (!initialized) {
        clock_gettime(CLOCK_MONOTONIC, &start_ts);
        initialized = true;
    }
    clock_gettime(CLOCK_MONOTONIC, &cur_ts);
    return (float)((f64)(cur_ts.tv_sec - start_ts.tv_sec) +
                   ((f64)(cur_ts.tv_nsec - start_ts.tv_nsec) * 1e-9));
}

static void calc_fps() {
    float cur_time = get_time();
    _nb_frames++;
    if (cur_time - _last_time >= 1.0) {
        _fps = _nb_frames;
        _nb_frames = 0;
        _last_time += 1.0f;
    }
}
static unsigned int get_fps() { return _fps; }

static void calc_dt() {
    float cur_frame = get_time();
    _dt = (cur_frame - _last_frame) * _time_scale;
    _last_frame = cur_frame;
}

static float get_dt() { return _dt; }
static float get_time_scale() { return _time_scale; }

static void set_time_scale(float scale) { _time_scale = scale; }

// }}}

// {{{ Inputs

typedef struct {
    vec2f pos;
    float zoom;
    float rot;
} cam_2D;

static GLFWwindow *_window = NULLPTR;
static cam_2D _cam_2D;

static bool _key_states[KEY_LAST - KEY_SPACE + 1];
static bool _prev_key_states[KEY_LAST - KEY_SPACE + 1];
static bool _mouse_button_states[MOUSE_BUTTON_LAST + 1];
static bool _prev_mouse_button_states[MOUSE_BUTTON_LAST + 1];

static void update_input() {
    for (unsigned int i = 0; i < KEY_LAST - KEY_SPACE; i++) {
        _prev_key_states[i] = _key_states[i];
    }
    for (unsigned int key = KEY_SPACE; key <= KEY_LAST; key++) {
        _key_states[key - KEY_SPACE] =
            glfwGetKey(_window, (int)key) == GLFW_PRESS;
    }

    for (unsigned int i = 0; i < MOUSE_BUTTON_LAST - MOUSE_BUTTON_1; i++) {
        _prev_mouse_button_states[i] = _mouse_button_states[i];
    }
    for (unsigned int button = MOUSE_BUTTON_1; button <= MOUSE_BUTTON_LAST;
         button++) {
        _mouse_button_states[button - MOUSE_BUTTON_1] =
            glfwGetMouseButton(_window, (int)button) == GLFW_PRESS;
    }
}

static bool is_key_down(int key) { return _key_states[key - KEY_SPACE]; }
static bool is_key_up(int key) { return !_key_states[key - KEY_SPACE]; }
static bool is_key_pressed(int key) {
    return _key_states[key - KEY_SPACE] && !_prev_key_states[key - KEY_SPACE];
}
static bool is_key_released(int key) {
    return !_key_states[key - KEY_SPACE] && _prev_key_states[key - KEY_SPACE];
}

static bool is_mouse_down(int button) {
    return _mouse_button_states[button - MOUSE_BUTTON_1];
}
static bool is_mouse_pressed(int button) {
    return _mouse_button_states[button - MOUSE_BUTTON_1] &&
           !_prev_mouse_button_states[button - MOUSE_BUTTON_1];
}
static bool is_mouse_released(int button) {
    return !_mouse_button_states[button - MOUSE_BUTTON_1] &&
           _prev_mouse_button_states[button - MOUSE_BUTTON_1];
}

static mat4f *cam_2D_get_view_mat(cam_2D *cam) {
    mat4f *view = malloc(sizeof(mat4f));
    mat4f_identity(view);

    mat4f_translate(view, &(vec3f){-cam->pos.x, -cam->pos.y, 0.0f});

    mat4f_translate(view, &(vec3f){cam->pos.x, cam->pos.y, 0.0f});
    mat4f_rotate(view, cpm_rad(cam->rot), &(vec3f){0.0f, 0.0f, 1.0f});
    mat4f_translate(view, &(vec3f){-cam->pos.x, -cam->pos.y, 0.0f});

    mat4f_translate(view, &(vec3f){cam->pos.x, cam->pos.y, 0.0f});
    mat4f_scale(view, &(vec3f){cam->zoom, cam->zoom, 1.0f});
    mat4f_translate(view, &(vec3f){-cam->pos.x, -cam->pos.y, 0.0f});

    return view;
}

static cam_2D *get_cam_2D() { return &_cam_2D; }

static vec2f get_mouse_pos() {
    f64 x = 0;
    f64 y = 0;
    glfwGetCursorPos(_window, &x, &y);
    return VEC2F((float)x, (float)y);
}
static vec2f get_screen_to_world_2D(vec2f sp) {
    float x = sp.x;
    float y = sp.y;
    x /= _cam_2D.zoom;
    y /= _cam_2D.zoom;
    x += _cam_2D.pos.x;
    y += _cam_2D.pos.y;
    return (vec2f){x, y};
}

// }}}

// {{{ Window

typedef enum {
    SHAPE_2D_UNLIT,
    SHAPE_2D_LIT,
    TEXT,
    TEXTURE_2D_UNLIT,
    TEXTURE_2D_LIT,
    _DRAW_MODES_COUNT
} draw_mode;

static GLubyte *_renderer;
static GLubyte *_vendor;
static GLubyte *_version;
static unsigned int _screen_width = 0;
static unsigned int _screen_height = 0;
static mat4f _projection_2D;
static draw_mode _cur_draw_mode = SHAPE_2D_UNLIT;
static shader _shaders[_DRAW_MODES_COUNT];
static shader _hdr_shader;

static void _framebuffer_size_callback([[maybe_unused]] GLFWwindow *window,
                                       int width, int height) {
    glViewport(0, 0, width, height);
    _screen_width = width;
    _screen_height = height;
    mat4f_ortho(&_projection_2D, 0.0f, (float)_screen_width,
                (float)_screen_height, 0.0f, -1.0f, 1.0f);
}

static void _web_window_resize() {
#ifdef __EMSCRIPTEN__
    int w = emscripten_run_script_int("window.innerWidth");
    int h = emscripten_run_script_int("window.innerHeight");
    if ((float)w != _screen_width || (float)h != _screen_height) {
        glfwSetWindowSize(_window, w, h);
    }
#endif
}

static void _init_shaders() {
#ifndef __EMSCRIPTEN__
    create_shader(&_shaders[SHAPE_2D_UNLIT], "shaders/vert/2D/shape.vert",
                  "shaders/frag/2D/shape_unlit.frag");
    create_shader(&_shaders[SHAPE_2D_LIT], "shaders/vert/2D/shape.vert",
                  "shaders/frag/2D/shape_lit.frag");
    create_shader(&_shaders[TEXT], "shaders/vert/2D/text.vert",
                  "shaders/frag/2D/text.frag");
    create_shader(&_shaders[TEXTURE_2D_UNLIT], "shaders/vert/2D/texture.vert",
                  "shaders/frag/2D/texture_unlit.frag");
    create_shader(&_shaders[TEXTURE_2D_LIT], "shaders/vert/2D/texture.vert",
                  "shaders/frag/2D/texture_lit.frag");

    create_shader(&_hdr_shader, "shaders/vert/2D/hdr.vert",
                  "shaders/frag/2D/hdr.frag");
#else
    create_shader(&_shaders[SHAPE_2D_UNLIT], "/shaders/vert/2D/shape_w.vert",
                  "/shaders/frag/2D/shape_unlit_w.frag");
    create_shader(&_shaders[SHAPE_2D_LIT], "/shaders/vert/2D/shape_w.vert",
                  "/shaders/frag/2D/shape_lit_w.frag");
    create_shader(&_shaders[TEXT], "/shaders/vert/2D/text_w.vert",
                  "/shaders/frag/2D/text_w.frag");
    create_shader(&_shaders[TEXTURE_2D_UNLIT],
                  "/shaders/vert/2D/texture_w.vert",
                  "/shaders/frag/2D/texture_unlit_w.frag");
    create_shader(&_shaders[TEXTURE_2D_LIT], "/shaders/vert/2D/texture_w.vert",
                  "/shaders/frag/2D/texture_lit_w.frag");

    create_shader(&_hdr_shader, "/shaders/vert/2D/hdr_w.vert",
                  "/shaders/frag/2D/hdr_w.frag");
#endif
}

static void init_window(unsigned int width, unsigned int height, char *title,
                        unsigned int version) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, (int)version / 10);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, (int)version % 10);
#ifndef __EMSCRIPTEN__
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif
#ifdef OPENGL_DEBUG
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, 1);
#else
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, 0);
#endif

#ifdef __EMSCRIPTEN__
    double browser_w, browser_h;
    emscripten_get_element_css_size("#canvas", &browser_w, &browser_h);
    width = (int)browser_w;
    height = (int)browser_h;
    if (width <= 0)
        width = emscripten_run_script_int("window.innerWidth");
    if (height <= 0)
        height = emscripten_run_script_int("window.innerHeight");
#endif

    _screen_width = width;
    _screen_height = height;

    _window =
        glfwCreateWindow((int)width, (int)height, title, NULLPTR, NULLPTR);
    if (!_window) {
        cpl_log(LOG_ERR, "[CPL] [ERROR] Failed to create window");
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(_window);
    glfwSetFramebufferSizeCallback(_window, _framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)(glfwGetProcAddress))) {
        cpl_log(LOG_ERR, "[CPL] [ERROR] Failed to initialize GLAD");
        exit(-1);
    }

    enable_opengl_debug();

    _cam_2D = (cam_2D){{0.0f, 0.0f}, 1.0f, 0.0f};
    mat4f_ortho(&_projection_2D, 0.0f, (float)_screen_width,
                (float)_screen_height, 0.0f, -1.0f, 1.0f);

    _init_shaders();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    _renderer = (GLubyte *)glGetString(GL_RENDERER);
    _vendor = (GLubyte *)glGetString(GL_VENDOR);
    _version = (GLubyte *)glGetString(GL_VERSION);
}

static bool window_should_close() { return glfwWindowShouldClose(_window); }

static void destroy_window() { glfwSetWindowShouldClose(_window, 1); }

static void close_window() { glfwTerminate(); }

static unsigned int get_screen_width() { return _screen_width; }
static unsigned int get_screen_height() { return _screen_height; }
static vec2f get_screen_size() { return VEC2F(_screen_width, _screen_height); }

static void enable_vsync(bool enabled) { glfwSwapInterval(enabled); }

static void update() {
    calc_fps();
    calc_dt();
    update_input();
}

static void end_frame() {
    glfwSwapBuffers(_window);
    glfwPollEvents();
}

// }}}

// {{{ Drawing

static void clear_background(vec4f color) {
    glClearColor(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f,
                 color.a / 255.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

static void begin_draw(draw_mode draw_mode, bool mode_2D) {
    _cur_draw_mode = draw_mode;
    use_shader(&_shaders[draw_mode]);

    mat4f view_projection_2D;
    if (mode_2D) {
        mat4f *view = cam_2D_get_view_mat(&_cam_2D);
        mat4f_mul(&_projection_2D, view, &view_projection_2D);
        free(view);
    }
    shader_set_mat4f(&_shaders[draw_mode], "projection",
                     mode_2D ? view_projection_2D : _projection_2D);
}

static void draw_rect(vec2f pos, vec2f size, vec4f color, float rot) {
    rect r;
    create_rect(&r, pos, size, color, rot);
    draw_rect_raw(&_shaders[_cur_draw_mode], &r);
    destroy_rect(&r);
}

static void draw_triangle(vec2f pos, vec2f size, vec4f color, float rot) {
    triangle t;
    create_triangle(&t, pos, size, color, rot);
    draw_triangle_raw(&_shaders[_cur_draw_mode], &t);
    destroy_triangle(&t);
}

static void draw_circle(vec2f pos, float radius, vec4f color) {
    circle c;
    create_circle(&c, pos, radius, color);
    draw_circle_raw(&_shaders[_cur_draw_mode], &c);
    destroy_circle(&c);
}

static void draw_line(vec2f start, vec2f end, float thickness, vec4f color) {
    line l;
    create_line(&l, start, end, color);
    glLineWidth(thickness);
    draw_line_raw(&_shaders[_cur_draw_mode], &l);
    glLineWidth(1.0f);
    destroy_line(&l);
}

static void draw_text(font *font, char *text, vec2f pos, float scale,
                      vec4f color) {
    draw_text_raw(&_shaders[_cur_draw_mode], font, text, pos, scale, color);
}

static void draw_text_shadow(font *font, char *text, vec2f pos, float scale,
                             vec4f color, vec2f shadow_off,
                             vec4f shadow_color) {
    draw_text_raw(&_shaders[_cur_draw_mode], font, text,
                  VEC2F(pos.x + shadow_off.x, pos.y + shadow_off.y), scale,
                  shadow_color);
    draw_text_raw(&_shaders[_cur_draw_mode], font, text, pos, scale, color);
}

static void draw_texture2D(texture *tex, vec2f pos, vec2f size, vec4f color,
                           float rot) {
    texture2D t;
    create_texture2D(&t, pos, size, rot, color, tex);
    draw_texture2D_raw(&_shaders[_cur_draw_mode], &t);
    destroy_texture2D(&t);
}

static void reset_shader() { use_shader(&_shaders[_cur_draw_mode]); }

static void display_details(font *font) {
    begin_draw(TEXT, false);

    char version_str[50];
    char renderer_str[50];
    char vendor_str[50];
    char fps[15];
    char stack_used[50];
    char heap_total[50];
    char heap_used[50];
    char heap_free[50];

    snprintf(version_str, 50, "OpenGL version: %s", _version);
    snprintf(renderer_str, 50, "Renderer: %s", _renderer);
    snprintf(vendor_str, 50, "Vendor: %s", _vendor);
    snprintf(fps, 15, "FPS: %d", get_fps());
    snprintf(stack_used, 50, "Stack used: %.3f / %.3f MB (%f%%)",
             MB((float)get_stack_used()), MB((float)get_stack_size()),
             (float)get_stack_used() / (float)get_stack_size());
    snprintf(heap_total, 50, "Heap size: %d MB",
             (int)MB((float)get_heap_size()));
    snprintf(heap_used, 50, "Heap used: %d MB",
             (int)MB((float)get_heap_used()));
    snprintf(heap_free, 50, "Heap free: %d MB",
             (int)MB((float)get_heap_free()));

    draw_text(font, version_str, VEC2F(10.0f, 10.0f), 0.5f, WHITE);
    draw_text(font, renderer_str, VEC2F(10.0f, 40.0f), 0.5f, WHITE);
    draw_text(font, vendor_str, VEC2F(10.0f, 70.0f), 0.5f, WHITE);
    draw_text(font, fps, VEC2F(10.0f, 100.0f), 0.5f, WHITE);
    draw_text(font, stack_used, VEC2F(10.0f, 130.0f), 0.5f, WHITE);
    draw_text(font, heap_total, VEC2F(10.0f, 160.0f), 0.5f, WHITE);
    draw_text(font, heap_used, VEC2F(10.0f, 190.0f), 0.5f, WHITE);
    draw_text(font, heap_free, VEC2F(10.0f, 220.0f), 0.5f, WHITE);
}

// }}}

// {{{ Lighting 2D

typedef struct {
    vec2f pos;
    float radius;
    float intensity;
    vec4f color;
} point_light_2D;
typedef struct {
    float intensity;
    vec4f color;
} global_light_2D;

static void set_ambient_light_2D(float strength) {
    shader *ss = &_shaders[SHAPE_2D_LIT];
    use_shader(ss);
    shader_set_float(ss, "ambient", strength);

    shader *ts = &_shaders[TEXTURE_2D_LIT];
    use_shader(ts);
    shader_set_float(ts, "ambient", strength);

    reset_shader();
}
static void set_global_light_2D(global_light_2D *l) {
    shader *ss = &_shaders[SHAPE_2D_LIT];
    use_shader(ss);
    shader_set_float(ss, "g_light.intensity", l->intensity);
    shader_set_rgba(ss, "g_light.color", l->color);

    shader *ts = &_shaders[TEXTURE_2D_LIT];
    use_shader(ts);
    shader_set_float(ts, "g_light.intensity", l->intensity);
    shader_set_rgba(ts, "g_light.color", l->color);

    reset_shader();
}

static void add_point_lights_2D(point_light_2D *ls, unsigned int size) {
    shader *ss = &_shaders[SHAPE_2D_LIT];
    use_shader(ss);

    shader_set_int(ss, "point_lights_cnt", (int)size);
    for (unsigned int i = 0; i < size; i++) {
        char pos[50];
        snprintf(pos, 50, "point_lights[%d].pos", i);
        char radius[50];
        snprintf(radius, 50, "point_lights[%d].r", i);
        char intensity[50];
        snprintf(intensity, 50, "point_lights[%d].intensity", i);
        char color[50];
        snprintf(color, 50, "point_lights[%d].color", i);

        shader_set_vec2f(ss, pos, ls[i].pos);
        shader_set_float(ss, radius, ls[i].radius);
        shader_set_float(ss, intensity, ls[i].intensity);
        shader_set_rgba(ss, color, ls[i].color);
    }

    shader *ts = &_shaders[TEXTURE_2D_LIT];
    use_shader(ts);

    shader_set_int(ts, "point_lights_cnt", (int)size);
    for (unsigned int i = 0; i < size; i++) {
        char pos[50];
        snprintf(pos, 50, "point_lights[%d].pos", i);
        char radius[50];
        snprintf(radius, 50, "point_lights[%d].r", i);
        char intensity[50];
        snprintf(intensity, 50, "point_lights[%d].intensity", i);
        char color[50];
        snprintf(color, 50, "point_lights[%d].color", i);

        shader_set_vec2f(ts, pos, ls[i].pos);
        shader_set_float(ts, radius, ls[i].radius);
        shader_set_float(ts, intensity, ls[i].intensity);
        shader_set_rgba(ts, color, ls[i].color);
    }

    reset_shader();
}

// }}}

// {{{ Tilemap

#define CPL_TILEMAP_GET_UV(m, tx, ty)                                          \
    VEC2F(((tx) * (m).size.x) / (m).tex.size.x,                                \
          ((ty) * (m).size.y) / (m).tex.size.y)

typedef struct {
    float x, y, z;
    float u, v;
} vertex;

typedef struct {
    vertex *vertices;
    bool *collidable;
    unsigned int count;
    unsigned int capacity;
    unsigned int vbo;
} tilemap_renderer;

typedef struct {
    tilemap_renderer renderer;
    vec2f size;
    texture tex;
    unsigned int vao;
} tilemap;

static void tilemap_load_texture(tilemap *m, char *path,
                                 texture_filtering filter) {
    load_texture(&m->tex, path, filter);
}

static void tilemap_delete_tile(tilemap *m, vec2f pos) {
    for (unsigned int i = 0; i < m->renderer.count; i += 6) {
        if (m->renderer.vertices[i].x == pos.x &&
            m->renderer.vertices[i].y == pos.y) {
            unsigned int right_count = m->renderer.count - (i + 6);
            if (right_count > 0) {
                memmove(&m->renderer.vertices[i], &m->renderer.vertices[i + 6],
                        right_count * sizeof(vertex));
                memmove(&m->renderer.collidable[i / 6],
                        &m->renderer.collidable[(i / 6) + 1],
                        (right_count / 6) * sizeof(bool));
            }
            m->renderer.count -= 6;
            break;
        }
    }
}

static bool tilemap_tile_exists(tilemap *m, vec2f pos) {
    for (unsigned int i = 0; i < m->renderer.count; i += 6) {
        if (m->renderer.vertices[i].x == pos.x &&
            m->renderer.vertices[i].y == pos.y) {
            return true;
        }
    }
    return false;
}

static void tilemap_check_collidable_tiles(tilemap *m, vec2f size) {
    for (unsigned int i = 0; i < m->renderer.count; i += 6) {
        bool exposed = false;

        vec2f neighbors[4] = {
            {m->renderer.vertices[i].x - size.x, m->renderer.vertices[i].y},
            {m->renderer.vertices[i].x + size.x, m->renderer.vertices[i].y},
            {m->renderer.vertices[i].x, m->renderer.vertices[i].y - size.y},
            {m->renderer.vertices[i].x, m->renderer.vertices[i].y + size.y}};

        for (unsigned int n = 0; n < 4; n++) {
            if (!tilemap_tile_exists(m, neighbors[n])) {
                exposed = true;
                break;
            }
        }
        m->renderer.collidable[i / 6] = exposed;
    }
}

static bool tilemap_tile_collidable(tilemap *m, vec2f pos) {
    for (unsigned int i = 0; i < m->renderer.count; i += 6) {
        if (m->renderer.vertices[i].x == pos.x &&
            m->renderer.vertices[i].y == pos.y) {
            return m->renderer.collidable[i / 6];
        }
    }
    return false;
}

static vec2f tilemap_get_tile_uv(tilemap *m, vec2f pos) {
    for (unsigned int i = 0; i < m->renderer.count; i += 6) {
        if (m->renderer.vertices[i].x == pos.x &&
            m->renderer.vertices[i].y == pos.y) {
            float tw = m->size.x / m->tex.size.x;
            float th = m->size.y / m->tex.size.y;
            return VEC2F(m->renderer.vertices[i].u / tw,
                         ((1.0f - m->renderer.vertices[i].v) / th) - 1.0f);
        }
    }
    return VEC2F(-1, -1);
}

static void create_tilemap(tilemap *m, vec2f tile_size) {
    m->size = tile_size;
    m->renderer.count = 0;
    m->renderer.capacity = 100 * 6;
    m->renderer.vertices = malloc(sizeof(vertex) * m->renderer.capacity);
    m->renderer.collidable = malloc(sizeof(bool) * (m->renderer.capacity / 6));

    glGenVertexArrays(1, &m->vao);
    glGenBuffers(1, &m->renderer.vbo);

    glBindVertexArray(m->vao);
    glBindBuffer(GL_ARRAY_BUFFER, m->renderer.vbo);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(vertex),
                          (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

static void destroy_tilemap(tilemap *m) {
    free(m->renderer.vertices);
    free(m->renderer.collidable);
    glDeleteBuffers(1, &m->renderer.vbo);
    glDeleteVertexArrays(1, &m->vao);
}

static void tilemap_begin_editing(tilemap *m) { m->renderer.count = 0; }

static void tilemap_add_tile(tilemap *m, vec2f pos, vec2f size, vec2f uv) {
    if (tilemap_tile_exists(m, pos)) {
        return;
    }
    if (m->renderer.count + 6 > m->renderer.capacity) {
        m->renderer.capacity *= 2;
        vertex *tmp_vertices = realloc(m->renderer.vertices,
                                       sizeof(vertex) * m->renderer.capacity);
        bool *tmp_collidable = realloc(
            m->renderer.collidable, sizeof(bool) * (m->renderer.capacity / 6));
        if (tmp_vertices && tmp_collidable) {
            m->renderer.vertices = tmp_vertices;
            m->renderer.collidable = tmp_collidable;
        }
    }

    float tw = m->size.x / m->tex.size.x;
    float th = m->size.y / m->tex.size.y;

    float u_start = uv.x * tw;
    float v_start = 1.0f - ((uv.y + 1) * th);
    float u_end = u_start + tw;
    float v_end = v_start + th;

    float x = pos.x;
    float y = pos.y;
    float w = size.x;
    float h = size.y;

    vertex quad[6] = {
        {x, y, 0, u_start, v_start},     //
        {x + w, y, 0, u_end, v_start},   //
        {x + w, y + h, 0, u_end, v_end}, //

        {x, y, 0, u_start, v_start},     //
        {x + w, y + h, 0, u_end, v_end}, //
        {x, y + h, 0, u_start, v_end}    //
    };

    memcpy(&m->renderer.vertices[m->renderer.count], quad, sizeof(quad));
    m->renderer.count += 6;
}

static void tilemap_draw(tilemap *m, vec4f color) {
    if (m->renderer.count == 0) {
        return;
    }

    glBindBuffer(GL_ARRAY_BUFFER, m->renderer.vbo);
    glBufferData(GL_ARRAY_BUFFER,
                 (unsigned int)(m->renderer.count * sizeof(vertex)),
                 m->renderer.vertices, GL_STREAM_DRAW);

    mat4f transform;
    mat4f_identity(&transform);
    shader_set_mat4f(&_shaders[_cur_draw_mode], "transform", transform);
    shader_set_rgba(&_shaders[_cur_draw_mode], "input_color", color);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m->tex.id);

    glBindVertexArray(m->vao);
    glDrawArrays(GL_TRIANGLES, 0, (int)m->renderer.count);

    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

// }}}

// {{{ Particle System

#define UNLIMITED_PARTICLES 0

#define PARTICLE(pos, size, dir, color, life_time, rot, tex)                   \
    (particle) { pos, size, dir, color, 0, life_time, rot, tex, true }

typedef struct {
    vec2f pos;
    vec2f size;
    vec2f dir;
    vec4f color;
    float cur_life_time;
    float life_time;
    float rot;
    texture *tex;
    bool active;
} particle;

typedef struct {
    vec2f pos;
    unsigned int max_particles;

    particle *particles;
} particle_system;

static void create_particle_system(particle_system *ps, vec2f pos,
                                   unsigned int max_particles) {
    ps->pos = pos;
    ps->max_particles = max_particles;
    ps->particles =
        vec_init(ps->particles,
                 max_particles >= 10 || max_particles == UNLIMITED_PARTICLES
                     ? 10
                     : max_particles);
}

static void destroy_particle_system(particle_system *ps) {
    vec_destroy(ps->particles);
}

static void update_particle_system(particle_system *ps) {
    foreach_vec(p, ps->particles) {
        p->cur_life_time += get_dt();
        p->pos = vec2f_add(&VEC2F(p->dir.x * get_dt(), p->dir.y * get_dt()),
                           &p->pos);
        if (p->cur_life_time >= p->life_time) {
            p->active = false;
        }
    }

    size_t write_idx = 0;
    for (size_t read_idx = 0; read_idx < vec_size(ps->particles); read_idx++) {
        if (ps->particles[read_idx].active) {
            ps->particles[write_idx] = ps->particles[read_idx];
            write_idx++;
        }
    }
    vec_header(ps->particles)->size = write_idx;
}

static void draw_particles(particle_system *ps) {
    foreach_vec(p, ps->particles) {
        draw_texture2D(p->tex, p->pos, p->size, p->color, p->rot);
    }
}

static void add_particle(particle_system *ps, particle p) {
    if (vec_size(ps->particles) < ps->max_particles || ps->max_particles == 0) {
        vec_push(ps->particles, p);
    }
}

// }}}

// {{{ Shadow 2D

#define MAX_RECT_SHADOWS 1024

typedef struct {
    vec2f pos;
    vec2f size;
} rect_shadow;

static rect_shadow _rect_shadows[MAX_RECT_SHADOWS];
static unsigned int _rect_shadow_count = 0;

static void begin_shadow_cast_2D() {
    glEnable(GL_STENCIL_TEST);
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
    glStencilFunc(GL_ALWAYS, 1, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
    begin_draw(SHAPE_2D_UNLIT, true);
}

static void end_shadow_cast_2D(float ambient, float shadow_strength,
                               color shadow_color) {
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    glStencilFunc(GL_EQUAL, 1, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
    float shadow_alpha = CPM_CLAMP(shadow_strength - ambient, 0, 1);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    begin_draw(SHAPE_2D_UNLIT, false);
    draw_rect(VEC2F_INIT(0), get_screen_size(),
              RGBA(shadow_color.r, shadow_color.g, shadow_color.b,
                   255 * shadow_alpha),
              0);
    glDisable(GL_STENCIL_TEST);
}

static void submit_rect_shadow(vec2f pos, vec2f size) {
    if (_rect_shadow_count < MAX_RECT_SHADOWS) {
        _rect_shadows[_rect_shadow_count++] = (rect_shadow){pos, size};
    }
}

// TODO make ts somehow work

static void draw_triangle_shadow(vec2f a, vec2f b, vec2f c) {
    float vertices[9] = {
        a.x, a.y, 0.0f, b.x, b.y, 0.0f, c.x, c.y, 1.0f,
    };
    unsigned int vao;
    unsigned int vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                          (void *)NULL);
    glEnableVertexAttribArray(0);
    mat4f transform;
    mat4f_identity(&transform);
    shader_set_mat4f(&_shaders[SHAPE_2D_UNLIT], "transform", transform);
    shader_set_rgba(&_shaders[SHAPE_2D_UNLIT], "input_color",
                    RGBA(0.0f, 0.0f, 0.0f, 1.0f));
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
}

static void draw_rect_shadow(vec2f pos, vec2f size, point_light_2D *lights,
                             unsigned int n, float far) {
    vec2f corners[4] = {
        {pos.x, pos.y},
        {pos.x + size.x, pos.y},
        {pos.x + size.x, pos.y + size.y},
        {pos.x, pos.y + size.y},
    };
    vec2f normals[4] = {
        {0, -1},
        {1, 0},
        {0, 1},
        {-1, 0},
    };
    for (unsigned int l = 0; l < n; l++) {
        for (unsigned int i = 0; i < 4; i++) {
            unsigned int next = (i + 1) % 4;
            vec2f a = corners[i];
            vec2f b = corners[next];
            vec2f mid = {(a.x + b.x) * 0.5f, (a.y + b.y) * 0.5f};
            vec2f to_edge = {mid.x - lights[l].pos.x, mid.y - lights[l].pos.y};
            float d = (normals[i].x * to_edge.x) + (normals[i].y * to_edge.y);
            if (d <= 0) {
                continue;
            }
            vec2f dir_a = {a.x - lights[l].pos.x, a.y - lights[l].pos.y};
            float len_a = cpm_sqrt((dir_a.x * dir_a.x) + (dir_a.y * dir_a.y));
            dir_a.x /= len_a;
            dir_a.y /= len_a;
            vec2f dir_b = {b.x - lights[l].pos.x, b.y - lights[l].pos.y};
            float len_b = cpm_sqrt((dir_b.x * dir_b.x) + (dir_b.y * dir_b.y));
            dir_b.x /= len_b;
            dir_b.y /= len_b;
            vec2f a2 = {a.x + (dir_a.x * far), a.y + (dir_a.y * far)};
            vec2f b2 = {b.x + (dir_b.x * far), b.y + (dir_b.y * far)};
            draw_triangle_shadow(a, b, b2);
            draw_triangle_shadow(a, b2, a2);
        }
    }
}

static void draw_shadows(point_light_2D *lights, unsigned int light_count,
                         float far, float shadow_strength) {
    glEnable(GL_STENCIL_TEST);

    glClear(GL_STENCIL_BUFFER_BIT);
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
    glStencilFunc(GL_ALWAYS, 1, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

    for (unsigned int l = 0; l < light_count; l++) {
        for (unsigned int i = 0; i < _rect_shadow_count; i++) {
            draw_rect_shadow(_rect_shadows[i].pos, _rect_shadows[i].size,
                             &lights[l], 1, far);
        }
    }

    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    glStencilFunc(GL_EQUAL, 1, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

    begin_draw(SHAPE_2D_UNLIT, false);
    draw_rect(VEC2F_INIT(0), get_screen_size(),
              RGBA(0, 0, 0, (u8)(255 * shadow_strength)), 0);

    glDisable(GL_STENCIL_TEST);
    _rect_shadow_count = 0;
}

// }}}

// {{{ HDR

typedef struct {
    unsigned int fbo;
    unsigned int rbo_depth;
    unsigned int color_buffer;
    unsigned int quad_vao;
    unsigned int quad_vbo;
} hdr;

static hdr _hdr = (hdr){0, 0, 0, 0, 0};

static void init_hdr() {
    glGenFramebuffers(1, &_hdr.fbo);
    glGenTextures(1, &_hdr.color_buffer);
    glBindTexture(GL_TEXTURE_2D, _hdr.color_buffer);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, (int)_screen_width,
                 (int)_screen_height, 0, GL_RGBA, GL_FLOAT, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glGenRenderbuffers(1, &_hdr.rbo_depth);
    glBindRenderbuffer(GL_RENDERBUFFER, _hdr.rbo_depth);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT,
                          (int)_screen_width, (int)_screen_height);
    glBindFramebuffer(GL_FRAMEBUFFER, _hdr.fbo);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D,
                           _hdr.color_buffer, 0);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,
                              GL_RENDERBUFFER, _hdr.rbo_depth);
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        cpl_log(LOG_ERR, "Framebuffer is not complete!");
    }
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

static void hdr_quad_resize(hdr *h, int width, int height) {
    // q->size = (vec2f){(float)width, (float)height};

    glBindTexture(GL_TEXTURE_2D, h->color_buffer);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
                 GL_UNSIGNED_BYTE, NULLPTR);

    glBindRenderbuffer(GL_RENDERBUFFER, h->rbo_depth);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);

    glBindTexture(GL_TEXTURE_2D, 0);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
}

static void begin_hdr() {
    glBindFramebuffer(GL_FRAMEBUFFER, _hdr.fbo);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    hdr_quad_resize(&_hdr, (int)_screen_width, (int)_screen_height);
}

static void apply_hdr(bool gamma_correct, float exposure) {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    use_shader(&_hdr_shader);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _hdr.color_buffer);
    shader_set_bool(&_hdr_shader, "gamma_correct", gamma_correct);
    shader_set_float(&_hdr_shader, "exposure", exposure);
    if (_hdr.quad_vao == 0) {
        float vertices[] = {
            -1.0f, 1.0f,  0.0f, 0.0f, 1.0f, //
            -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, //
            1.0f,  1.0f,  0.0f, 1.0f, 1.0f, //
            1.0f,  -1.0f, 0.0f, 1.0f, 0.0f, //
        };
        glGenVertexArrays(1, &_hdr.quad_vao);
        glGenBuffers(1, &_hdr.quad_vbo);
        glBindVertexArray(_hdr.quad_vao);
        glBindBuffer(GL_ARRAY_BUFFER, _hdr.quad_vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices,
                     GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
                              (void *)0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
                              (void *)(3 * sizeof(float)));
    }
    glBindVertexArray(_hdr.quad_vao);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glBindVertexArray(0);
}

// }}}

// {{{ Networking

typedef enum { NET_PACKET_RELIABLE = 1 } packet_flags;

#define NET_SEC(s) ((s) * 1000)

// {{{ Client

typedef struct {
    ENetHost *client;
    ENetAddress address;
    ENetEvent event;
    ENetPeer *peer;
} client_t;

static bool _net_worker_running = true;
static ENetHost *_host = NULL;
static void (*_parse_func)(char *, size_t, void *) = NULL;
static void *_parse_arg = NULL;
static pthread_t _net_worker;

static void *_net_worker_loop() {
    while (_net_worker_running) {
        ENetEvent event;
        while (enet_host_service(_host, &event, 0) > 0) {
            if (event.type == ENET_EVENT_TYPE_RECEIVE) {
                _parse_func((char *)event.packet->data,
                            event.packet->dataLength, _parse_arg);
                enet_packet_destroy(event.packet);
            }
        }
    }

    return NULL;
}

static void client_create_worker_loop(client_t *client,
                                      void (*parse_data)(char *, size_t,
                                                         void *),
                                      void *parse_data_arg) {
    _host = client->client;
    _parse_func = parse_data;
    _parse_arg = parse_data_arg;
    pthread_create(&_net_worker, NULL, _net_worker_loop, NULL);
}

static void client_destroy_worker_loop() {
    _net_worker_running = false;
    pthread_join(_net_worker, NULL);
}

static bool client_create(client_t *client, char *ip, int port, int wait_ms) {
    if (enet_initialize()) {
        fprintf(stderr, "Failed to init ENet\n");
        exit(-1);
    }
    atexit(enet_deinitialize);

    client->client = NULL;
    client->client = enet_host_create(NULL, 1, 1, 0, 0);
    if (!client) {
        fprintf(stderr, "Failed to create client host\n");
        exit(-1);
    }

    if (!ip) {
        fprintf(stderr, "IP is invalid\n");
        exit(-1);
    }

    enet_address_set_host(&client->address, ip);
    client->address.port = port;

    client->peer = enet_host_connect(client->client, &client->address, 1, 0);
    if (!client->peer) {
        fprintf(stderr, "No peers available for connection\n");
        exit(-1);
    }

    if (enet_host_service(client->client, &client->event, wait_ms) > 0 &&
        client->event.type == ENET_EVENT_TYPE_CONNECT) {
        return true;
    }
    enet_peer_reset(client->peer);
    return false;
}

static void client_destroy(client_t *client, int wait_ms) {
    enet_peer_disconnect(client->peer, 0);
    while (enet_host_service(client->client, &client->event, wait_ms) > 0) {
        if (client->event.type == ENET_EVENT_TYPE_RECEIVE) {
            enet_packet_destroy(client->event.packet);
        } else if (client->event.type == ENET_EVENT_TYPE_DISCONNECT) {
            break;
        }
    }
}

// }}}

// {{{ Server

typedef struct {
    ENetHost *server;
    ENetAddress address;
} server_t;

static void server_init(server_t *server, int port, struct in6_addr host,
                        int max_clients) {
    if (enet_initialize()) {
        fprintf(stderr, "Failed to init ENet\n");
        exit(-1);
    }
    atexit(enet_deinitialize);

    server->address.host = host;
    server->address.port = port;

    server->server = enet_host_create(&server->address, max_clients, 1, 0, 0);
    if (!server) {
        fprintf(stderr, "Failed to create server host\n");
        exit(-1);
    }
}

static void server_destroy(server_t *server) {
    enet_host_destroy(server->server);
}

// }}}

// {{{ Packets

typedef struct {
    uint8_t data[1024];
    size_t size;
} packet_writer;

typedef struct {
    uint8_t *data;
    size_t size;
    size_t pos;
} packet_reader;

static void packet_writer_init(packet_writer *writer, uint8_t packet_id) {
    writer->data[0] = packet_id;
    writer->size = 1;
}

static void packet_write_char(packet_writer *writer, char val) {
    writer->data[writer->size++] = val;
}

static void packet_write_int(packet_writer *writer, int val) {
    memcpy(&writer->data[writer->size], &val, sizeof(int));
    writer->size += sizeof(int);
}

static void packet_write_uint(packet_writer *writer, unsigned int val) {
    memcpy(&writer->data[writer->size], &val, sizeof(unsigned int));
    writer->size += sizeof(unsigned int);
}

static void packet_write_float(packet_writer *writer, float val) {
    memcpy(&writer->data[writer->size], &val, sizeof(float));
    writer->size += sizeof(float);
}

static void packet_write_double(packet_writer *writer, double val) {
    memcpy(&writer->data[writer->size], &val, sizeof(double));
    writer->size += sizeof(double);
}

static void packet_write_bool(packet_writer *writer, bool val) {
    memcpy(&writer->data[writer->size], &val, sizeof(bool));
    writer->size += sizeof(bool);
}

static uint8_t packet_reader_init(packet_reader *reader, uint8_t *data,
                                  size_t size) {
    reader->data = data;
    reader->size = size;
    reader->pos = 0;

    return reader->data[reader->pos++];
}

static char packet_read_char(packet_reader *reader) {
    return (char)reader->data[reader->pos++];
}

static int packet_read_int(packet_reader *reader) {
    int val = 0;
    memcpy(&val, &reader->data[reader->pos], sizeof(int));
    reader->pos += sizeof(int);
    return val;
}

static unsigned int packet_read_uint(packet_reader *reader) {
    unsigned int val = 0;
    memcpy(&val, &reader->data[reader->pos], sizeof(unsigned int));
    reader->pos += sizeof(unsigned int);
    return val;
}

static float packet_read_float(packet_reader *reader) {
    float val = 0;
    memcpy(&val, &reader->data[reader->pos], sizeof(float));
    reader->pos += sizeof(float);
    return val;
}

static double packet_read_double(packet_reader *reader) {
    double val = 0;
    memcpy(&val, &reader->data[reader->pos], sizeof(double));
    reader->pos += sizeof(double);
    return val;
}

static bool packet_read_bool(packet_reader *reader) {
    bool val = 0;
    memcpy(&val, &reader->data[reader->pos], sizeof(bool));
    reader->pos += sizeof(bool);
    return val;
}

static void send_packet_to_server(client_t *client, packet_writer *writer,
                                  int packet_flag) {
    ENetPacket *packet =
        enet_packet_create(writer->data, writer->size, packet_flag);
    enet_peer_send(client->peer, 0, packet);
}

static void send_packet_to_client(ENetPeer *peer, packet_writer *writer,
                                  int packet_flag) {
    ENetPacket *packet =
        enet_packet_create(writer->data, writer->size, packet_flag);
    enet_peer_send(peer, 0, packet);
}

static void broadcast_packet(server_t *server, packet_writer *writer,
                             int packet_flag) {
    ENetPacket *packet =
        enet_packet_create(writer->data, writer->size, packet_flag);
    enet_host_broadcast(server->server, 0, packet);
}

// }}}

// }}}

#ifdef __cplusplus
}
}
#endif
