#include "enemy_grid.h"

void Enemy_grid::Init()
{

	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			//maybe i should init those values idk
			grid[i][j] = Enemy(i * 60 + 5, j * 60 + 5, 55, 55, 2);
		}
	}
}

Enemy_grid::Enemy_grid()
{
	Init();
}

void Enemy_grid::Spawn()
{
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			grid[i][j].Spawn();
		}
	}
}

void Enemy_grid::Lower()
{
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			grid[i][j].setPosX(i * 60);
			grid[i][j].setPosY( grid[i][j].getPosY() + grid[i][j].getHeigth());
		}
	}
}

void Enemy_grid::Move()
{
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (grid[i][j].getPosX() >= 1280 - grid[i][j].getWidth())
			{
				Lower();
			}
			grid[i][j].Move();
		}
	}
}

