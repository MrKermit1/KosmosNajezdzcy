#include "enemy_grid.h"
#include <iostream>
#include "raylib.h"
void Enemy_grid::Init()
{
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			isAlive[j][i] = true;
			aliens[j][i] = Enemy(i * 60 + 5, j * 60 + 5, 55, 55, 3, WHITE);
		}
	}
	/*for (int i = 0; i < cols; i++)
	{
		grid[4][i] = true;
	}*/
}

void Enemy_grid::CheckCollision(Player& player)
{
	auto& bullets = player.getBulltets();
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (!isAlive[j][i]) continue;
			for (auto& bulletP : bullets)
			{
				auto it = bullets.begin();
				while (it != bullets.end()) 
				{
					if (bulletP.isActive() && CheckCollisionRecs(aliens[j][i].getRect(), bulletP.getRect()))
					{
						aliens[j][i].setColor(BLACK);
						isAlive[j][i] = false;
						bulletP.Deactivate();
						player.DeleteBullet(it);
						//bulletP.Test();
						std::cout << "Bullet hit alien at (" << j << ", " << i << ")\n";
						break;
					}
					else {
						it++;
					}
					
				}
				
			}
		}
	}
}

Enemy_grid::Enemy_grid()
{
	Init();
	lastShotTime = 0.0;
}

void Enemy_grid::Lower(bool border)
{
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (border)
			{
				aliens[j][i].setPosX(1280 - (i * 60 + 1));
			}
			else
			{
				aliens[j][i].setPosX(0 + (i * 60 + 1));
			}
			aliens[j][i].setSpeed(aliens[j][i].getSpeed() * -1);
			aliens[j][i].setPosY(aliens[j][i].getPosY() + aliens[j][i].getHeigth());

		}
	}
}

void Enemy_grid::Shoot()
{
	double time = GetTime();
	if (time - lastShotTime >= shootInterval)
	{
		int randomCol = GetRandomValue(0, cols - 1);
		int randomRow = GetRandomValue(0, rows - 1);
		if (isAlive[randomRow][randomCol])
		{
			aliens[randomRow][randomCol].Shoot();
			lastShotTime = GetTime();
		}
	}
	

}

void Enemy_grid::Move()
{
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (aliens[j][i].getPosX() >= 1280)
			{
				Lower(true);
			}
			if (aliens[j][i].getPosX() <= 0 - aliens[j][i].getWidth())
			{
				Lower(false);
			}
			aliens[j][i].Move();
		}
	}
}

void Enemy_grid::Spawn()
{

	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (isAlive[j][i])
			{
				//DrawRectangle(i * 60 + 5, j * 60 + 5, 55, 55, WHITE);
				aliens[j][i].Spawn();

			}
			
		}
	}
}