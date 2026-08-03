#include "GameLogic.h"
#include "raylib.h"
#include "GameManager.h"
#include "HandleDamage.cpp"

class GameManager;
class HandleDamage handleDamage;
float shootTimer = GetRandomValue(1, 3);


void Game::Run(int SCREENWIDTH, int SCREENHEIGHT, GameManager& gameManager) {
	if (player.active) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            bullets.push_back(player.Shoot());
        }

        if (spawnLogic.CanSpawn() && enemies.size() <= 20)
        {
            Enemy enemy;

            enemy.position = spawnLogic.Spawn(SCREENWIDTH, SCREENHEIGHT);
            enemies.push_back(enemy);
        }

        

        BeginDrawing();
        ClearBackground(BLACK);

        camera.target = player.GetCenter();
        BeginMode2D(camera);
        
        for (int x = -5; x <= 5; x++)
        {
            for (int y = -5; y <= 5; y++)
            {
                DrawTexture(
                    background,
                    x * background.width,
                    y * background.height,
                    WHITE
                );
            }
        }


        player.Update();
        player.FaceMouse(camera);
       // player.DrawRec();
        player.DrawTex();
        

        // Draw and update enemies
        for (Enemy& enemy : enemies)
        {
            if (enemy.active)
            {
                enemy.Update(player);
                enemy.FacePlayer(player);
                // enemy.DrawRec();
                enemy.DrawTex();
            }
        }

        // Update and draw bullets
        for (Projectile& bullet : bullets) {
            if (!bullet.active) {
                continue;
            }
            bullet.Update();
            bullet.Draw();

            // Check collision with all enemies
            for (Enemy& enemy : enemies) {
                if (enemy.active && collision.isColliding(bullet, enemy) && bullet.fromPlayer) {
                    enemy.TakeDamage(player.damage, enemy);
                    bullet.active = false;
                    break;
                }
            }
        }

        
        for (Enemy& enemy : enemies) {
            for (Enemy& enemy : enemies)
            {
                enemy.shootTimer -= GetFrameTime();

                if (enemy.shootTimer <= 0)
                {
                    enemy.shootTimer = (float)GetRandomValue(5, 10);
                    bullets.push_back(enemy.Shoot());
                }
            }
        }

        for (Enemy& enemy : enemies) {
            for (Projectile& bullet : bullets) {
                handleDamage.DamagePlayer(player, enemy, bullet);
            }
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
        //DrawCircleV(player.GetCenter(), 5, YELLOW);

        EndMode2D();

        DrawText(TextFormat("Health: %d", player.health), 10, 10, 20, GREEN);
        DrawText(TextFormat("Gold: %d", player.money), 10, 30, 20, GREEN);

        EndDrawing();

    }  
    else if (!player.active) {
        gameManager.state = GameState::GameOver;
    }

	}
Player& Game::GetPlayer() {
    return player;
}

Game::Game() {

    camera.target = player.GetCenter();
    camera.offset = {
        GetScreenWidth() / 2.0f,
        GetScreenHeight() / 2.0f
    };
    camera.zoom = 1.0f;
    camera.rotation = 0.0f;

    background = LoadTexture("../../../assets/background.png");
    
}