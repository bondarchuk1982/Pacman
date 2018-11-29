#pragma once
#include <vector>

#include "StaticObject.h"
#include "DinamicObject.h"
#include "Player.h"

class Field
{
public:
	Field(Sprite& tile, int& coutnGosts, float& _speed, float& _playerSpeed);
	~Field();

	/* Интерфейс по ссылкам на перменные записывает значения
	 * размера игрового поля.
	*/
	void getSize(unsigned int& W, unsigned int& H);

	/* Интерфейс для перерисовки всех объектов на
	 * игровом поле:
	 * window - ссылка на объект окна содержащего игровое поле.
	 * time - значение таймера для сдвига объектов.
	*/
	void update(RenderWindow& window, float& time);

	/* Интерфейс предоставляющий возможность обработки нажатия
	 * игроком клавиши на клавиатуре:
	 * key  - код нажатой клавиши.
	 * time - значение таймера для сдвига объекта.
	*/
	void eventKeyPressed(Keyboard::Key key, float& time);
private:
	// Условная схема игрового поля
	std::vector <std::string> field;

	// Коллекция всех клеток со стенами
	std::vector <StaticObject*> wall;

	// Коллекция всех клеток с сокровищами
	std::vector <StaticObject*> gold;

	// Коллекция всех объектов типа привидение
	std::vector <DinamicObject*> gosts;

	// Указатель на статический объект
	StaticObject *sObject = nullptr;

	// Указательно на динамический объект
	DinamicObject *dObject = nullptr;

	// Инициализация объекта игрока
	Player player;

	// Функция записи схемы игрового поля во внутреннюю перменную
	void readField(Sprite& tile);

	/* Функция создающая все статические объекты на игровом поле:
	 * tile - спрайт содержащий в себе изображения всех объктов
	 * и их состояний.
	*/
	void creatStaticObject(Sprite& tile);

	/* Функция создающая все динамические объекты на игровом поле:
	 * tile - спрайт содержащий в себе изображения всех объктов
	 * и их состояний.
	*/
	void creatDinamicObject(Sprite& tile, int& count, float& _speed);

	/* Функция рандомно меняющая вектор движения привидения в
	 * случае его столкновения со стеной:
	 * obj - ссылка на объект вектор движения которого необходимо
	 * изменить.
	*/
	void changeGostMoveVector(DinamicObject& obj);

	/* Функция создающая объект игрока на игровом поле:
	 * tile - спрайт содержащий в себе изображения всех объктов
	 * и их состояний.
	 * _speed - скорость передвижения игрока по игровому полю
	*/
	void creatPlayerObject(Sprite& tile, float& _speed);
};

