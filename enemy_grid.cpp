#include "enemy_grid.h"
#include <iostream>
#include "raylib.h"
void Enemy_grid::Init()
{
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			aliens[j][i] = Enemy(i * 50 + 5, j * 50 + 100, 45, 45, 1, WHITE);
		}
	}
}

Enemy_grid::Enemy_grid()
{
	Init();
	lastShotTime = 0.0;
}

void Enemy_grid::CheckPlayerHits(Player& player)
{
	auto& bullets = player.getBulltets();
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (!aliens[j][i].getIsAlive()) continue;
			for (auto& bulletP : bullets)
			{
				auto it = bullets.begin();
				while (it != bullets.end()) 
				{
					if (bulletP.isActive() && CheckCollisionRecs(aliens[j][i].getRect(), bulletP.getRect()))
					{
						aliens[j][i].setColor(BLACK);
						aliens[j][i].setIsAlive(false);
						player.DeleteBullet(it);
						player.addScore(100);
						std::cout << "Bullet hit alien at (" << j << ", " << i << ")\n";
						std::cout << "Player score: "<<player.getScore()<<"\n";
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
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (aliens[j][i].getBullet().isActive() && CheckCollisionRecs(aliens[j][i].getBullet().getRect(), player.getRect()))
			{
				player.setLife(player.getLife() - 1);
			}
		}
	}
}

void Enemy_grid::Lower()
{
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			aliens[j][i].setPosY(aliens[j][i].getPosY() + aliens[j][i].getHeigth());
			if (aliens[j][i].getSpeed() < 0)
			{
				aliens[j][i].setSpeed(aliens[j][i].getSpeed() -1);
			}
			else if (aliens[j][i].getSpeed() > 0)
			{
				aliens[j][i].setSpeed(aliens[j][i].getSpeed() + 1);
			}
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
		if (aliens[randomRow][randomCol].getIsAlive())
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
			if (aliens[j][i].getIsAlive())
			{
				aliens[j][i].Spawn();
			}
			
		}
	}
}