#ifndef TIMER_H
#define TIMER_H

#include <stdbool.h>
#include "scramble.h"

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
    char* descriptionText;
    char* scramble;
} Timer;

// Function prototypes
Timer timer_new(int frameWidth, int frameHeight);
void timer_update(Timer *t);
void timer_draw(Timer *t);

#endif // TIMER_H
