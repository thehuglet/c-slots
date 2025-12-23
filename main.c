#include "raylib.h"

struct Texture2DAtlas {
    Texture2D texture;
    int spriteHeight;
    int spriteWidth;
};

Rectangle AtlasSpriteRect(struct Texture2DAtlas atlas, int col, int row) {
    Rectangle spriteRect = {
        col * atlas.spriteWidth,
        row * atlas.spriteHeight,
        atlas.spriteWidth,
        atlas.spriteHeight,
    };
    return spriteRect;
}

int main() {
    InitWindow(800, 600, "Hello Raylib");
    SetTargetFPS(144);

    struct Texture2DAtlas atlas = {
        .texture = LoadTexture("assets/cards_small.png"),
        .spriteHeight = 41,
        .spriteWidth = 71,
    };

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Hello Raylib!", 190, 200, 20, LIGHTGRAY);

        Rectangle spriteRect = AtlasSpriteRect(atlas, 11, 2);
        DrawTextureRec(atlas.texture, spriteRect, (Vector2){100, 100}, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
