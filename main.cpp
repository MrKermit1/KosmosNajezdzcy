#include "raylib.h"
#include "Player.h"
#include "enemy_grid.h"



int main()
{

	const int SCREEN_HEIGTH = 1000;
	const int SCREEN_WIDTH = 1280;
	//Enemy enemy = Enemy(100, 0, 60, 60, 3);
	Enemy_grid grid;
	Player player = Player(640, 900, 100, 50, 12);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGTH, "Epicki Kosmiczny Pojedynek");

	SetTargetFPS(60);
	while (!WindowShouldClose())
	{


		player.Move();
		player.Shoot();
		grid.CheckPlayerHits(player); 
		grid.Move();
		grid.Shoot();


		BeginDrawing();
		ClearBackground(BLACK);
		grid.Spawn();
		player.Spawn();
		EndDrawing();
	}
	CloseWindow();

	return 0;
}