#include "draw.h"

#include <math.h>
#include <stdio.h>

#include "evaluation.h"

void plot_point(char grid[HEIGHT][WIDTH], int x, int y) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        grid[y][x] = '*';
    }
}

void draw_graph(double (*func)(const char* expression, double), const char* expression) {
    char grid[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = '.';
        }
    }

    double x_step = (X_MAX - X_MIN) / WIDTH;
    double y_scale = (double)(HEIGHT - 1) / (double)(Y_MAX - Y_MIN);

    for (int i = 0; i < WIDTH; i++) {
        double x = X_MIN + i * x_step;
        double y = func(expression, x);

        if (y >= Y_MIN && y <= Y_MAX) {
            int plot_x = i;
            int plot_y = round((y - Y_MIN) * y_scale);
            plot_point(grid, plot_x, plot_y);
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            putchar(grid[i][j]);
        }
        putchar('\n');
    }
}
