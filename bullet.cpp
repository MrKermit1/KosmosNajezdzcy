#include "bullet.h"
#include <iostream>
Bullet::Bullet(int posX, int posY, int bulletSpeed, Color color)
{
	bulletPos.x = posX;
	bulletPos.y = posY;
	this->bulletSpeed = bulletSpeed;
	this->color = color;
	active = true;
}

Bullet::Bullet()
{}

Vector2 Bullet::getBulletPos()
{
	return bulletPos;
}

void Bullet::Activate()
{
	active = true;
}

void Bullet::Deactivate()
{
	active = false;
}

bool Bullet::isActive() const
{
	return active;
}

void Bullet::Spawn()
{
	if (active)
	{
		DrawRectangle(bulletPos.x, bulletPos.y, 5, 10, color);
	}
	
}

void Bullet::Test()
{
	std::cout << active << "\n";
}

Rectangle Bullet::getRect() const
{
	return { bulletPos.x, bulletPos.y, 5, 10 };
}
	

void Bullet::Move()
{	
	if (active)
	{
		bulletPos.y += bulletSpeed;
	}

}