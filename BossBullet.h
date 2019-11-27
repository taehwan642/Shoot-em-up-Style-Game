#pragma once
#include "Sprite.h"
#include "Boss.h"
class BossBullet :
	public Sprite
{
public:
	BossBullet();
	float speed;
	float movespeed;
	float falivetime;
	vector2 _v;
	void CollisionCheck();
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
