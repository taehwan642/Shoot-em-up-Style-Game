#include "DXUT.h"
#include "Bullet.h"

Bullet::Bullet()
{
	Create(L"redbullet.png");
	isUI = true;
	movespeed = 6.5f;
	_visible = false;
	_position = { 900,900 };
}

void Bullet::CollisionCheck()
{
}

void Bullet::Update()
{
	_position.y -= movespeed;
	if (_position.y < 0)
	{
		_visible = false;
	}
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
