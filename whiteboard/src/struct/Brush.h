#include <raylib.h>

#ifndef BRUSH_H
#define BRUSH_H

typedef struct Brush {
  Vector2 coords;

  Color primaryColor;
  Color secondaryColor;

  float size;
  float velocity;
} Brush;

void brushSwapColors(Brush *brush);

#endif
