#include "GameLogic.h"
#include "raylib.h"
#include "GameManager.h"
#include "HandleDamage.cpp"

class GameManager;
class HandleDamage handleDamage;
float shootTimer = GetRandomValue(1, 3);

void Game::Run(int SCREENWIDTH, int SCREENHEIGHT, GameManager& gameManager) {
    spawnLogic.PassData(player.position);
    Vector2 playerPos = player.GetCenter();

    if (playerPos.x > camera.target.x + 100)
    {
        camera.target.x = playerPos.x - 100;
    }
    else if (playerPos.x < camera.target.x - 100)
    {
        camera.target.x = playerPos.x + 100;
    }
    if (playerPos.y > camera.target.y + 100)
    {
        camera.target.y = playerPos.y - 100;
    }
    else if (playerPos.y < camera.target.y - 100)
    {
        camera.target.y = playerPos.y + 100;
    }
	if (player.active) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            bullets.push_back(player.Shoot());
            PlaySound(blasterSound);
        }

        if (spawnLogic.CanSpawn() && enemies.size() <= 20)
        {
            Enemy enemy;

            enemy.position = spawnLogic.Spawn();
            enemies.push_back(enemy);
        }

        

        BeginDrawing();
        ClearBackground(BLACK);

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

        
            for (Enemy& enemy : enemies)
            {
                enemy.shootTimer -= GetFrameTime();

                if (enemy.shootTimer <= 0)
                {
                    enemy.shootTimer = (float)GetRandomValue(5, 10);
                    bullets.push_back(enemy.Shoot());
                    PlaySound(blasterSound);
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

Texture2D Game::GetBackground() {
    return background;
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
    bgMusic = LoadMusicStream("../../../assets/spaceMusic.mp3");
    blasterSound = LoadSound("../../../assets/blaster.mp3");
    btnClick = LoadSound("../../../assets/click.mp3");
    gameMusic = LoadMusicStream("../../../assets/gameplayMusic.mp3");
    deathMusic = LoadMusicStream("../../../assets/death.mp3");
}

void Game::Reset(GameManager& gameManager) {
    gameManager.state = GameState::Menu;
    player.Reset();
    enemies.clear();
    bullets.clear();
    camera.target = player.GetCenter();
}