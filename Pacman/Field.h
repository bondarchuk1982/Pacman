#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

class Field
{
public:
	Field();
	~Field();

	void getFieldSize(unsigned int& W, unsigned int& H);

	void updateField(RenderWindow& window, Sprite& tile);
private:
	std::vector <std::string> field;

	void creatField();
};

