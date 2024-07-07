#include "house.h"

House::House(float x, float y, int width, int heigth, int lifePoints, int speed) : Player(x, y, width, heigth, speed)
{
	this->lifePoints = lifePoints;
}
