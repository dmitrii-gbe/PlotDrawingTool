#pragma once

#define WIDTH 80
#define HEIGHT 25
#define X_MIN 0
#define X_MAX (4 * M_PI)
#define Y_MIN -1
#define Y_MAX 1

void draw_graph(double (*func)(const char* expression, double), const char* expression);

void plot_point(char grid[HEIGHT][WIDTH], int x, int y);
