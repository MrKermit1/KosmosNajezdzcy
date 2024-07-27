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
	for (auto& bullet : bullets) {
		if (bullet.isActive() && !(bullet.getPosition().y >= GetScreenHeight() - 10)) {
			bullet.Spawn();
		}
	}
	DrawRectangleV(position ,size, color);
}

Bullet Enemy::getBullet()
{
	return bullet;
}

void Enemy::Move()
{
	for (auto& bullet : bullets) {
		if (bullet.isActive() && !(bullet.getPosition().y >= GetScreenHeight() - 10)) {
			bullet.Move();
		}
	}
	position.x += speed;
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
			//bullet = Bullet(position.x, position.y, 5, 10, 4, RED);
			bullets.push_back(Bullet(position.x + size.x / 2, position.y, 5, 10, 5, RED));
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

void Enemy::DeleteBullet(std::vector<Bullet>::iterator it)
{
	bullets.erase(it);
}

std::vector<Bullet>& Enemy::getBulltets()
{
	return bullets;
}