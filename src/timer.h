#ifndef TIMER_H
#define TIMER_H

#include <stdbool.h>
#include "scramble.h"
#include "colors.h"

#define MAX_SCRAMBLE_LENGTH 400

typedef struct {
    double startTime;
    double currentTime;
    bool running;
    bool ready;
    bool stopped;
    char timerText[64];
    int frameWidth;
    int frameHeight;
    int fontSize;
    char scramble[MAX_SCRAMBLE_LENGTH];

    ColorScheme *scheme;
} Timer;

// Function prototypes
Timer timer_new(int frameWidth, int frameHeight, ColorScheme *scheme);
void timer_update(Timer *t);
void timer_draw(Timer *t);
void timer_reset_scramble(Timer *t);

#endif // TIMER_H
