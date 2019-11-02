#pragma once
#include "Sprite.h"
class Boss :
	public Sprite
{
public:
	Boss();
	float fTime;
	float fPos;
	int HP;
	void MoveMent();
	void Pattern1();
	void Update() override;
};

class BossMNG : public Singleton<BossMNG>
{
public:
	Boss* boss;
	void CreateBoss();
};