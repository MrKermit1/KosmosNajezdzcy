#include "player.h"


Player::Player(float x, float y, float width, float heigth)
{
	position.x = x;
	position.y = y;
	this->size.x = width;
	this->size.y = heigth;
}

Player::Player(){}

void Player::Shoot(){}

void Player::Move(){}

void Player::Spawn() {}

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

