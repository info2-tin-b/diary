#include <SDL2/SDL.h>
#include <stdbool.h>
#include "gui.h"

#define CELL_SIZE 50

struct gui {
    SDL_Window *window;
    SDL_Renderer *renderer;
};

GUI* gui_init(unsigned size) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Window *win = SDL_CreateWindow("Labyrinthe", 100, 100, size * CELL_SIZE, size * CELL_SIZE, SDL_WINDOW_SHOWN);
    if (!win) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        SDL_DestroyWindow(win);
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Couleur de fond blanche
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    GUI *gui = malloc(sizeof(GUI));
    gui->window = win;
    gui->renderer = renderer;
    return gui;
}

void gui_destroy(GUI *gui) {
    SDL_DestroyRenderer(gui->renderer);
    SDL_DestroyWindow(gui->window);
    free(gui);
    SDL_Quit();
}

bool gui_should_exit(GUI *gui) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            gui_destroy(gui);
            return true;
        }
    }
    return false;
}

void gui_clear(GUI *gui) {
    SDL_SetRenderDrawColor(gui->renderer, 255, 255, 255, 255); // Couleur de fond blanche
    SDL_RenderClear(gui->renderer);
}

void gui_draw_wall(GUI *gui, int x, int y) {
    SDL_Rect cell = { y * CELL_SIZE, x * CELL_SIZE, CELL_SIZE, CELL_SIZE };
    SDL_SetRenderDrawColor(gui->renderer, 64, 64, 64, 255); // Couleur des murs
    SDL_RenderFillRect(gui->renderer, &cell);
}

void gui_draw_solution(GUI *gui, int x, int y) {
    SDL_Rect cell = { y * CELL_SIZE, x * CELL_SIZE, CELL_SIZE, CELL_SIZE };
    SDL_SetRenderDrawColor(gui->renderer, 144, 238, 144, 255); // Couleur de la solution
    SDL_RenderFillRect(gui->renderer, &cell);
}

void gui_draw_visited(GUI *gui, int x, int y) {
    SDL_Rect cell = { y * CELL_SIZE, x * CELL_SIZE, CELL_SIZE, CELL_SIZE };
    SDL_SetRenderDrawColor(gui->renderer, 160, 160, 160, 255); // Couleur des cellules visitées
    SDL_RenderFillRect(gui->renderer, &cell);
}

void gui_draw_path(GUI *gui, int x, int y) {
    SDL_Rect cell = { y * CELL_SIZE, x * CELL_SIZE, CELL_SIZE, CELL_SIZE };
    SDL_SetRenderDrawColor(gui->renderer, 200, 200, 200, 255); // Couleur du chemin
    SDL_RenderFillRect(gui->renderer, &cell);
}

void gui_draw_grid(GUI *gui, const int size) {
    SDL_SetRenderDrawColor(gui->renderer, 0, 0, 0, 255); // Couleur des contours
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            SDL_Rect cell = { y * CELL_SIZE, x * CELL_SIZE, CELL_SIZE, CELL_SIZE };
            SDL_SetRenderDrawColor(gui->renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(gui->renderer, &cell);
        }
    }
}

void gui_present(GUI *gui) {
    SDL_RenderPresent(gui->renderer);
    SDL_Delay(200);
}
