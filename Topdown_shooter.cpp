

#include "raylib.h"
#include "GameManager.h"
#include "GameOver.h"
#include "GameLogic.h"
#include "Menu.h"
#include "Shop.h"

#include <vector>

constexpr int SCREENWIDTH = 800;
constexpr int SCREENHEIGHT = 800;

int main()
{
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Test");
	SetTargetFPS(30);

    Game game;
    Menu menu;
    Shop shop;
    GameOver gameOver;

    GameManager gameManager;

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_P)) {
            gameManager.state = GameState::Menu;
        }

        switch (gameManager.state) {
        case GameState::Menu:
            menu.Draw(gameManager);
            break;

        case GameState::Playing:
            game.Run(SCREENWIDTH, SCREENHEIGHT, gameManager);
            break;
        
        case GameState::Shop:
            shop.Draw(game.GetPlayer());
            break;

        case GameState::GameOver:
            gameOver.Draw(gameManager);
            break;
        }
    }
 CloseWindow();
}