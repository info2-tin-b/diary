#include <stdbool.h>
#include <stdio.h>

#define N 8
#define DEBUG

bool labyrinthe[N][N] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {1, 0, 1, 0, 1, 1, 1, 0},
    {1, 0, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
};

bool visited[N][N] = {false};
bool solution[N][N] = {false};

void display() {
    // Codes couleurs ANSI
    const char *WALL_COLOR = "\033[38;5;94m";     // Brun
    const char *SOLUTION_COLOR = "\033[38;5;120m";  // Vert clair
    const char *VISITED_COLOR = "\033[38;5;203m";   // Rouge clair
    const char *RESET_COLOR = "\033[0m";

    for (int i = 0; i < N + 2; i++) {
        for (int j = 0; j < N + 2; j++) {
            if (i == 0 || i == N + 1 || j == 0 || j == N + 1) {
                printf("%s██%s", WALL_COLOR, RESET_COLOR);
                continue;
            }

            int x = i - 1;
            int y = j - 1;

            if (labyrinthe[x][y] == 0) {
                printf("%s██%s", WALL_COLOR, RESET_COLOR);
            } else if (solution[x][y]) {
                printf("%s██%s", SOLUTION_COLOR, RESET_COLOR);
            } else if (visited[x][y]) {
                printf("%s██%s", VISITED_COLOR, RESET_COLOR);
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

bool unvisited_path(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N &&
            labyrinthe[x][y] == 1 &&
            !visited[x][y]);
}

bool for_each_neighbor(int x, int y, bool (*callback)(int, int)) {
    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (!unvisited_path(nx, ny)) continue;
        if (callback(nx, ny)) return true;
    }
    return false;
}

bool find_exit(int x, int y) {
    #ifdef DEBUG
    printf("Visiting (%d, %d)\n", x, y);
    display();
    #endif
    // Reached the exit?
    if (x == N - 1 && y == N - 1) {
        visited[x][y] = true;
        solution[x][y] = true;
        return true;
    }

    if (!unvisited_path(x, y))
        return false;

    visited[x][y] = true;
    if (for_each_neighbor(x, y, find_exit)) {
        // Backtrack
        solution[x][y] = true;
        #ifdef DEBUG
        display();
        #endif
        return true;
    }
}

int main() {
    bool found_exit = find_exit(0, 0);
    display();
    return 0;
}
