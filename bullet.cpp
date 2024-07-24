#include "bullet.h"
#include <iostream>
Bullet::Bullet(int posX, int posY, int width, int heigth, int speed, Color color) : GameObject(posX, posY, width, heigth, speed)
{
	this->color = color;
	active = true;
}

Bullet::Bullet()
{}


void Bullet::Activate()
{
	active = true;
}

void Bullet::Deactivate()
{
	active = false;
	std::cout << "bullet is now: " << active << "\n";
}

bool Bullet::isActive() const
{
	return active;
}

void Bullet::Spawn()
{
	if (active)
	{
		DrawRectangle(position.x, position.y, size.x, size.y, color);
	}
	
}

void Bullet::Test()
{
	std::cout << active << "\n";
}

Rectangle Bullet::getRect() const
{
	return { position.x, position.y, size.x, size.y };
}
	

void Bullet::Move()
{	
	if (active)
	{
		position.y += speed;
	}

}