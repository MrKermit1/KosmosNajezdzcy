#include "brick.h"

Brick::Brick(float posX, float posY, float width, float heigth) : GameObject(posX, posY, width, heigth)
{
	color = { 255, 87, 51 , 255 };
	destroyed = false;
}

Brick::Brick(){}

void Brick::Spawn()
{
	if (!destroyed)
	{
		DrawRectangleV(position, size, color);
	}

}

bool Brick::isDestroyed()
{
	return destroyed;
}

void Brick::Destroy()
{
	destroyed = true;
}

void Brick::setColor(Color color)
{
	this->color = color;
}