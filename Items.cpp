#include "DXUT.h"
#include "Items.h"

Items::Items()
{
	itemnum = 0;
	Create(L"explode1.png");
	_visible = false;
}

void Items::Movement()
{
	_position.y += 3;

}

void Items::ItemEffect()
{

}

void Items::Update()
{
	if (!_visible)
		return;

	Movement();

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
