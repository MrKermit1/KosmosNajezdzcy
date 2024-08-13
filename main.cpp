#include "raylib.h"
#include "player.h"
#include "enemy_grid.h"
#include "obstacle.h"
#include <iostream>
const int SCREEN_HEIGTH = 1000;
const int SCREEN_WIDTH = 1280;

Enemy_grid grid;
Player player = Player(640, 900, 100, 10, 12, 4);
Obstacle obstacles[3] =
{
	Obstacle(955, 700),
	Obstacle(500, 700),
	Obstacle(10, 700)
};
int playerLife = player.getLife();
bool gameOver = false;
bool win = false;
void GUI()
{
	if (!gameOver)
	{
		DrawText(TextFormat("Score: %08i", player.getScore()), 50, 40, 20, WHITE);
		DrawText(TextFormat("Life: %02i", player.getLife()), 1150, 40, 20, WHITE);
	}
	else if(!win && gameOver) 
	{
		DrawText(TextFormat("GAME OVER\n\nYour Score: %08i", player.getScore()), (SCREEN_WIDTH / 2) - 100, SCREEN_HEIGTH / 2, 20, WHITE);
	}
	else if (win && gameOver)
	{
		DrawText(TextFormat("YOU WIN!\n\nYour Score: %08i", player.getScore()), (SCREEN_WIDTH / 2) - 100, SCREEN_HEIGTH / 2, 20, WHITE);
	}
	
}

void Reset()
{
	if (player.getLife() + 1 == playerLife)
	{
		grid.UnloadAssets();
		grid = Enemy_grid();
		grid.LoadAssets();
		player.ResetBullets();
		player.setPosX(640);
		player.setPosY(900.);
		player.setWidth(100);
		player.setHeigth(50);

		//this is so shitty
		obstacles[0] = Obstacle(955, 700);
		obstacles[1] = Obstacle(500, 700);
		obstacles[2] = Obstacle(10, 700);
		 
		playerLife--;
	}
	
	
}

void SpawnObstacles()
{
	for (int i = 0; i < 3; i++)
	{
		obstacles[i].Spawn();
	}
}

void CheckPlayerWithObstacles(Obstacle *buff)
{
	if (buff != nullptr)
	{
		for (int i = 0; i < 3; i++)
		{
			auto& bullets = player.getBulltets();
			for (auto it = bullets.begin(); it != bullets.end();)
			{
				if (it->isActive() && (buff + i)->CheckCollisionWithBullets(it))
				{
					it = bullets.erase(it);
				}
				else {
					++it;
				}
			}
		}
	}
	else {
		std::cout << "null pointer detected!!!\n";
	}
	
}

void CheckGameOverConditions()
{
	if (grid.isGridEmpty() || player.getLife() == 0)
	{
		if (grid.isGridEmpty())
		{
			win = true;
		}
		gameOver = true;
	}
}

int main()
{

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGTH, "Epicki Kosmiczny Pojedynek");
	SetTargetFPS(60);

	grid.LoadAssets();
	player.LoadTextures();
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		GUI();

		if (!gameOver)
		{

			player.Move();
			player.Shoot();
			grid.CheckPlayerHits(player);
			grid.CheckAlienHits(player, obstacles);
			CheckPlayerWithObstacles(obstacles);
			grid.Move();
			grid.Shoot();
			Reset();
			CheckGameOverConditions();
			grid.Spawn();
			SpawnObstacles();
			player.Spawn();

		}
		EndDrawing();
	}
	grid.UnloadAssets();
	player.UnloadTextures();
	CloseWindow();

	return 0;
}

/*
	TODO:
		-GAME:
			-INPUT NAME OF PLAYER
			-MAYBE COMPILE TO WEB ASM
			-DB:
				-SQL CONNECTION
				-SAVING SCORES IN DB
				-SECURE DB USER INFO
*/