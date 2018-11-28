#include "pch.h"
#include "StaticObject.h"

StaticObject::StaticObject() { }
StaticObject::~StaticObject() { }

void StaticObject::setPoint(const float& x, const float& y)
{
	point.first = x;
	point.second = y;
}

std::pair<float, float>& StaticObject::getPoint()
{
	return point;
}

void StaticObject::setSprite(Sprite& spr)
{
	sprite = spr;
}

void StaticObject::drawObject(RenderWindow& window)
{
	window.draw(sprite);
}
