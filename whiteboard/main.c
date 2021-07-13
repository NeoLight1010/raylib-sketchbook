#include <raylib.h>
#include <stdio.h>

int main() {
  const int W = 800;
  const int H = 450;

  InitWindow(W, H, "Whiteboard");

  Vector2 brushCoords = {(float)W / 2, (float)H / 2};
  Color brushColor = RED;
  float brushSize = 15;
  float brushVelocity = 1;

  while (!WindowShouldClose()) {
    // Controls
    // Move brush.
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

    DrawCircleV(brushCoords, brushSize, brushColor);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
