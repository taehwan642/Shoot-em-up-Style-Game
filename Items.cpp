#include "DXUT.h"
#include "Items.h"
#include "Health.h"
Items::Items()
{
	itemnum = 0;
	Create(L"explode1.png");
	cout << "!!" << endl;
	_visible = false;
}

void Items::Movement()
{
	_position.y += 3;
	RECT RR;
	if (IntersectRect(&RR, &PlayerMNG::GetInstance()->player->GetRect(), &GetRect()))
	{
		if(itemnum == 0)
			HealthMNG::GetInstance()->HealthControl(0);
		
		_visible = false;
	}
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
	for (auto it : itemss)
	{
		/*it->_position.x = ((rand() % 300) + 30);
		it->_position.y = (rand() % 150) + 30;*/
	/*	it->_position.x = mon->_position.x;
		it->_position.y = mon->_position.y;*/

		it->_visible = true;
	}
}

void ItemMNG::DeleteItem()
{
	for (auto it : itemss)
	{
		delete it;
	}
	itemss.clear();
}
