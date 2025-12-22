#include "raylib.h"

Rectangle AtlasRect(Rectangle atlasRect, int x, int y, int spriteWidth, int spriteHeight) {
    Rectangle sprite = {
        atlasRect.x + x * spriteWidth,
        atlasRect.y + y * spriteHeight,
        spriteWidth,
        spriteHeight
    };
    return sprite;
}


int main() {
    InitWindow(800, 600, "Hello Raylib");
    SetTargetFPS(144);

    Texture2D atlas = LoadTexture("assets/cards_small.png");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Hello Raylib!", 190, 200, 20, LIGHTGRAY);

        Rectangle spriteRect = AtlasRect((Rectangle){0,0, atlas.width, atlas.height}, 1, 2, 32, 32);
        DrawTextureRec(atlas, spriteRect, (Vector2){100,100}, WHITE);


        EndDrawing();
    }


    CloseWindow();
    return 0;
}
