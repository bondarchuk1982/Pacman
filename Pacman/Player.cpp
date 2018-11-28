#include "pch.h"
#include "Player.h"


Player::Player(Texture &image)
{
	player.sprite.setTexture(image);
	player.sprite.setTextureRect(IntRect(320, 0, 32, 32));
}
Player::~Player() { }

void Player::update(RenderWindow& window, Sprite& tile)
{
	player.sprite.setPosition(player.x, player.y);
	tile = player.sprite;

	window.draw(tile);
}

void Player::setKeyPressed(Keyboard::Key key, float& time)
{
	switch (key)
	{
		case Keyboard::Left:	keyLeft(time);	break;
		case Keyboard::Right:	keyRight(time); break;
		case Keyboard::Up:		keyUp(time);	break;
		case Keyboard::Down:	keyDown(time);	break;
		default:								break;
	}
}
void Player::keyLeft(float& time)
{
	setPlayerRect(64);
	player.x -= player.speed;

	setCurrent(time);
}
void Player::keyRight(float& time)
{
	setPlayerRect(0);
	player.x += player.speed;

	setCurrent(time);
}
void Player::keyUp(float& time)
{
	setPlayerRect(96);
	player.y -= player.speed;

	setCurrent(time);
}
void Player::keyDown(float& time)
{
	setPlayerRect(32);
	player.y += player.speed;

	setCurrent(time);
}

void Player::setCurrent(float& time)
{
	time > 2500 ? time = 0 : player.current += 0.5;

	if (player.current > 6) {
		player.picture = Picture::first;
		player.current = 0;
	}
	else if (player.current > 3) {
		player.picture = Picture::second;
	}
}

void Player::setPlayerRect(int y)
{
	player.picture == Picture::first
		? player.sprite.setTextureRect(IntRect(320, y, 32, 32))
		: player.sprite.setTextureRect(IntRect(352, y, 32, 32));
}
