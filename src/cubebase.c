#include <raylib.h>
#include "timer.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TITLE "CubeBase"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    Timer timer = timer_new(800, 600);

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
