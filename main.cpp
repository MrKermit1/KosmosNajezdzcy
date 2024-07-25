#include "raylib.h"
#include "player.h"
#include "enemy_grid.h"
#include <iostream>
const int SCREEN_HEIGTH = 1000;
const int SCREEN_WIDTH = 1280;
Enemy_grid grid;
Player player = Player(640, 900, 100, 50, 12, 4);
int playerLife = player.getLife();
bool gameOver = false;
void GUI()
{
	if (!gameOver)
	{
		DrawText(TextFormat("Score: %08i", player.getScore()), 50, 40, 20, WHITE);
		DrawText(TextFormat("Life: %02i", player.getLife()), 1150, 40, 20, WHITE);
	}
	else {
		DrawText(TextFormat("GAME OVER\n\nYour Score: %08i", player.getScore()), (SCREEN_WIDTH / 2) - 100, SCREEN_HEIGTH / 2, 20, WHITE);
	}
	
}

void Reset()
{
	if (player.getLife() + 1 == playerLife)
	{
		grid = Enemy_grid();
		player.ResetBullets();
		player.setPosX(640);
		player.setPosY(900.);
		player.setWidth(100);
		player.setHeigth(50);

		
		playerLife--;

		if (player.getLife() == 0)
		{
			gameOver = true;
		}
	}
	
	
}

int main()
{



	InitWindow(SCREEN_WIDTH, SCREEN_HEIGTH, "Epicki Kosmiczny Pojedynek");

	SetTargetFPS(60);
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
			grid.CheckAlienHits(player);
			grid.Move();
			grid.Shoot();
			Reset();
			grid.Spawn();
			player.Spawn();

		}
		EndDrawing();
	}
	CloseWindow();

	return 0;
}