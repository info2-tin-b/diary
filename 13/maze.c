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

/**
 * Check if the cell (x, y) is a valid path and not visited.
 * - Not out of bounds
 * - Not a wall
 * - Not visited
 */
bool unvisited_path(int x, int y) {
    return false;
}

/**
 * From a given cell (x, y), iterate over its neighbors
 * (up, right, down, left)
 * and call the callback function for each unvisited path.
 *
 * NOTE: Only valid unvisited paths are passed to the callback.
 *
 * @return true if the callback returns true for any neighbor.
 */
bool for_each_neighbor(int x, int y, bool (*callback)(int, int)) {
    return false;
}

/**
 * Recursive function to find the exit of the maze.
 *
 * 1. Return if the exit is found.
 * 2. Check if the cell (x, y) is a valid path and not visited.
 * 3. Mark the cell as visited.
 * 4. For each neighbor (up, right, down, left):
 *    - If the neighbor is a valid path, call find_exit recursively.
 * 5. If the exit is found, mark the cell as part of the solution.
 * 6. Backtrack if necessary.
 * 7. Return true if the exit is found.
 *
 * @return true if the exit is found.
 */
bool find_exit(int x, int y) {
    return false;
}

int main() {
    bool found_exit = find_exit(0, 0);
    display();
}
