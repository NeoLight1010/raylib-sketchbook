#include "struct/Brush.h"
#include <raylib.h>
#include <stdio.h>

int main() {
  const int W = 800;
  const int H = 450;

  InitWindow(W, H, "Whiteboard");

  Brush brush = {(Vector2){(float)W / 2, (float)H / 2}, RED, RAYWHITE, 15, 1};

  RenderTexture2D canvas = LoadRenderTexture(W, H);

  // Clear canvas.
  BeginTextureMode(canvas);
  ClearBackground(RAYWHITE);
  EndTextureMode();

  while (!WindowShouldClose()) {
    // Brush control
    if (IsKeyPressed(KEY_C))
      brushSwapColors(&brush);

    if (IsKeyPressed(KEY_X) && brush.size < 25)
      brush.size += 5;
    if (IsKeyPressed(KEY_Z) && brush.size > 5)
      brush.size -= 5; // Brush size

    // Move brush
    if (IsKeyDown(KEY_UP))
      brush.coords.y -= brush.velocity;
    if (IsKeyDown(KEY_DOWN))
      brush.coords.y += brush.velocity;
    if (IsKeyDown(KEY_RIGHT))
      brush.coords.x += brush.velocity;
    if (IsKeyDown(KEY_LEFT))
      brush.coords.x -= brush.velocity;

    // Update canvas.
    BeginTextureMode(canvas);
    DrawCircleV(brush.coords, brush.size, brush.primaryColor);
    EndTextureMode();

    // Drawing
    BeginDrawing();

    DrawTextureRec(canvas.texture,
                   (Rectangle){0, 0, (float)canvas.texture.width,
                               (float)-canvas.texture.height},
                   (Vector2){0, 0}, RAYWHITE); // Draw canvas

    DrawCircleLines(brush.coords.x, brush.coords.y, brush.size,
                    BLACK); // Cursor

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
