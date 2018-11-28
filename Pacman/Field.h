#pragma once
#include <vector>

#include "StaticObject.h"
#include "DinamicObject.h"
#include "Player.h"

class Field
{
public:
	Field(Sprite& tile, int& coutnGosts, float& _speed, float& _playerSpeed);
	~Field();

	void getSize(unsigned int& W, unsigned int& H);

	void update(RenderWindow& window, float& time);
	void eventKeyPressed(Keyboard::Key key, float& time);
private:
	std::vector <std::string> field;
	std::vector <StaticObject*> wall;
	std::vector <StaticObject*> gold;
	std::vector <DinamicObject*> gosts;

	StaticObject *sObject = nullptr;
	DinamicObject *dObject = nullptr;

	Player player;

	void readField(Sprite& tile);
	void creatStaticObject(Sprite& tile);
	void creatDinamicObject(Sprite& tile, int& count, float& _speed);
	void changeGostMoveVector(DinamicObject& obj);
	void creatPlayerObject(Sprite& tile, float& _speed);
};

