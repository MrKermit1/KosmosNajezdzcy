#include "raylib.h"

#include "enemy.h"

int main()
{

	const int SCREEN_HEIGTH = 720;
	const int SCREEN_WIDTH = 1280;

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGTH, "Epicki Kosmiczny Pojedynek");

	while (!WindowShouldClose())
	{
		Enemy enemy = Enemy(0, 0, 60, 60);
		BeginDrawing();
		ClearBackground(BLACK);
		
		enemy.Spawn();

		EndDrawing();
	}
}