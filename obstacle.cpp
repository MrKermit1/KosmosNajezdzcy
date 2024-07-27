#include "obstacle.h"

void Obstacle::Init()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			bricks[j][i] = Brick(i * 105 + position.x, j * 55 + position.y, 100, 50);
		}
	}
}

Obstacle::Obstacle(int posX, int posY) : GameObject(posX, posY)
{
	Init();
}

void Obstacle::Spawn()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			bricks[j][i].Spawn();
		}
	}
}

bool Obstacle::CheckCollisionWithBullets(std::vector<Bullet>::iterator it)
{

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (bricks[j][i].isDestroyed()) continue;
			if (it->isActive() && CheckCollisionRecs(bricks[j][i].getRect(), it->getRect()))
			{
				bricks[j][i].Destroy();
				bricks[j][i].setColor(BLACK);
				return true;
			}
		}
	}

	return false;
}



