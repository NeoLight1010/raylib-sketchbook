#include <raylib.h>
#include <stdio.h>

void swapMainColors(Color *primary, Color *secondary) {
  Color temp = *primary;

  *primary = *secondary;
  *secondary = temp;
}

int main() {
  const int W = 800;
  const int H = 450;

  InitWindow(W, H, "Whiteboard");

  Color primaryColor = RED;
  Color secondaryColor = RAYWHITE;

  Vector2 brushCoords = {(float)W / 2, (float)H / 2};
  float brushSize = 15;
  float brushVelocity = 1;

  while (!WindowShouldClose()) {
    // Brush color control
    if (IsKeyPressed(KEY_C))
      swapMainColors(&primaryColor, &secondaryColor);

    // Move brush
    if (IsKeyDown(KEY_UP))
      brushCoords.y -= brushVelocity;
    if (IsKeyDown(KEY_DOWN))
      brushCoords.y += brushVelocity;
    if (IsKeyDown(KEY_RIGHT))
      brushCoords.x += brushVelocity;
    if (IsKeyDown(KEY_LEFT))
      brushCoords.x -= brushVelocity;

    // Drawing
    BeginDrawing();

    DrawCircleV(brushCoords, brushSize, primaryColor);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
