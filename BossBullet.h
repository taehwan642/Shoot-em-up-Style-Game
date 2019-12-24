#pragma once
#include "Sprite.h"
#include "Boss.h"
#include "Player.h"
class BossBullet :
	public Sprite
{
public:
	BossBullet();
	float speed;
	float movespeed;
	float falivetime;
	float r;
	int patternnumber;
	bool ishit;
	void AliveCheck();
	void MoveMent();
	void Update() override;
	void Pattern1();
	void Pattern2();
	void Pattern3();
};

class BossBulletMNG : public Singleton<BossBulletMNG>
{
public:
	vector<BossBullet*> Bossbullets;
	void CreateBullet();
	void SpawnBullet(int PatternNum, float rotation);
	void DeleteBullet();
};
