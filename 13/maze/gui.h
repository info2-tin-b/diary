#pragma once

typedef struct gui GUI;

GUI* gui_init();
void gui_destroy(GUI *gui);
bool gui_should_exit(GUI *gui);
void gui_clear(GUI *gui);

void gui_draw_wall(GUI *gui, int x, int y);
void gui_draw_solution(GUI *gui, int x, int y);
void gui_draw_visited(GUI *gui, int x, int y);

void gui_draw_path(GUI *gui, int x, int y);

void gui_draw_grid(GUI *gui, const int size);

void gui_present(GUI *gui);
