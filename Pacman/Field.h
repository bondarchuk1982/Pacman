#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "StaticObject.h"
#include "DinamicObject.h"

using namespace sf;

class Field
{
public:
	Field(Sprite& tile, int& coutnGosts, float& _speed);
	~Field();

	void getSize(unsigned int& W, unsigned int& H);

	void update(RenderWindow& window, float& time);
private:
	std::vector <std::string> field;
	std::vector <StaticObject*> wall;
	std::vector <StaticObject*> gold;
	std::vector <DinamicObject*> gosts;

	StaticObject *sObject;
	DinamicObject *dObject;

	void readField(Sprite& tile);
	void creatStaticObject(Sprite& tile);
	void creatDinamicObject(Sprite& tile, int& count, float& _speed);
	void changeGostMoveVector(DinamicObject& obj);
};

