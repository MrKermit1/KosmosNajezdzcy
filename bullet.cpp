#include "bullet.h"
#include <iostream>
Bullet::Bullet(int posX, int posY, int bulletSpeed)
{
	bulletPos.x = posX;
	bulletPos.y = posY;
	this->bulletSpeed = bulletSpeed;

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

	
	DrawRectangle(bulletPos.x, bulletPos.y, 2, 8, RED);


}

void Bullet::Move()
{
	std::cout << active << "\n";

	
	bulletPos.y += bulletSpeed;


	
}