
#include "gameobject.h"

GameObject::GameObject(float posX, float posY, float width, float heigth, int speed)
{
	position = { posX, posY };
	size = { width ,heigth };
	this->speed = speed;
}

GameObject::GameObject(){}

Vector2 GameObject::getPosition()
{
	return position;
}

Rectangle GameObject::getRect()
{
	return { position.x, position.y, size.x, size.y };
}

float GameObject::getPosX()
{
	return position.x;
}

float GameObject::getPosY()
{
	return position.y;
}

float GameObject::getHeigth()
{
	return size.x;
}

float GameObject::getWidth()
{
	return size.y;
}

void GameObject::setPosX(float x)
{
	position.x = x;
}

void GameObject::setHeigth(int h)
{
	size.y = h;
}

void GameObject::setWidth(int w)
{
	size.x = w;
}

void GameObject::setPosY(float y)
{
	position.y = y;
}

float GameObject::getSpeed()
{
	return speed;
}

void GameObject::setSpeed(float speed)
{
	this->speed = speed;
}