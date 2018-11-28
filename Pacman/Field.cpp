#include "pch.h"
#include "Field.h"


Field::Field() 
{
	creatField();
}


Field::~Field()
{
}

void Field::getFieldSize(unsigned int& W, unsigned int& H)
{
	if (field.size() == 0 || field.at(0).size() == 0) return;

	H = static_cast<unsigned int>(field.size());
	W = static_cast<unsigned int>(field.at(0).size());
}

void Field::updateField(RenderWindow& window, Sprite& tile)
{
	float i = 0;
	for (const auto& h : field) {
		float j = 0;
		for (const auto& w : h) {
			if (w == 'w') {
				tile.setPosition(j * 32, i * 32);
				tile.setTextureRect(IntRect(384, 96, 32, 32));
			}
			if (w == '.') {
				tile.setPosition(j * 32 + 15, i * 32 + 15);
				tile.setTextureRect(IntRect(384, 96, 3, 3));
			}
			if (w == ' ') {
				++j;
				continue;
			}

			window.draw(tile);
			++j;
		}
		++i;
	}
}

void Field::creatField()
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
	"...........w..   ..w...........",
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
