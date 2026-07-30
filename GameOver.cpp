#include "GameOver.h"
#include "C:/Users/777ni/OneDrive/Documents/Projects/Libraries/raylib/w64devkit/include/raygui.h" //raygui.h

void GameOver::Draw(GameManager& gameManager) {
	BeginDrawing();
	ClearBackground(BLACK);

	DrawText("Game Over", 300, 380, 40,  RED);

	EndDrawing();
}