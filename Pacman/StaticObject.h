#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class StaticObject
{
public:
	StaticObject();
	virtual ~StaticObject();

	void setPoint(const float& x, const float& y);
	std::pair<float, float>& getPoint();

	void setSprite(Sprite& spr);
	void drawObject(RenderWindow& window);
protected:
	std::pair<float, float> point = { static_cast<float>(0.0), static_cast<float>(0.0) };

	Sprite sprite;
};

