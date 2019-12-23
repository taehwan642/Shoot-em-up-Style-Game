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
	bool ishit;
	vector2 _v;
	void AliveCheck();
	void MoveMent();
	void Update() override;
};

class BossBulletMNG : public Singleton<BossBulletMNG>
{
public:
	vector<BossBullet*> Bossbullets;
	void CreateBullet();
	void SpawnBullet(vector2 vec);
	void DeleteBullet();
};
