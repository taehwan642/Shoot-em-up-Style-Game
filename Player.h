#pragma once
#include "Sprite.h"
class Player :
	public Sprite
{
public:
	Player();
	float fmovespeed;
	float freshootingtime;
	float HP;
	Sprite* collider;
	void MoveMent();
	void Update() override;
};

class PlayerMNG : public Singleton<PlayerMNG>
{
public:
	Player* player;
	void CreatePlayer();
};