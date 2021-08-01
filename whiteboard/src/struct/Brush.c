#include "Brush.h"

void brushSwapColors(Brush *brush) {
  Color temp = brush->primaryColor;

  brush->primaryColor = brush->secondaryColor;
  brush->secondaryColor = temp;
}

void brushApplyDefaultControls(Brush *brush) {
  // Brush control
  if (IsKeyPressed(KEY_C))
    brushSwapColors(brush);

  if (IsKeyPressed(KEY_X) && brush->size < 25)
    brush->size += 5;
  if (IsKeyPressed(KEY_Z) && brush->size > 5)
    brush->size -= 5; // Brush size

  // Move brush
  if (IsKeyDown(KEY_UP))
    brush->coords.y -= brush->velocity;
  if (IsKeyDown(KEY_DOWN))
    brush->coords.y += brush->velocity;
  if (IsKeyDown(KEY_RIGHT))
    brush->coords.x += brush->velocity;
  if (IsKeyDown(KEY_LEFT))
    brush->coords.x -= brush->velocity;
}
