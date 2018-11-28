#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

enum class EnemyPicture
{
	first,
	second
};

struct EnemyStruct
{
	float speed = 1.0;

	float x = 15.0 * 32;
	float y = 13.0 * 32;

	Sprite sprite;
	EnemyPicture picture = EnemyPicture::first;
	float current = 0;
};

class Enemy
{
public:
	Enemy(Texture &image);
	~Enemy();
	
	void update(RenderWindow& window, Sprite& tile, float& time);

	void moveLeft(float& time);
	void moveRight(float& time);
	void moveUp(float& time);
	void moveDown(float& time);
private:
	EnemyStruct enemy;

	void setCurrent(float& time);
	void setPlayerRect(int y);
};

