#include "Brush.h"

void brushSwapColors(Brush *brush) {
  Color temp = brush->primaryColor;

  brush->primaryColor = brush->secondaryColor;
  brush->secondaryColor = temp;
}
