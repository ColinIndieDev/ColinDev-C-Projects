#include "../include/cplt/cplt.h"

#include <termios.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

static struct termios origin;

static int rows;
static int cols;
static pixel_t *screen_buffer;

int cplt_begin() {
    struct termios raw;
    if (tcgetattr(STDIN_FILENO, &origin) == -1) {
        perror("tcgetattr");
        return 0;
    }
    raw = origin;
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= (CS8);
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) {
        perror("tcgetattr");
        return 0;
    }
    struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
    rows = ws.ws_row;
    cols = ws.ws_col;
    screen_buffer = calloc(rows * cols, sizeof(pixel_t));
    for (int i = 0; i < rows * cols; ++i) {
        screen_buffer[i].c = ' ';
        screen_buffer[i].f = RGB(255, 255, 255);
        screen_buffer[i].b = RGB(0, 0, 0);
    }
    write(STDOUT_FILENO, CLEAR_SCREEN HIDE_CURSOR, 10);
    return 1;
}

void cplt_end() {
    write(STDOUT_FILENO, SHOW_CURSOR, 6);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &origin);
}

void cplt_clear() {
    printf(CLEAR_SCREEN RESET_CURSOR_POS);
    fflush(stdout);
}

void cplt_refresh() {
    char buffer[1024 * 1024];
    int len = 0;
    len += snprintf(buffer + len, sizeof(buffer) - len, RESET_CURSOR_POS);
    color_t cf = RGB(0, 0, 0);
    color_t cb = RGB(0, 0, 0);
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            pixel_t pixel = screen_buffer[y * cols + x];
            if (memcmp(&pixel.f, &cf, sizeof(color_t)) != 0 || memcmp(&pixel.b, &cb, sizeof(color_t))) {
                len += snprintf(buffer + len, sizeof(buffer) - len, "\e[38;2;%d;%d;%dm", pixel.f.r, pixel.f.g, pixel.f.b);
                len += snprintf(buffer + len, sizeof(buffer) - len, "\e[48;2;%d;%d;%dm", pixel.b.r, pixel.b.g, pixel.b.b);
                cf = pixel.f;
                cb = pixel.b;
            }
            buffer[len++] = pixel.c;
        }
        if (y < rows - 1) {
            len += snprintf(buffer + len, sizeof(buffer) - len, "\r\n");
        }
    }
    len += snprintf(buffer + len, sizeof(buffer) - len, "\e[0m");
    write(STDOUT_FILENO, buffer, len);
}

void cplt_putc(int x, int y, char c, color_t f, color_t b) {
    if (y < 0 || y >= rows || x < 0 || x >= cols) {
        return;
    }
    screen_buffer[y * cols + x].c = c;
    screen_buffer[y * cols + x].f = f;
    screen_buffer[y * cols + x].b = b;
}

void cplt_puts(int x, int y, const char *str, color_t f, color_t b) {
    while (*str) {
        cplt_putc(x++, y, *str++, f, b);
    }
}

void cplt_get_key_pressed(unsigned char buffer[3], ssize_t *n) {
    *n = read(STDIN_FILENO, buffer, 3);
}

int cplt_get_screen_width() {
    return rows;
}

int cplt_get_screen_height() {
    return cols;
}
