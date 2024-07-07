#include "raylib.h"

#include "enemy_grid.h"

int main()
{

	const int SCREEN_HEIGTH = 720;
	const int SCREEN_WIDTH = 1280;
	//Enemy enemy = Enemy(100, 0, 60, 60, 3);
	Enemy_grid grid;
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGTH, "Epicki Kosmiczny Pojedynek");

	

	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		
		BeginDrawing();
		ClearBackground(BLACK);

		grid.Spawn();
		grid.Move();

		EndDrawing();
	}
	CloseWindow();
}