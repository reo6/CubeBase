#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <raylib.h>
#include "timer.h"
#include "scramble.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TITLE "CubeBase"

int main() {
    srand(time(NULL));

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    Timer timer = timer_new(SCREEN_WIDTH, SCREEN_HEIGHT);

    while (!WindowShouldClose()) {
        timer_update(&timer);
        BeginDrawing();
        ClearBackground(BLACK);
        timer_draw(&timer);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
