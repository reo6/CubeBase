#ifndef COLORS_H_
#define COLORS_H_

#include <raylib.h>

extern const Color c_black;
extern const Color c_white;
extern const Color c_darkgreen;
extern const Color c_greenwhite;


typedef struct {
  Color background;
  Color text;
  Color text_secondary;
} ColorScheme;

#endif // COLORS_H_

