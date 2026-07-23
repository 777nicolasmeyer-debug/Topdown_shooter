#include "raylib.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

#include <vector>


int main()
{
    InitWindow(800, 450, "Test");
	SetTargetFPS(30);

    Player player;
    player.position = { 400, 225 };
    player.speed = 5.0f;
    player.dimension = 50.0f;
    player.color = RED;

    std::vector<Projectile>bullets;
    
    Enemy enemy;
    enemy.position = { 450 , 200 };
    enemy.speed = 2.5f;
    enemy.width = 50.0f;
    enemy.height = 50.0f;
    enemy.color = BLUE;

    while (!WindowShouldClose())
    {
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            bullets.push_back(player.Shoot());
		}

        BeginDrawing();
        ClearBackground(BLACK);

        player.Update();
		player.FaceMouse();
        player.Draw();

        enemy.Update(player);
        enemy.FacePlayer(player);
        enemy.Draw();

        for (Projectile& bullet : bullets) {
            bullet.Update();
            bullet.Draw();
        }
        DrawCircleV(player.GetCenter(), 5, YELLOW);

        EndDrawing();
    }

    CloseWindow();
}