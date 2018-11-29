#include "pch.h"
#include "Field.h"

int main()
{
	int countGosts = 5; // количество привидений, максимум 5!
	float gameSpeed = static_cast<float>(0.05); // скорость игры
	float playerSpeed = static_cast<float>(0.75); // скорость игрока

	// Читаем из файла набор спрайтов для разных объектов игры.
	Texture tileSet; 
	tileSet.loadFromFile("Sprites.png");

	// Объект хранящий в себе все спрайты
	Sprite tile(tileSet);

	/* Создаём игровое поле с начальными параметрами:
	 * tile - передаём набор спрайтов для объектов на игровом поле.
	 * countGosts - количество привидений на игровом поле.
	 * gameSpeed - скорость игры.
	 * playerSpeed - скорость передвижения игрока по полю.
	*/ 
	unsigned int W = 0, H = 0;
	Field field(tile, countGosts, gameSpeed, playerSpeed);
	/* После создания поля получаем его размеры:
	 * W - ширина поля.
	 * H - высота поля.
	*/
	field.getSize(W, H);

	// Создаём окно необходимого размера с заголовком.
	RenderWindow window(VideoMode(W*32, H*32), "Pacman.");

	// Таймер.
	Clock clock;

	while (window.isOpen())	{
		float time = static_cast<float> (clock.getElapsedTime().asMicroseconds());
		clock.restart();

		time = time / 500;  // здесь дополнительно регулируем скорость игры
		if (time > 20) {
			time = 20;
		}

		Event event; // Отлавливаем события в окне игры.
		while (window.pollEvent(event))	{
			if (event.type == Event::Closed) // Закрытие кона игры.
				window.close();

			if (event.type == Event::KeyPressed) // Нажатие игроком клавиши на клавиатуре
				field.eventKeyPressed(event.key.code, time); // Обрабатываем нажатие.
		}
		window.clear(Color(0, 0, 0)); // Чистим поле(заливаем чёрным цветом).

		field.update(window, time); // Перерисовываем игровое поле.
		window.display(); // Отображаем окно с игровым полем.
	}
}
