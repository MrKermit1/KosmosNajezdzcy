#include "enemy.h"
#include "raylib.h"
#include "bullet.h"

Enemy::Enemy(){}

Enemy::Enemy(int x, int y, int width, int heigth, int speed, Color color) : GameObject(x, y, width, heigth, speed)
{
	this->color = color;
	isAlive = true;
	shootOut = false;
}

void Enemy::setColor(Color color)
{
	this->color = color;
}

void Enemy::setShotout(bool shootout)
{
	shootOut = shootout;
}

void Enemy::Spawn()
{ 
	DrawRectangleV(position ,size, color);
	if (!(bullet.getPosition().y >= GetScreenHeight() - 10) && bullet.isActive())
	{
		bullet.Spawn();
	}
}

Bullet Enemy::getBullet()
{
	return bullet;
}

void Enemy::Move()
{
	position.x += speed;
	
	if (!(bullet.getPosition().y >= GetScreenHeight() - 10) && bullet.isActive())
	{
		bullet.Move();
	}

}

bool Enemy::IsColorBlack(Color color)
{
	return (color.r == BLACK.r) && (color.g == BLACK.g) && (color.b == BLACK.b) && (color.a == BLACK.a);
}

void Enemy::Shoot()
{
	if (!IsColorBlack(color))
	{
		if (!shootOut)
		{
			shootOut = true;
			bullet = Bullet(position.x, position.y, 5, 10, 4, RED);
		}
	}
}

void Enemy::setIsAlive(bool alive)
{
	isAlive = alive;
}

bool Enemy::getIsAlive()
{
	return isAlive;
}