

#include "raylib.h"
#include "GameManager.h"
#include "GameOver.h"
#include "GameLogic.h"
#include "Menu.h"
#include "Shop.h"

constexpr int SCREENWIDTH = 800;
constexpr int SCREENHEIGHT = 800;

int main()
{
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Test");
    InitAudioDevice();
	SetTargetFPS(30);

    Game game;
    Menu menu;
    Shop shop;
    GameOver gameOver;

    GameManager gameManager;
    game.bgMusic.looping = true;
    game.gameMusic.looping = true;
    game.deathMusic.looping = true;


    while (!WindowShouldClose())
    {

        if (IsKeyPressed(KEY_M)) {
            gameManager.state = GameState::Menu;
        }
        if (IsKeyPressed(KEY_R)) {
            game.Reset(gameManager);
        }
        

        switch (gameManager.state) {
        case GameState::Menu:
            StopMusicStream(game.gameMusic);
            StopMusicStream(game.deathMusic);
            if (!IsMusicStreamPlaying(game.bgMusic)) {
                PlayMusicStream(game.bgMusic);
            }
            menu.Draw(gameManager, game.GetBackground());
            UpdateMusicStream(game.bgMusic);
            break;

        case GameState::Playing:
            StopMusicStream(game.bgMusic);
            StopMusicStream(game.deathMusic);
            if (!IsMusicStreamPlaying(game.gameMusic)) {
                PlayMusicStream(game.gameMusic);
            }
            game.Run(SCREENWIDTH, SCREENHEIGHT, gameManager);
            UpdateMusicStream(game.gameMusic);
            break;

        case GameState::Shop:
            StopMusicStream(game.gameMusic);
            StopMusicStream(game.deathMusic);
            if (!IsMusicStreamPlaying(game.bgMusic)) {
                PlayMusicStream(game.bgMusic);
            }
            shop.Draw(game.GetPlayer(), game.GetBackground());
            UpdateMusicStream(game.bgMusic);
            break;

        case GameState::GameOver:
            StopMusicStream(game.bgMusic);
            StopMusicStream(game.gameMusic);
            if (!IsMusicStreamPlaying(game.deathMusic)) {
                PlayMusicStream(game.deathMusic);
            }
            gameOver.Draw(gameManager);
            UpdateMusicStream(game.deathMusic);
            break;
        }
    }
 CloseWindow();
}