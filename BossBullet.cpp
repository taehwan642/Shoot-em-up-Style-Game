#include "DXUT.h"
#include "BossBullet.h"

BossBullet::BossBullet()
{
	Create(L"graybullet.png");
	isUI = false;
	speed = 3.0f;
	movespeed = 6.5f;
	falivetime = 5;
	ishit = false;
	_visible = false;
	_scale = { 0.7f,0.7f };
	_position = { 900,900 };
}

void BossBullet::AliveCheck()
{
	if (!_visible)
		return;
	falivetime -= Time::deltaTime;

	if (ishit)
	{
		if (Animation(L"explode", 3, 0.05f, 1))
		{
			ishit = false;
			_visible = false;
			falivetime = 5;
		}
	}

	if (falivetime < 0)
	{
		_visible = false;
		falivetime = 5;
	}

	if (_position.x > 360 || _position.x < 0 || _position.y > 720 || _position.y < 0)
	{
		_visible = false;
		falivetime = 5;
	}
}

void BossBullet::Pattern1()
{
	vector2 vec;
	float x = (cos(r * (3.141592 / 180)));
	float y = (sin(r * (3.141592 / 180)));
	vec.x = x;
	vec.y = y;

	_position += vec * speed;
}

void BossBullet::Pattern2()
{
	vector2 vec;
	float x = (cos(r * (3.141592 / 180)));
	float y = (sin(r * (3.141592 / 180)));
	vec.x = x;
	vec.y = y;

	_position += vec * speed;
}

void BossBullet::Pattern3()
{

}

void BossBullet::MoveMent()
{
	switch (patternnumber)
	{
	case 1:
		Pattern1();
		break;
	case 2:
		Pattern1();
		break;
	default:
		break;
	}
}

void BossBullet::Update()
{
	AliveCheck();
	MoveMent();
	if (!ishit)
	{
		RECT rct;
		if (IntersectRect(&rct, &PlayerMNG::GetInstance()->player->collider->GetRect(), &GetRect()))
		{
			PlayerMNG::GetInstance()->player->HP--;
			cout << "SIBAL " << PlayerMNG::GetInstance()->player->HP << endl;
			ishit = true;
		}
	}
}


void BossBulletMNG::CreateBullet()
{
	for (int i = 0; i < 1000; i++)
	{
		BossBullet* bullet = new BossBullet();
		Bossbullets.push_back(bullet);
	}
}

void BossBulletMNG::SpawnBullet(int PatternNum, float rotation)
{
	for (auto it : Bossbullets)
	{
		if (!it->_visible)
		{
			it->_position = BossMNG::GetInstance()->boss->_position;
			it->Create(L"graybullet.png");
			it->patternnumber = PatternNum;
			it->r = rotation;
			it->_visible = true;

			return;
		}
	}
}


void BossBulletMNG::DeleteBullet()
{
	for (auto it : Bossbullets)
	{
		delete it;
	}
	Bossbullets.clear();
}
