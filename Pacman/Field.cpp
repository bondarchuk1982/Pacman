#include "pch.h"
#include "Field.h"


Field::Field(Sprite& tile, int& coutnGosts, float& _speed)
{
	readField(tile);
	creatStaticObject(tile);
	creatDinamicObject(tile, coutnGosts, _speed);
}
Field::~Field()
{
	wall.clear();
	gold.clear();
	gosts.clear();
}

void Field::getSize(unsigned int& W, unsigned int& H)
{
	if (field.size() == 0 || field.at(0).size() == 0) return;

	H = static_cast<unsigned int>(field.size());
	W = static_cast<unsigned int>(field.at(0).size());
}

void Field::update(RenderWindow& window, float& time)
{
	for (const auto& obj : wall) {
		obj->drawObject(window);
	}
	for (const auto& obj : gosts) {
		obj->update(time);
		obj->drawObject(window);
	}
	for (const auto& obj : gold) {
		obj->drawObject(window);
	}
}

void Field::readField(Sprite& tile)
{
	field = {
	"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
	"w..............w..............w",
	"w..www..wwwww..w..wwwww..www..w",
	"w..w w..w   w..w..w   w..w w..w",
	"w..www..wwwww..w..wwwww..www..w",
	"w.............................w",
	"w..www..w..wwwwwwwww..w..www..w",
	"w.......w......w......w.......w",
	"w.......w......w......w.......w",
	"wwwwww..www....w....www..wwwwww",
	"     w..w.............w..w     ",
	"     w..w..ww.....ww..w..w     ",
	"wwwwww.....w... ...w.....wwwwww",
	" ..........w..   ..w...........",
	"wwwwww.....w... ...w.....wwwwww",
	"     w..w..wwwwwwwww..w..w     ",
	"     w..w.............w..w     ",
	"wwwwww..w..wwwwwwwww..w..wwwwww",
	"w..............w..............w",
	"w..www..wwwww..w..wwwww..www..w",
	"w....w...................w....w",
	"www..w..w..wwwwwwwww..w..w..www",
	"w.......w......w......w.......w",
	"w..wwwwwwwwww..w..wwwwwwwwww..w",
	"w.............................w",
	"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
	};
}

void Field::creatStaticObject(Sprite& tile)
{
	float i = 0.0, x = 0.0, y = 0.0;
	for (const auto& h : field) {
		float j = 0;
		for (const auto& w : h) {
			if (w == ' ') {
				++j;
				continue;
			}

			x = j * 32;
			y = i * 32;

			if (w == 'w') {
				tile.setPosition(x, y);
				tile.setTextureRect(IntRect(384, 96, 32, 32));

				sObject = new StaticObject();
				sObject->setSprite(tile);
				sObject->setPoint(x, y);

				wall.push_back(sObject);
			}
			else if (w == '.') {
				tile.setPosition(x + 15, y + 15);
				tile.setTextureRect(IntRect(384, 96, 3, 3));

				sObject = new StaticObject();
				sObject->setSprite(tile);
				sObject->setPoint(x + 15, y + 15);

				gold.push_back(sObject);
			}
			++j;
		}
		++i;
	}
}
void Field::creatDinamicObject(Sprite& tile, int& count, float& _speed)
{
	for (int obj = 0; obj < count; ++obj) {
		dObject = new DinamicObject();

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 2; ++j) {
				float x = static_cast<float>((field.at(0).size() / 2) * 32);
				float y = static_cast<float>((field.size() / 2) * 32);

				tile.setPosition(x, y);
				tile.setTextureRect(IntRect(j * 32 + obj * 32, i * 32 + obj * 32, 31, 31));
				dObject->setVSprites(tile);
				dObject->setPoint(x, y);
			}
		}

		dObject->setSprite(tile);
		dObject->setSpeed(_speed);
		gosts.push_back(dObject);
	}
}
