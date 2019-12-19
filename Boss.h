#pragma once
#include "Sprite.h"
#include "BossBullet.h"
class Boss :
	public Sprite
{
public:
	Boss();
	float fTime;
	float fPos;
	float HP;
	float timer;

	void MoveMent();
	void BossMoveMent(float position, float cycle, float radius);
	void PatternMNG(int patternnum, float shootpatterndelay);
	void Pattern1();
	void Update() override;
};

class BossMNG : public Singleton<BossMNG>
{
public:
	Boss* boss;
	void CreateBoss();
};