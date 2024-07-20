#include "player.h"



Player::Player(float x, float y, float width, float heigth, int speed)
{
	position.x = x;
	position.y = y;
	this->size.x = width;
	this->size.y = heigth;
	this->speed = speed;
}

Player::Player(){}

void Player::DeleteBullet(std::vector<Bullet>::iterator it)
{
	bullets.erase(it);
	std::cout << "Delted Bullet\n";
}

void Player::Shoot()
{
	if (IsKeyPressed(KEY_SPACE)) {
		bullets.push_back(Bullet(position.x + size.x / 2, position.y, -5, YELLOW));
	}
}

/*void Player::DeleteBullets() {
	for (auto x = bullets.begin(); x != bullets.end();) {
		if (x->active == false) {
			x = bullets.erase(x);
			
		}
		else {
			++x;
		}
	}
}*/

std::vector<Bullet>& Player::getBulltets()
{
	return bullets;
}

Rectangle Player::getRect()
{
	return { position.x, position.y, size.x, size.y };
}

void Player::Move()
{
	for (auto& bullet : bullets)
	{
		if (bullet.isActive())
		{
			bullet.Move();
		}
	}


	if (IsKeyDown(KEY_A))
	{
		position.x -= speed;
	}

	if (IsKeyDown(KEY_D))
	{
		position.x += speed;
	}
}

void Player::Spawn()
{
	DrawRectangleV(position, size, WHITE);
	for (auto& bullet : bullets) {
		if (bullet.isActive()) {
			bullet.Spawn();
		}
	}
}

float Player::getPosX()
{
	return position.x;
}

float Player::getPosY()
{
	return position.y;
}

float Player::getSpeed()
{
	return speed;
}

float Player::getHeigth() 
{
	return size.x;
}

float Player::getWidth()
{
	return size.y;
}

void Player::setPosX(float x)
{
	position.x = x;
}

void Player::setPosY(float y)
{
	position.y = y;
}

void Player::setSpeed(float speed) 
{
	this->speed = speed;
}

