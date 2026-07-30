#include "GameLogic.h"
#include "raylib.h"
#include "GameManager.h"
#include "HandleDamage.cpp"

class GameManager;
class HandleDamage handleDamage;

void Game::Run(int SCREENWIDTH, int SCREENHEIGHT, GameManager& gameManager) {
	if (player.active) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            bullets.push_back(player.Shoot());
        }

        if (spawnLogic.CanSpawn())
        {
            Enemy enemy;

            enemy.position = spawnLogic.Spawn(SCREENWIDTH, SCREENHEIGHT);
            enemy.speed = GetRandomValue(1, 4);
            enemy.width = 50.0f;
            enemy.height = 50.0f;
            enemy.color = BLUE;
            enemy.active = true;
            enemy.health = 10;
            enemy.damage = 5.0f;
            enemies.push_back(enemy);
        }

        BeginDrawing();
        ClearBackground(BLACK);

        DrawText(TextFormat("Health: %d", player.health), 10, 10, 20, GREEN);
        DrawText(TextFormat("Gold: %d", player.money), 10, 30, 20, GREEN);

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
            if (!bullet.active) {
                continue;
            }
            bullet.Update();
            bullet.Draw();

            if (bullet.position.x <= 0 || bullet.position.x >= SCREENWIDTH || bullet.position.y <= 0 || bullet.position.y >= SCREENHEIGHT) {
                bullet.active = false;
            }

            // Check collision with all enemies
            for (Enemy& enemy : enemies) {
                if (enemy.active && collision.isColliding(bullet, enemy)) {
                    enemy.TakeDamage(player.damage, enemy);
                    bullet.active = false;
                    break;
                }
            }
        }

        for (Enemy& enemy : enemies) {
            handleDamage.DamagePlayer(player, enemy);
        }

        // Remove dead enemies
        for (size_t i = 0; i < enemies.size();) {
            if (!enemies[i].active) {
                enemies[i].RewardPlayer(player);
                enemies.erase(enemies.begin() + i);
            }
            else {
                i++;
            }
        }
        DrawCircleV(player.GetCenter(), 5, YELLOW);

        EndDrawing();

    }  
    else if (!player.active) {
        gameManager.state = GameState::GameOver;
    }

	}
Player& Game::GetPlayer() {
    return player;
}