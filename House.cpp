#include "house.h"

House::House(float x, float y, int width, int heigth, int lifePoints) : Player(x, y, width, heigth)
{
	this->lifePoints = lifePoints;
}
