#include "Player.h"
#pragma once
class House : protected Player
{
private:
	int lifePoints;
public:

	void Spawn();

	House();
	House(int x, int y, int width, int heigth, int lifePoints) : Player(x, y, width, heigth)
	{
		this->lifePoints = lifePoints;
	}
};

