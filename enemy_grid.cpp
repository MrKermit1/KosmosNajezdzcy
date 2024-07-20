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

void Enemy_grid::CheckPlayerHits(Player& player)
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
						player.DeleteBullet(it);
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

void Enemy_grid::CheckAlienHits(Player& player)
{

}



Enemy_grid::Enemy_grid()
{
	Init();
	lastShotTime = 0.0;
}

void Enemy_grid::Lower()
{
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{


			aliens[j][i].setPosY(aliens[j][i].getPosY() + aliens[j][i].getHeigth());
			aliens[j][i].setSpeed(aliens[j][i].getSpeed() * -1);
			

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
	bool shouldLower = false;

	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (aliens[j][i].getPosX() >= 1280 - aliens[j][i].getWidth() || aliens[j][i].getPosX() <= 0)
			{
				shouldLower = true;
				break;
			}
		}
		if (shouldLower)
		{
			break;
		}
	}

	if (shouldLower)
	{
		Lower();
	}

	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
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