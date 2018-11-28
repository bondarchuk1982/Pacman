#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

class Field
{
public:
	Field();
	~Field();

	void getSize(unsigned int& W, unsigned int& H);

	void update(RenderWindow& window, Sprite& tile);
private:
	std::vector <std::string> field;

	void creat();
};

