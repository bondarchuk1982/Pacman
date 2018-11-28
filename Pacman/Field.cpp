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
		if (obj != nullptr) {
			obj->drawObject(window);
		}
	}
	for (const auto& obj : gosts) {
		if (obj != nullptr) {
			obj->update(time);
			
			if (obj->checkCollision(wall)) {
				obj->moveBack(time);
				changeGostMoveVector(*obj);
			}
			
			obj->drawObject(window);
		}
	}
	for (const auto& obj : gold) {
		if (obj != nullptr) {
			obj->drawObject(window);
		}
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

				tile.setPosition(x, y + obj);
				tile.setTextureRect(IntRect(j * 32 + obj * 64, i * 32, 31, 31));
				dObject->setVSprites(tile);
				dObject->setPoint(x, y + obj);
			}
		}

		dObject->setSprite(tile);
		dObject->setSpeed(_speed);
		gosts.push_back(dObject);
	}
}

void Field::changeGostMoveVector(DinamicObject& obj)
{
	std::pair<int, int> mvObject = { obj.getMoveVector() };

	bool flagChangeMoveVector = false;
	while (!flagChangeMoveVector) {
		int random_variable = std::rand() % 10000;
		if (mvObject.first != 1 && random_variable > 0 && random_variable <= 2500) {
			obj.setMoveVector(1, 0);
			flagChangeMoveVector = true;
		}
		if (mvObject.first != -1 && random_variable > 2500 && random_variable <= 5000) {
			obj.setMoveVector(-1, 0);
			flagChangeMoveVector = true;
		}
		if (mvObject.second != 1 && random_variable > 5000 && random_variable <= 7500) {
			obj.setMoveVector(0, 1);
			flagChangeMoveVector = true;
		}
		if (mvObject.second != -1 && random_variable > 7500 && random_variable <= 10000) {
			obj.setMoveVector(0, -1);
			flagChangeMoveVector = true;
		}
	}
}
