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
	float* pattern2rotation;
	float pattern21;
	float pattern22;
	float pattern23;
	float pattern24;

	void MoveMent();
	void BossMoveMent(float position, float cycle, float radius);
	void PatternMNG(int patternnum, float shootpatterndelay);
	void Pattern1();
	void Pattern2(/*startrotation nees to be 0 ~ 360*/float& startrotation);
	void Update() override;
};

class BossMNG : public Singleton<BossMNG>
{
public:
	Boss* boss;
	void CreateBoss();
};