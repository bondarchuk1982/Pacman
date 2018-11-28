#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Field.h"

using namespace sf;

int main()
{
	Field field;

	unsigned int W = 0, H = 0;
	field.getFieldSize(W, H);

	RenderWindow window(VideoMode(W*32, H*32), "Pacman.");

	Texture tileSet;
	tileSet.loadFromFile("GhostSprites.png");

	Sprite tile(tileSet);

	while (window.isOpen())	{
		Event event;
		while (window.pollEvent(event))	{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear(Color(0, 0, 0));

		field.updateField(window, tile);

		window.display();
	}
}
