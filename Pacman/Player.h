#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

enum class Picture
{
	first,
	second
};

struct objectStruct
{
	float speed = 1.25;

	float x = 0.0;
	float y = 13.0*32;

	Sprite sprite;
	Picture picture = Picture::first;
	float current = 0;
};

class Player
{
public:
	Player(Texture &image);
	~Player();

	void update(RenderWindow& window, Sprite& tile);
	void setKeyPressed(Keyboard::Key, float& time);

	void keyLeft(float& time);
	void keyRight(float& time);
	void keyUp(float& time);
	void keyDown(float& time);
private:
	objectStruct player;

	void setCurrent(float& time);
	void setPlayerRect(int y);
};
