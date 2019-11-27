#include "DXUT.h"
#include "Bullet.h"

Bullet::Bullet()
{
	Create(L"redbullet.png");
	isUI = false;
	movespeed = 6.5f;
	falivetime = 5;
	_visible = false;
	_scale = { 0.7f,0.7f };
	_position = { 900,900 };
}

void Bullet::CollisionCheck()
{
}

void Bullet::AliveCheck()
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

void Bullet::Update()
{
	AliveCheck();
	_position.y -= movespeed;
}

void BulletMNG::CreateBullet()
{
	for (int i = 0; i < 30; i++)
	{
		Bullet* bullet = new Bullet();
		bullets.push_back(bullet);
	}
}

void BulletMNG::SpawnBullet()
{
	for (auto it : bullets)
	{
		if (!it->_visible)
		{
			it->_position = PlayerMNG::GetInstance()->player->_position;
			it->_visible = true;
			return;
		}
	}
}

void BulletMNG::DeleteBullet()
{
	for (auto it : bullets)
	{
		delete it;
	}
	bullets.clear();
}
