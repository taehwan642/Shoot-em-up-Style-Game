#include "DXUT.h"
#include "BossBullet.h"

BossBullet::BossBullet()
{
	Create(L"graybullet.png");
	isUI = false;
	speed = 300.0f;
	movespeed = 6.5f;
	falivetime = 5;
	_visible = false;
	_scale = { 0.7f,0.7f };
	_position = { 900,900 };
}

void BossBullet::CollisionCheck()
{

}

void BossBullet::AliveCheck()
{
	if (!_visible)
		return;
	falivetime -= Time::deltaTime;

	if (falivetime < 0)
	{
		_visible = false;
		falivetime = 5;
	}

}

void BossBullet::MoveMent()
{
	_position += {speed * Time::deltaTime * _v};
}

void BossBullet::Update()
{
	AliveCheck();
	MoveMent();
}

void BossBulletMNG::CreateBullet()
{
	for (int i = 0; i < 1000; i++)
	{
		BossBullet* bullet = new BossBullet();
		Bossbullets.push_back(bullet);
	}
}

void BossBulletMNG::SpawnBullet(vector2 vec)
{
	for (auto it : Bossbullets)
	{
		if (!it->_visible)
		{
			it->_position = BossMNG::GetInstance()->boss->_position;
			it->_v = vec;
			it->_visible = true;
			return;
		}
	}
}


void BossBulletMNG::DeleteBullet()
{
}
