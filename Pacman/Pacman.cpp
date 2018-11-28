#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Field.h"
#include "Player.h"

using namespace sf;

int main()
{
	int countGosts = 1;
	float gameSpeed = static_cast<float>(0.05);

	Texture tileSet;
	tileSet.loadFromFile("Sprites.png");

	Sprite tile(tileSet);

	unsigned int W = 0, H = 0;
	Field field(tile, countGosts, gameSpeed);
	field.getSize(W, H);

	RenderWindow window(VideoMode(W*32, H*32), "Pacman.");

	Player player(tileSet);
//	Enemy enemy(tileSet);

	Clock clock;

	while (window.isOpen())	{
		float time = static_cast<float> (clock.getElapsedTime().asMicroseconds());
		clock.restart();

		Event event;
		while (window.pollEvent(event))	{
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::KeyPressed)
				player.setKeyPressed(event.key.code, time);
		}

		window.clear(Color(0, 0, 0));

		time = time / 500;  // здесь регулируем скорость игры
		if (time > 20) {
			time = 20;
		}

		field.update(window, time);
		//player.update(window, tile);
		//enemy.update(window, tile, time);

		window.display();
	}
}
