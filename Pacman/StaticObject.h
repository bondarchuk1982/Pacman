#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class StaticObject
{
public:
	StaticObject();
	virtual ~StaticObject();

	/* Функция задаёт координаты позиции объекта на поле.
	 * х - координата по оси х.
	 * у - координата по оси у.
	 */
	virtual void setPoint(const float& x, const float& y);

	/* Функция возвращает координаты позиции объекта на поле.
	 * point  - включает в себя две координаты:
	 * first  - координата по оси х.
	 * second - координата по оси у.
	 */
	virtual std::pair<float, float>& getPoint();

	/* Интерфейс для доступа к внутреннему объекту типа Sprite.
	 * Задаёт картинку присущую данному экземпляру объекта.
	 */
	virtual void setSprite(Sprite& spr);

	/* Интерфейс для отрисовки внутреннего бъекта типа Sprite в 
	 * основном окне.
	 */
	virtual void drawObject(RenderWindow& window);
protected:
	/* Внутренняя переменная хранящая координаты данного объекта.
	 * Задаётся списком инициализации с начальными координатами.
	 * Пришлось делать static_cast<float> т.к. компилятор Visual
	 * Studio 2017 выдавал предупреждение о возможной потере данных
	 * при преобразовании double во float.
	*/
	std::pair<float, float> point = { static_cast<float>(0.0), static_cast<float>(0.0) };

	// Внутренняя переменная хранящая картинку данного объекта.
	Sprite sprite;
};

