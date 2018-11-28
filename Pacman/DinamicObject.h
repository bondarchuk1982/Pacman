#pragma once
#include "StaticObject.h"

class DinamicObject :
	public StaticObject
{
public:
	DinamicObject();
	virtual ~DinamicObject();

	void setSpeed(float& s);
	void setVSprites(Sprite& spr);
	void setMoveVector(int x, int y);
	std::pair<int, int>& getMoveVector();
	void update(const float& time);
	bool checkCollisionWall(std::vector <StaticObject*>& wall);
	void moveBack(const float& time);
protected:
	void setTexture();
	void setCurrent(const float& time);

	bool collision(std::pair<float, float>& p);

	float speed = 0.0;
	float current = 0.0;

	std::pair<int, int> moveVector = {0, -1};

	std::vector<Sprite> vSprites;
};

