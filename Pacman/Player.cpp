#include <algorithm>

#include "pch.h"
#include "Player.h"

Player::Player() { setMoveVector(0, 0); }
Player::~Player() { }

void Player::setKeyPressed(Keyboard::Key key, float& time)
{
	switch (key)
	{
		case Keyboard::Left:	keyLeft(time);  break;
		case Keyboard::Right:	keyRight(time); break;
		case Keyboard::Up:		keyUp(time);	break;
		case Keyboard::Down:	keyDown(time);	break;
		default:								break;
	}
}
void Player::keyLeft(float& time)
{
	setMoveVector(-1, 0);
	update(time);
}
void Player::keyRight(float& time)
{
	setMoveVector(1, 0);
	update(time);
}
void Player::keyUp(float& time)
{
	setMoveVector(0, -1);
	update(time);
}
void Player::keyDown(float& time)
{
	setMoveVector(0, 1);
	update(time);
}

void Player::checkCollisionGold(std::vector<StaticObject*>& gold)
{
	int index = 0;

	for (const auto& obj : gold) {
		std::pair<float, float> p = obj->getPoint();
		index = collisionGold(p);

		if (index != -1) {
			gold.erase(std::remove(gold.begin(), gold.end(), obj), gold.end());
		}
	}
}
bool Player::checkCollisionGosts(std::vector<DinamicObject*>& gosts)
{
	for (const auto& obj : gosts) {
		std::pair<float, float> p = obj->getPoint();
		if (collision(p)) {
			return true;
		}
	}
	return false;
}

int Player::collisionGold(std::pair<float, float>& p)
{
	if (p.first > point.first && p.first < point.first + 30 &&
		p.second > point.second && p.second < point.second + 30) {
		return true;
	}
	if (p.first + 3 > point.first && p.first + 3 < point.first + 30 &&
		p.second > point.second && p.second < point.second + 30) {
		return true;
	}
	if (p.first + 3 > point.first && p.first + 3 < point.first + 30 &&
		p.second + 3 > point.second && p.second + 3 < point.second + 30) {
		return true;
	}
	if (p.first > point.first && p.first < point.first + 30 &&
		p.second + 3 > point.second && p.second + 3 < point.second + 30) {
		return true;
	}
	return -1;
}
