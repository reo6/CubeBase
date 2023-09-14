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
Move* generate_scramble(int length);

#endif // SCRAMBLE_H_
