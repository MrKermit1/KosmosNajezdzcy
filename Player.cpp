#include "player.h"

Player::Player(float x, float y, float width, float heigth, int speed, int life) : GameObject(x, y, width, heigth, speed)
{
	this->life = life;
	shootOut = false;
	score = 0;
	textureLoaded = false;
}

Player::Player(){}

void Player::DeleteBullet(std::vector<Bullet>::iterator it)
{
	bullets.erase(it);
}

void Player::Shoot()
{
	if (IsKeyPressed(KEY_SPACE)) {
		bullets.push_back(Bullet(position.x + size.x / 2, position.y, 5, 10, -5, YELLOW));
	}
}

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
		if (bullet.isActive() && !(bullet.getPosition().y < 10))
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
	DrawRectangleV(position, size, BLACK);
	DrawTextureV(texture, position, RAYWHITE);
	for (auto& bullet : bullets) {
		if (bullet.isActive() && !(bullet.getPosition().y < 10)) {
			bullet.Spawn();
		}
	}
}

int Player::getScore()
{
	return score;
}

int Player::getLife()
{
	return life;
}

void Player::setLife(int life)
{
	this->life = life;
}

void Player::addScore(int pscore)
{
	this->score += pscore;
}

void Player::ResetBullets()
{
	bullets.clear();
}

void Player::LoadTextures()
{
	if (!textureLoaded)
	{
		image = LoadImage("assets/player/player.png");
		texture = LoadTextureFromImage(image);
		UnloadImage(image);
		textureLoaded = true;
	}
}

void Player::UnloadTextures()
{
	if (textureLoaded)
	{
		UnloadTexture(texture);
		textureLoaded = false;
	}
}