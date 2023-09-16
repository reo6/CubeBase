#ifndef COLORS_H_
#define COLORS_H_

#include <raylib.h>

extern const Color c_black;
extern const Color c_white;
extern const Color c_darkgreen;
extern const Color c_greenwhite;
extern const Color c_vintage_bg;
extern const Color c_vintage_fg;

typedef struct {
  Color background;
  Color text;
  Color text_secondary;
} ColorScheme;


// Pre-defined color schemes:
extern ColorScheme s_greenscheme;
extern ColorScheme s_vintage;

ColorScheme scheme_new(Color background, Color text, Color t2);
void scheme_init();

#endif // COLORS_H_

