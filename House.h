#include "player.h"
#pragma once
class House : protected Player
{
private:
	int lifePoints;
public:

	void Spawn();
	void Destroy();

	House();
	House(float x, float y, int width, int heigth, int lifePoints);

	void setLifePoints();

	int getLifePoints();
};

