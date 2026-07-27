#define RAYGUI_IMPLEMENTATION

#include "raylib.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Spawn_logic.h"
#include "Collisions.h"
#include "C:/Users/777ni/OneDrive/Documents/Projects/Libraries/raylib/w64devkit/include/raygui.h"

#include <vector>

constexpr int SCREENWIDTH = 800;
constexpr int SCREENHEIGHT = 800;

int main()
{
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Test");
	SetTargetFPS(30);

    Player player;
    player.position = { SCREENHEIGHT / 2, SCREENHEIGHT / 2 };
    player.speed = 5.0f;
    player.damage = 5;
    player.dimension = 50.0f;
    player.color = RED;

    std::vector<Projectile>bullets;

    std::vector<Enemy>enemies;
  
    SpawnLogic spawnLogic;

    Collisions collision;

    while (!WindowShouldClose())
    {
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            bullets.push_back(player.Shoot());
		}

        if (spawnLogic.CanSpawn())
        {
            Enemy enemy;

            enemy.position = spawnLogic.Spawn(SCREENWIDTH, SCREENHEIGHT);
            enemy.speed = GetRandomValue(1,4);
            enemy.width = 50.0f;
            enemy.height = 50.0f;
            enemy.color = BLUE;
            enemy.active = true;
            enemies.push_back(enemy);
        }
        
        BeginDrawing();
        ClearBackground(BLACK);

        player.Update();
		player.FaceMouse();
        player.Draw();

        // Draw and update enemies
        for (Enemy& enemy : enemies)
        {
            if (enemy.active)
            {
                enemy.Update(player);
                enemy.FacePlayer(player);
                enemy.Draw();
            }
        }

        // Update and draw bullets
        for (Projectile& bullet : bullets) {
            bullet.Update();
            bullet.Draw();

            // Check collision with all enemies
            for (Enemy& enemy : enemies) {
                if (enemy.active && collision.isColliding(bullet, enemy)) {
                    enemy.TakeDamage(player.damage);
                    bullet.active = false;
                }
            }
        }

        // Remove dead enemies
        for (size_t i = 0; i < enemies.size();) {
            if (!enemies[i].active) {
                enemies.erase(enemies.begin() + i);
            }
            else {
                i++;
            }
        }
        DrawCircleV(player.GetCenter(), 5, YELLOW);

        EndDrawing();
    }
 CloseWindow();
}