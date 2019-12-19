#include "DXUT.h"
#include "Boss.h"

Boss::Boss()
{
	Create(L"grayplane.png");
	cout << "SIBAL" << endl;
	fTime = 0;
	fPos = 0;
	HP = 100;
	timer = 0;
	_scale = { 3,3 };
	_position.x = 180;
	_position.y = 60;
	_visible = true;
	isUI = false;
}

//Boss Needs 3 Patterns;

void Boss::MoveMent()
{
	fTime += Time::deltaTime * 1.0f;
	fPos = cos(fTime) * 0.8f;
	_position.x += fPos;
}

void Boss::BossMoveMent(float position, float cycle, float radius)
{
	fTime += Time::deltaTime * cycle;
	position = cos(fTime) * radius;
	_position.x += position;
}

void Boss::PatternMNG(int patternnum, float shootpatterndelay)
{
	timer += Time::deltaTime;
	switch (patternnum)
	{
	case 1:
		if (timer > shootpatterndelay)
		{
			Pattern1();
			timer = 0;
		}
		break;
	default:
		break;
	}
	return;
}

void Boss::Pattern1()
{


	for (int r = 60; r <= 125; r += 10)
	{
		float x = (cos(r * (3.141592 / 180)));
		float y = (sin(r * (3.141592 / 180)));
		BossBulletMNG::GetInstance()->SpawnBullet({ x,y });
	}
	/*for (int r = 0; r <= 360; r += 10)
	{
		float x = (cos(r * (3.141592 / 180)));
		float y = (sin(r * (3.141592 / 180)));
		BossBulletMNG::GetInstance()->SpawnBullet({ x,y });
	}*/

}





void Boss::Update()
{



	if (HP > 70)
	{
		PatternMNG(1, 1);
	}


	BossMoveMent(0, 1.0f, 0.8f);

	if (HP <= 0)
		_visible = false;

}



void BossMNG::CreateBoss()
{
	boss = new Boss();
}