#include "colors.h"
#include <raylib.h>

const Color c_black = {0xff, 0xff, 0xff, 0xff};
const Color c_white = {0x00, 0x00, 0x00, 0xff};
const Color c_darkgreen = {0x39, 0x51, 0x44, 0xff};
const Color c_greenwhite = {0xf0, 0xeb, 0xce, 0xff};


void scheme_init() {
    s_greenscheme = scheme_new(c_darkgreen, c_greenwhite, c_greenwhite);
    s_vintage = scheme_new(c_vintage_bg, c_vintage_fg, c_vintage_fg);
}

ColorScheme scheme_new(Color background, Color text, Color t2) {
  ColorScheme scheme;
  scheme.background = background;
  scheme.text = text;
  scheme.text_secondary = t2;
  return scheme;
}
