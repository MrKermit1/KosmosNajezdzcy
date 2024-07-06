#pragma once
class Player
{
protected:

	int posX;
	int posY;
	int width;
	int heigth;

private:
	float speed;

public:

	Player();
	Player(int x, int y, int width, int heigth);

	virtual void Move();
	virtual void Spawn();
	void Shoot();

	void setPosX(int x);
	void setPosY(int y);
	void setSpeed(float speed);
	void setWidth(int width);
	void setHeigth(int heigth);


	int getPosX();
	int getPosY();
	float getSpeed();
	int getWidth();
	int getHeigth();




};

