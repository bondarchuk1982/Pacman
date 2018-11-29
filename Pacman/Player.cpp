#include <algorithm>

#include "pch.h"
#include "Player.h"

Player::Player() 
{
	font.loadFromFile("sansation.ttf");
	setMoveVector(0, 0); 
}
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
	for (const auto& obj : gold) {
		std::pair<float, float> p = obj->getPoint();

		if (collisionGold(p)) {
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

void Player::drawPlayerStatus(RenderWindow& window)
{
	std::string str;
	if (playerStatus == PlayerStatus::dead) {
		str = "You are DEAD!!!";
	}
	if (playerStatus == PlayerStatus::win) {
		str = "You are WIN!!!";
	}

	Vector2u v = window.getSize();
	float x = static_cast<float>(v.x / 2 - (str.length() / 2) * 24);
	float y = static_cast<float>(v.y / 2);

	Text txt;
	txt.setFont(font); 
	txt.setString(str);
	txt.setFillColor(Color::White);
	txt.setPosition(x, y);
	txt.setCharacterSize(48);
	txt.setStyle(sf::Text::Bold | sf::Text::Underlined);

	window.draw(txt);
}

bool Player::collisionGold(std::pair<float, float>& p)
{
	if (p.first > point.first + 10 && p.first < point.first + 20 &&
		p.second > point.second + 10 && p.second < point.second + 20) {
		return true;
	}
	if (p.first + 3 > point.first + 10 && p.first + 3 < point.first + 20 &&
		p.second > point.second + 10 && p.second < point.second + 20) {
		return true;
	}
	if (p.first + 3 > point.first + 10 && p.first + 3 < point.first + 20 &&
		p.second + 3 > point.second + 10 && p.second + 3 < point.second + 20) {
		return true;
	}
	if (p.first > point.first + 10 && p.first < point.first + 20 &&
		p.second + 3 > point.second + 10 && p.second + 3 < point.second + 20) {
		return true;
	}
	return false;
}
