#pragma once
#include "Dot.h"

enum class ItemType
{
	HP_UP,
	SPEED_UP,
	POWER_UP
};

struct Item
{
	int x, y;
	bool activate;
	ItemType type;

	int itemTimer;


	Item(int posX, int posY, ItemType itemtype) : 
			x(posX), y(posY), activate(true), type(itemtype), itemTimer(500) {};

};


class ItemManager
{
private:
	Dot* _dot;
	vector<Item> _items;
	
	void DropItem(int x, int y);
	void UpdateItem();

	// getter
	vector<Item>& getItem();

public:
	ItemManager();
	~ItemManager();
};

