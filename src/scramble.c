#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MOVES "RLUDFB"

int get_random(int min, int max) {
    return min + rand() % (max - min + 1);
}

void generate_scramble(int length, char scramble[]) {
    const char moves[] = MOVES;
    int index = 0;
    char previous_move = ' ';

    for (int i = 0; i < length; i++) {
        char random_move;
        do {
            random_move = moves[rand() % (sizeof(moves) - 1)];
        } while(previous_move == random_move);
        scramble[index] = random_move;
        previous_move = random_move;
        index++;

        int move_type = get_random(0, 2);

        if (move_type == 1) {
            scramble[index] = '\'';
            index++;
        } else if (move_type == 2) {
            scramble[index] = '2';
            index++;
        }

        if (i < length - 1) {
            scramble[index] = ' ';
            index++;
        }
    }

    scramble[index] = '\0';
}
