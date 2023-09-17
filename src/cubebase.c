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
    scheme_init();

    int current_scheme = 0;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    SetWindowIcon(LoadImage("icon.png"));
    Timer timer = timer_new(SCREEN_WIDTH, SCREEN_HEIGHT, &s_themes[current_scheme]);

    while (!WindowShouldClose()) {
        if(IsKeyPressed(KEY_TAB)) {
            if(current_scheme == THEMES_LENGTH-1) {
                current_scheme = 0;
            } else {
                current_scheme++;
            }

            timer.scheme = &s_themes[current_scheme];
        }

        timer_update(&timer);
        BeginDrawing();
        ClearBackground(s_themes[current_scheme].background);
        timer_draw(&timer);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
