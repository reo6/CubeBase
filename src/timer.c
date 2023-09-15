#include <stdio.h>
#include <raylib.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "timer.h"
#include "scramble.h"

#define SCRAMBLE_LENGTH 12
#define DESCRIPTION_FONTSIZE 30
#define TIMER_FONTSIZE 80

Timer timer_new(int frameWidth, int frameHeight) {
    Timer timer;

    timer.startTime = 0;
    timer.currentTime = 0;
    timer.running = false;
    timer.ready = false;
    timer.stopped = false;

    timer.frameWidth = frameWidth;
    timer.frameHeight = frameHeight;

    generate_scramble(SCRAMBLE_LENGTH, timer.scramble);

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
            generate_scramble(SCRAMBLE_LENGTH, t->scramble);
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
    DrawText(t->timerText, (t->frameWidth - MeasureText(t->timerText, TIMER_FONTSIZE)) / 2, (t->frameHeight - TIMER_FONTSIZE) / 2, TIMER_FONTSIZE, t->ready ? GREEN : RAYWHITE);
    DrawText(t->scramble, (t->frameWidth - MeasureText(t->scramble, DESCRIPTION_FONTSIZE)) / 2, (t->frameHeight - DESCRIPTION_FONTSIZE) - 30, DESCRIPTION_FONTSIZE, RAYWHITE);
}
