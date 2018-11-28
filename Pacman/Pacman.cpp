#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Field.h"
#include "Player.h"
#include "Enemy.h"

using namespace sf;

int main()
{
	Field field;

	unsigned int W = 0, H = 0;
	field.getSize(W, H);

	RenderWindow window(VideoMode(W*32, H*32), "Pacman.");

	Texture tileSet;
	tileSet.loadFromFile("Sprites.png");

	Player player(tileSet);
	Enemy enemy(tileSet);

	Sprite tile(tileSet);

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

		field.update(window, tile);
		player.update(window, tile);
		enemy.update(window, tile, time);

		window.display();
	}
}
