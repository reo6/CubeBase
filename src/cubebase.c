#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <raylib.h>
#include "timer.h"
#include "scramble.h"
#include "colors.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TITLE "CubeBase"


int main() {
    srand(time(NULL));

    ColorScheme greenscheme;
    greenscheme.background = c_darkgreen;
    greenscheme.text = c_greenwhite;
    greenscheme.text_secondary = c_greenwhite;

    ColorScheme current_scheme = greenscheme;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    Timer timer = timer_new(SCREEN_WIDTH, SCREEN_HEIGHT, &current_scheme);

    while (!WindowShouldClose()) {
        timer_update(&timer);
        BeginDrawing();
        ClearBackground(current_scheme.background);
        timer_draw(&timer);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
