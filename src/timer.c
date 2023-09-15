#include <stdio.h>
#include <raylib.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "timer.h"
#include "scramble.h"

#define SCRAMBLE_LENGTH 12
#define MAX_SCRAMBLE_LENGTH 500

Timer timer_new(int frameWidth, int frameHeight) {
    Timer timer;

    timer.startTime = 0;
    timer.currentTime = 0;
    timer.running = false;
    timer.ready = false;
    timer.stopped = false;

    timer.frameWidth = frameWidth;
    timer.frameHeight = frameHeight;
    timer.fontSize = 60;
    timer.descriptionText = "Press SPACE to start/stop";
    
    Move scramble_moves[SCRAMBLE_LENGTH];
    generate_scramble(SCRAMBLE_LENGTH, scramble_moves);

    scramble_to_string(scramble_moves, timer.scramble, SCRAMBLE_LENGTH);

    return timer;
}


void timer_update(Timer *t) {
    if (t->running) {
        t->currentTime = GetTime() - t->startTime;
    }

    if(IsKeyDown(KEY_SPACE)) {
        if(t->running) {
            t->running = false;
            t->ready = false;
            t->stopped = true;
        } else {
            if(!t->ready && !t->stopped) {
                t->ready = true;
                t->startTime = GetTime();
                t->currentTime = 0;
            }
        }
    } else {
        if(t->ready) {
            t->ready = false;
            t->running = true;
        }
        t->stopped = false;
    }

    sprintf(t->timerText, "%.2f", t->currentTime);
}

void timer_draw(Timer *t) {
    DrawText(t->timerText, (t->frameWidth - MeasureText(t->timerText, t->fontSize)) / 2, (t->frameHeight - t->fontSize) / 2, t->fontSize, t->ready ? GREEN : RAYWHITE);
    DrawText(t->scramble, (t->frameWidth - MeasureText(t->scramble, 20)) / 2, (t->frameHeight - 20) - 30, 20, RAYWHITE);
}
