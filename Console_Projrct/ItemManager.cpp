#include "ItemManager.h"
#include "Common.h"



ItemManager::ItemManager()
{
	_dot = new Dot;
}

ItemManager::~ItemManager()
{
	delete _dot;
}

void ItemManager::DropItem(int x, int y)
{
	int randNum = rand() % 10;	// 0,1,2,3,4,5,6,7,8,9,10
	if (randNum < 4)
	{
		// 아이템 3개 중 한개 드랍
		int itemTypeNum = rand() % 3;
		ItemType type;
		switch (itemTypeNum)
		{
		case 0:
			type = ItemType::HP_UP;
			break;
			
		case 1:
			type = ItemType::POWER_UP;
			break;

		case 2:
			type = ItemType::SPEED_UP;
			break;
		}
		// item vector
		_items.push_back(Item(x, y, type));
	}
}

void ItemManager::UpdateItem()
{
}

vector<Item>& ItemManager::getItem()
{
	// TODO: 여기에 return 문을 삽입합니다.
}