#include "DXUT.h"
#include "Bullet.h"

Bullet::Bullet()
{
	Create(L"redbullet.png");
	isUI = false;
	movespeed = 10.0f;
	falivetime = 5;
	_visible = false;
	ishit = false;
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

	if (BossMNG::GetInstance()->boss->_visible)
	{
		RECT boss;
		if (IntersectRect(&boss, &GetRect(), &BossMNG::GetInstance()->boss->GetRect()))
		{
			ishit = true;
			BossMNG::GetInstance()->boss->HP--;
		}
	}

}

void Bullet::Update()
{
	if (!_visible)
		return;

	if (ishit)
	{
		if (Animation(L"explode", 3, 0.05f, 1))
		{
			_visible = false;
			ishit = false;
			falivetime = 5;
		}
	}
	else
	{
		_position.y -= movespeed;
		AliveCheck();
	}


}
//Drawline? LPD3DX?
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
			it->ishit = false;
			it->Create(L"redbullet.png");
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
