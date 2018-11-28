#pragma once
#include "DinamicObject.h"

class Player :
	public DinamicObject
{
public:
	Player();
	~Player();

	void setKeyPressed(Keyboard::Key, float& time);

	void keyLeft(float& time);
	void keyRight(float& time);
	void keyUp(float& time);
	void keyDown(float& time);

	void checkCollisionGold(std::vector <StaticObject*>& gold);
	bool checkCollisionGosts(std::vector <DinamicObject*>& gosts);

	enum class PlayerStatus
	{
		live,
		dead,
		win
	} playerStatus = PlayerStatus::live;
private:
	int collisionGold(std::pair<float, float>& p);
};
