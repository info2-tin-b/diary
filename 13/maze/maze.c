#include <stdbool.h>
#include <stdio.h>

#include "gui.h"

#define MAZE 1

#define N 8

typedef struct maze {
    unsigned size;
    bool data[N][N];
    bool visited[N][N];
    bool solution[N][N];
} Maze;


Maze maze = {
    .size = N,
    .data = {
#if MAZE == 1
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1, 1, 1, 0},
        {1, 0, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
#elif MAZE == 2
        {1, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
#endif
    }
};



void draw_maze(GUI *gui, Maze *maze) {
    gui_clear(gui);
    for (int x = 0; x < maze->size; x++) {
        for (int y = 0; y < maze->size; y++) {
            if (maze->data[x][y] == 0) {
                gui_draw_wall(gui, x, y);
            } else if (maze->solution[x][y]) {
                gui_draw_solution(gui, x, y);
            } else if (maze->visited[x][y]) {
                gui_draw_visited(gui, x, y);
            } else {
                gui_draw_path(gui, x, y);
            }
            gui_draw_grid(gui, maze->size);
        }
    }
    gui_present(gui);
}

bool unvisited_path(Maze *maze, int x, int y) {
    bool valid = true;
    valid &= x >= 0 && x < N;
    valid &= y >= 0 && y < N;
    valid &= maze->data[x][y] == 1;
    valid &= !maze->visited[x][y];
    return valid;
}

void display_level(int x, int y, int level) {
    for (int i = 0; i < level; i++) printf("   ");
    printf("%c%d\n", 'A' + x , y);
}

bool find_exit(GUI *gui, Maze *maze, int x, int y, int level) {
    display_level(x, y, level);

    if (x == N - 1 && y == N - 1) {
        maze->visited[x][y] = true;
        maze->solution[x][y] = true;
        draw_maze(gui, maze);
        display_level(x, y, level);
        return true;
    }

    if (!unvisited_path(maze, x, y)) {
        display_level(x, y, level);
        return false;
    }

    maze->visited[x][y] = true;
    draw_maze(gui, maze);

    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (!unvisited_path(maze, nx, ny)) continue;
        if (find_exit(gui, maze, nx, ny, level + 1)) {
            maze->solution[x][y] = true;
            draw_maze(gui, maze);
            display_level(x, y, level);
            return true;
        }
    }
    display_level(x, y, level);
    return false;
}

int main() {
    GUI *gui = gui_init(maze.size);
    find_exit(gui, &maze, 0, 0, 0);

    while(!gui_should_exit(gui)) {
        draw_maze(gui, &maze);
    }
    gui_destroy(gui);
}
