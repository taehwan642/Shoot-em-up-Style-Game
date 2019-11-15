#pragma once
#include "Sprite.h"
#include "Player.h"
class Bullet :
	public Sprite
{
public:
	Bullet();
	float movespeed;
	float falivetime;
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