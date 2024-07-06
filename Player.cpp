#include "Player.h"


Player::Player(int x, int y, int width, int heigth)
{
	posX = x;
	posY = y;
	this->width = width;
	this->heigth = heigth;
}

int Player::getPosX()
{
	return posX;
}

int Player::getPosY()
{
	return posY;
}

float Player::getSpeed()
{
	return speed;
}

void Player::setPosX(int x)
{
	posX = x;
}

void Player::setPosY(int y)
{
	posY = y;
}

