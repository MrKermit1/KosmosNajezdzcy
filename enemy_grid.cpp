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
	speed = 5;
	quanity = rows * cols;
}

//Check if player hit enemy
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
				
				for (auto it = bullets.begin(); it != bullets.end();)
				{
					if (bulletP.isActive() && CheckCollisionRecs(aliens[j][i].getRect(), bulletP.getRect()))
					{
						aliens[j][i].setIsAlive(false);
						it = bullets.erase(it);
						player.addScore(100);
						std::cout << "Bullet hit alien at (" << j << ", " << i << ")\n";
						quanity--;
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
//Check if alien hit obstacle
void Enemy_grid::CheckAlienHits(Player& player, Obstacle* obstacles)
{
	if (obstacles != nullptr)
	{
		for (int i = 0; i < cols; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				auto& bullets = aliens[j][i].getBulltets();
				for (int x = 0; x < 3; x++)
				{
					for (auto it = bullets.begin(); it != bullets.end();)
					{
						if (it->isActive() && (obstacles + x)->CheckCollisionWithBullets(it))
						{
							it = bullets.erase(it);
						}
						else {
							++it;
						}
					}
				}
				
			}
		}

	}
	else {
		std::cout << "null pointer detected!!!\n";
	}
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			auto& bullets = aliens[j][i].getBulltets();
			for (auto it = bullets.begin(); it != bullets.end();)
			{
				if (it->isActive() && CheckCollisionRecs(it->getRect(), player.getRect()))
                {
                    it->Deactivate();
                    it = bullets.erase(it);
                    player.setLife(player.getLife() - 1);
                }
                else
                {
                    ++it;
                }
			}
		}
	}
	
}
//Moves down after hitting edge of screen
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
//It makes random alien shoot
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
//Moves grid of aliens
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

bool Enemy_grid::isGridEmpty()
{
	if (quanity == 0)
	{
		return true;
	}

	return false;
}