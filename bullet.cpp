#include "bullet.h"
#include <iostream>
Bullet::Bullet(int posX, int posY, int bulletSpeed, Color color)
{
	bulletPos.x = posX;
	bulletPos.y = posY;
	this->bulletSpeed = bulletSpeed;
	this->color = color;

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

bool Bullet::isActive()
{
	return active;
}

void Bullet::Spawn()
{

	DrawRectangle(bulletPos.x, bulletPos.y, 5, 10, color);

}
	

void Bullet::Move()
{	
	bulletPos.y += bulletSpeed;	
}