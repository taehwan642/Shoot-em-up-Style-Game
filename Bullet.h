#pragma once
#include "Sprite.h"
#include "Player.h"
#include "Boss.h"
class Bullet :
	public Sprite
{
public:
	Bullet();
	float movespeed;
	float falivetime;
	bool ishit;
	void CollisionCheck();
	void AliveCheck();
	void Update() override;
};

class BulletMNG : public Singleton<BulletMNG>
{
public:
	vector<Bullet*> bullets;
	void CreateBullet();
	void SpawnBullet();
	void DeleteBullet();
};