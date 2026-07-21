#include "raylib.h"
#include "Player.h"

int main()
{
    InitWindow(800, 450, "Test");
	SetTargetFPS(30);

    Player player;
    player.position = { 400, 225 };
    player.speed = 5.0f;
    player.dimension = 50.0f;
    player.color = RED;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        player.Update();
		player.FaceMouse();
        player.Draw();
        EndDrawing();
    }

    CloseWindow();
}