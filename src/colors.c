#include "colors.h"
#include <raylib.h>


const Color c_black = {0xff, 0xff, 0xff, 0xff};
const Color c_white = {0x00, 0x00, 0x00, 0xff};
const Color c_darkgreen = {0x39, 0x51, 0x44, 0xff};
const Color c_greenwhite = {0xf0, 0xeb, 0xce, 0xff};

// #252B48
const Color c_vintage_bg = {0x25, 0x2B, 0x48, 0xff};
// #F7E987
const Color c_vintage_fg = {0xF7, 0xE9, 0x87, 0xff};

// Pre-defined color schemes:
ColorScheme s_greenscheme;
ColorScheme s_vintage;

ColorScheme s_themes[THEMES_LENGTH];

void scheme_init() {
    s_greenscheme = scheme_new(c_darkgreen, c_greenwhite, c_greenwhite);
    s_vintage = scheme_new(c_vintage_bg, c_vintage_fg, c_vintage_fg);

    s_themes[0] = s_vintage;
    s_themes[1] = s_greenscheme;
}

ColorScheme scheme_new(Color background, Color text, Color t2) {
  ColorScheme scheme;
  scheme.background = background;
  scheme.text = text;
  scheme.text_secondary = t2;
  return scheme;
}
