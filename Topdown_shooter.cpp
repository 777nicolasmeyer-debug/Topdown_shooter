#include "raylib.h"
#include "Player.h"
#include "Bullet.h"

#include <vector>


int main()
{
    InitWindow(800, 450, "Test");
	SetTargetFPS(30);

	Projectile bullet;
    bullet.color = RED;

    Player player;
    player.position = { 400, 225 };
    player.speed = 5.0f;
    player.dimension = 50.0f;
    player.color = RED;

    std::vector<Projectile>bullets;
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
        for (Projectile& bullet : bullets) {
            bullet.Update();
            bullet.Draw();
        }
        DrawCircleV(player.GetCenter(), 5, YELLOW);

        EndDrawing();
    }

    CloseWindow();
}