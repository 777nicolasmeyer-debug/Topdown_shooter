#include "C:/Users/777ni/OneDrive/Documents/Projects/Libraries/raylib/w64devkit/include/raygui.h" //raygui.h
#include "raylib.h"
#include "Shop.h"

void Shop::Draw(Player& player, Texture2D background)
{
    BeginDrawing();
    ClearBackground(BLACK);
    DrawTexture(
        background,
        0,
        0,
        WHITE
    );

    DrawText(TextFormat("Health: %d", player.health), 10, 10, 20, GREEN);
    DrawText(TextFormat("Gold: %d", player.money), 10, 30, 20, GREEN);

    Rectangle damageButton = { 300, 250, 200, 50 };
    if (GuiButton(damageButton, "Damage Upgrade: 100 Gold")) {

        if (player.money >= 100) {
            player.damage += 5;
            player.money -= 100;
        }
    }

    Rectangle healthButton = { 300, 320, 200, 50 };
    if (GuiButton(healthButton, "Health Upgrade: 150 Gold ")) {
       
        if (player.money >= 150) {
            player.health += 10;
            player.money -= 150;
        }
    }

    EndDrawing();
}