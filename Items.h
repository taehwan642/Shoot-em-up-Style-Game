#pragma once
#include "Sprite.h"
#include "Player.h"
#include "Monsters.h"

class Items : public Sprite
{
public:
	Items();
	void Movement();
	void ItemEffect();
	void Update() override;
	int itemnum;
};

class ItemMNG : public Singleton<ItemMNG>
{
public:
	vector<Items*> itemss;
	void ItemCreate();
	void ItemSpawn();
	void DeleteItem();
};

