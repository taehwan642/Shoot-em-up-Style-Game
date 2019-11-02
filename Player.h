#pragma once
#include "Sprite.h"
class Player :
	public Sprite
{
public:
	Player();
	float fmovespeed;
	void MoveMent();
	void Update() override;
};

class PlayerMNG : public Singleton<PlayerMNG>
{
public:
	Player* player;
	void CreatePlayer();
};