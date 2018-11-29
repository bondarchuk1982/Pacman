#include "pch.h"
#include "DinamicObject.h"

DinamicObject::DinamicObject() { }
DinamicObject::~DinamicObject() { }

void DinamicObject::setSpeed(float& s)
{
	speed = s;
}

void DinamicObject::setVSprites(Sprite& spr)
{
	Sprite s = spr;
	vSprites.push_back(s);
}

void DinamicObject::setMoveVector(int x, int y)
{
	moveVector.first = x;
	moveVector.second = y;
}
std::pair<int, int>& DinamicObject::getMoveVector()
{
	return moveVector;
}

void DinamicObject::update(const float& time)
{
	if (moveVector.first == 1) {
		point.first += time * speed;
	}
	else if (moveVector.first == -1) {
		point.first -= time * speed;
	}
	else if (moveVector.second == 1) {
		point.second += time * speed;
	}
	else if (moveVector.second == -1) {
		point.second -= time * speed;
	}

	setTexture();
	setCurrent(time);
}
void DinamicObject::setTexture()
{
	if (moveVector.first == 1) {
		current > 5 ? sprite = vSprites.at(0) : sprite = vSprites.at(1);
	}
	else if (moveVector.first == -1) {
		current > 5 ? sprite = vSprites.at(4) : sprite = vSprites.at(5);
	}
	else if (moveVector.second == 1) {
		current > 5 ? sprite = vSprites.at(2) : sprite = vSprites.at(3);
	}
	else if (moveVector.second == -1) {
		current > 5 ? sprite = vSprites.at(6) : sprite = vSprites.at(7);
	}

	sprite.setPosition(point.first, point.second);
}
void DinamicObject::setCurrent(const float& time)
{
	if (current > 10) {
		current = 0;
		return;
	}

	current += time * speed;
}

void DinamicObject::moveBack(const float & time)
{
	if (moveVector.first == 1) {
		point.first -= time * speed;
	}
	else if (moveVector.first == -1) {
		point.first += time * speed;
	}
	else if (moveVector.second == 1) {
		point.second -= time * speed;
	}
	else if (moveVector.second == -1) {
		point.second += time * speed;
	}

	setTexture();
	setCurrent(time);
}

bool DinamicObject::checkCollisionWall(std::vector<StaticObject*>& wall)
{
	for (const auto& obj : wall) {
		std::pair<float, float> p = obj->getPoint();
		if (collision(p)) {
			return true;
		}
	}
	return false;
}
bool DinamicObject::collision(std::pair<float, float>& p)
{
	if (point.first > p.first && point.first < p.first + 32 &&
		point.second > p.second && point.second < p.second + 32) {
		return true;
	}
	else if (point.first + 31 > p.first && point.first + 31 < p.first + 32 &&
		point.second > p.second && point.second < p.second + 32) {
		return true;
	}
	else if (point.first + 31 > p.first && point.first + 31 < p.first + 32 &&
		point.second + 31 > p.second && point.second + 31 < p.second + 32) {
		return true;
	}
	else if (point.first > p.first && point.first < p.first + 32 &&
		point.second + 31 > p.second && point.second + 31 < p.second + 32) {
		return true;
	}

	return false;
}
