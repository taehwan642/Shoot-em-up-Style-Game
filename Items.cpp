#include "DXUT.h"
#include "Items.h"

Items::Items()
{
	itemnum = 0;
}

void Items::Movement()
{
}

void Items::ItemEffect()
{
}

void ItemMNG::ItemCreate()
{
	for (int i = 0; i < 30; i++)
	{
		Items* item = new Items;
		itemss.push_back(item);
	}
}

void ItemMNG::ItemSpawn()
{

}

void ItemMNG::DeleteItem()
{

}
