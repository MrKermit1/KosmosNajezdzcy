#include "enemy.h"
#include "raylib.h"

Enemy::Enemy(){}

Enemy::Enemy(int x, int y, int width, int heigth, int speed) : Player(x, y, width, heigth, speed)
{
	
}

void Enemy::Spawn()
{ 
	DrawRectangleV(position ,size, WHITE);
}



void Enemy::Move()
{
	/*if (position.x >= 1280)
	{
		position.x = 0;
		position.y += size.y;
	}*/
	position.x += speed;
}


