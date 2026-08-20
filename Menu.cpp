#define RAYGUI_IMPLEMENTATION
#include "Menu.h"
#include "raylib.h"
#include "C:/Users/777ni/OneDrive/Documents/Projects/Libraries/raylib/w64devkit/include/raygui.h" //raygui.h

void Menu::Draw(GameManager& gameManager, Texture2D background)
{
    BeginDrawing();
    ClearBackground(BLACK);
    DrawTexture(
        background,
        0,
        0,
        WHITE
    );

    Rectangle playButton = { 300, 250, 200, 50 };
    if (GuiButton(playButton, "Play")) {
        gameManager.state = GameState::Playing;
    }

    Rectangle shopButton = { 300, 320, 200, 50 };
    if (GuiButton(shopButton, "Shop"))
    {
        gameManager.state = GameState::Shop;
    }

    EndDrawing();
}