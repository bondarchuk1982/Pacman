#include "pch.h"
#include "Enemy.h"


Enemy::Enemy(Texture &image)
{
	enemy.sprite.setTexture(image);
	enemy.sprite.setTextureRect(IntRect(0, 0, 32, 32));
}
Enemy::~Enemy() { }

void Enemy::update(RenderWindow & window, Sprite & tile, float & time)
{
	enemy.sprite.setPosition(enemy.x, enemy.y);
	tile = enemy.sprite;

	window.draw(tile);

	moveLeft(time);
}

void Enemy::moveLeft(float & time)
{
	setPlayerRect(64);
	enemy.x -= enemy.speed*0.05;

	setCurrent(time);
}

void Enemy::moveRight(float & time)
{
	setPlayerRect(0);
	enemy.x += enemy.speed;

	setCurrent(time);
}

void Enemy::moveUp(float & time)
{
	setPlayerRect(96);
	enemy.y -= enemy.speed;

	setCurrent(time);
}

void Enemy::moveDown(float & time)
{
	setPlayerRect(32);
	enemy.y += enemy.speed;

	setCurrent(time);
}

void Enemy::setCurrent(float & time)
{
	time > 2500 ? time = 0 : enemy.current += 0.5;

	if (enemy.current > 6) {
		enemy.picture = EnemyPicture::first;
		enemy.current = 0;
	}
	else if (enemy.current > 3) {
		enemy.picture = EnemyPicture::second;
	}
}

void Enemy::setPlayerRect(int y)
{
	enemy.picture == EnemyPicture::first
		? enemy.sprite.setTextureRect(IntRect(0, y, 32, 32))
		: enemy.sprite.setTextureRect(IntRect(0, y, 32, 32));
}
