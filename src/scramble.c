#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "scramble.h"

#define NUMNOTATIONS 6

Move random_move() {
    Move move;
    move.notation = (Notation)(rand() % NUMNOTATIONS);
    
    move.cclockwise = rand() % 2 == 0;
    move.doublemove = rand() % 2 == 0;

    if (move.cclockwise && move.doublemove) {
        move.doublemove = false;
    }

    return move;
}

void move_to_string(Move move, char* move_str) {
    char notation_str[2];
    char move_part[2] = "";

    switch (move.notation) {
        case R:
            strcpy(notation_str, "R");
            break;
        case L:
            strcpy(notation_str, "L");
            break;
        case U:
            strcpy(notation_str, "U");
            break;
        case D:
            strcpy(notation_str, "D");
            break;
        case F:
            strcpy(notation_str, "F");
            break;
        case B:
            strcpy(notation_str, "B");
            break;
        default:
            notation_str[0] = '\0';
            break;
    }

    if (move.doublemove) {
        strcpy(move_part, "2");
    } else {
        if (move.cclockwise) {
            strcpy(move_part, "'");
        }
    }

    strcpy(move_str, notation_str);
    strcat(move_str, move_part);
}

void generate_scramble(int length, Move* scramble) {
    Move previous_move = random_move();
    scramble[0] = previous_move;

    for (int i = 1; i < length; i++) {
        Move current_move;
        do {
            current_move = random_move();
        } while (current_move.notation == previous_move.notation || 
                 (current_move.cclockwise && current_move.doublemove) || 
                 current_move.doublemove == previous_move.cclockwise || 
                 (current_move.cclockwise && previous_move.doublemove) ||
                 (current_move.doublemove && previous_move.doublemove));

        scramble[i] = current_move;
        previous_move = current_move;
    }
}

void scramble_to_string(Move* scramble, char* scr_str, int length) {
    scr_str[0] = '\0';

    for (int i = 0; i < length; i++) {
        char move_str[3];
        move_to_string(scramble[i], move_str);
        if (i > 0) {
            strcat(scr_str, " ");
        }
        strcat(scr_str, move_str);
    }
}
