#include "enemy.h"
#include "raylib.h"

Enemy::Enemy(){}

Enemy::Enemy(int x, int y, int width, int heigth) : Player(x, y ,width, heigth)
{
	//init basic formation for enemy
	//maybe i should do it in seperate class but who cares
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			formation[i][j] = true;
		}
	}
}

void Enemy::Spawn()
{ 
	Vector2 spacer;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			spacer.x = j;
			spacer.y = j;
			if (formation[i][j])
			{
				DrawRectangle(j * size.y + 1, i * size.y + 1, size.x - 1, size.y - 1, WHITE);
			}
			
		}
	}
}

void Enemy::Move()
{

}
