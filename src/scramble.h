#ifndef SCRAMBLE_H_
#define SCRAMBLE_H_

#include <stdbool.h>

typedef enum {
  R,
  L,
  U,
  D,
  F,
  B
} Notation;

typedef struct {
  Notation notation;
  bool cclockwise;
  bool doublemove;
} Move; // TODO Find a better name

Move random_move();
void generate_scramble(int length, Move* scramble);
void move_to_string(Move move, char* move_str);
void scramble_to_string(Move* scramble, char* scr_str, int length);

#endif // SCRAMBLE_H_
