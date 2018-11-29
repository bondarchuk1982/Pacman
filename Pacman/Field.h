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

	/* ��������� �� ������� �� ��������� ���������� ��������
	 * ������� �������� ����.
	*/
	void getSize(unsigned int& W, unsigned int& H);

	/* ��������� ��� ����������� ���� �������� ��
	 * ������� ����:
	 * window - ������ �� ������ ���� ����������� ������� ����.
	 * time - �������� ������� ��� ������ ��������.
	*/
	void update(RenderWindow& window, float& time);

	/* ��������� ��������������� ����������� ��������� �������
	 * ������� ������� �� ����������:
	 * key  - ��� ������� �������.
	 * time - �������� ������� ��� ������ �������.
	*/
	void eventKeyPressed(Keyboard::Key key, float& time);
private:
	// �������� ����� �������� ����
	std::vector <std::string> field;

	// ��������� ���� ������ �� �������
	std::vector <StaticObject*> wall;

	// ��������� ���� ������ � �����������
	std::vector <StaticObject*> gold;

	// ��������� ���� �������� ���� ����������
	std::vector <DinamicObject*> gosts;

	// ��������� �� ����������� ������
	StaticObject *sObject = nullptr;

	// ����������� �� ������������ ������
	DinamicObject *dObject = nullptr;

	// ������������� ������� ������
	Player player;

	// ������� ������ ����� �������� ���� �� ���������� ���������
	void readField(Sprite& tile);

	/* ������� ��������� ��� ����������� ������� �� ������� ����:
	 * tile - ������ ���������� � ���� ����������� ���� �������
	 * � �� ���������.
	*/
	void creatStaticObject(Sprite& tile);

	/* ������� ��������� ��� ������������ ������� �� ������� ����:
	 * tile - ������ ���������� � ���� ����������� ���� �������
	 * � �� ���������.
	*/
	void creatDinamicObject(Sprite& tile, int& count, float& _speed);

	/* ������� �������� �������� ������ �������� ���������� �
	 * ������ ��� ������������ �� ������:
	 * obj - ������ �� ������ ������ �������� �������� ����������
	 * ��������.
	*/
	void changeGostMoveVector(DinamicObject& obj);

	/* ������� ��������� ������ ������ �� ������� ����:
	 * tile - ������ ���������� � ���� ����������� ���� �������
	 * � �� ���������.
	 * _speed - �������� ������������ ������ �� �������� ����
	*/
	void creatPlayerObject(Sprite& tile, float& _speed);
};

