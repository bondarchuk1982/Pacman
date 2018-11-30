#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class StaticObject
{
public:
	StaticObject();
	virtual ~StaticObject();

	/* ������� ����� ���������� ������� ������� �� ����.
	 * � - ���������� �� ��� �.
	 * � - ���������� �� ��� �.
	 */
	virtual void setPoint(const float& x, const float& y);

	/* ������� ���������� ���������� ������� ������� �� ����.
	 * point  - �������� � ���� ��� ����������:
	 * first  - ���������� �� ��� �.
	 * second - ���������� �� ��� �.
	 */
	virtual std::pair<float, float>& getPoint();

	/* ��������� ��� ������� � ����������� ������� ���� Sprite.
	 * ����� �������� �������� ������� ���������� �������.
	 */
	virtual void setSprite(Sprite& spr);

	/* ��������� ��� ��������� ����������� ������ ���� Sprite � 
	 * �������� ����.
	 */
	virtual void drawObject(RenderWindow& window);
protected:
	/* ���������� ���������� �������� ���������� ������� �������.
	 * ������� ������� ������������� � ���������� ������������.
	 * �������� ������ static_cast<float> �.�. ���������� Visual
	 * Studio 2017 ������� �������������� � ��������� ������ ������
	 * ��� �������������� double �� float.
	*/
	std::pair<float, float> point = { static_cast<float>(0.0), static_cast<float>(0.0) };

	// ���������� ���������� �������� �������� ������� �������.
	Sprite sprite;
};

