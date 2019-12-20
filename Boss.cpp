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
	pattern21 = 0;
	pattern22 = 90;
	pattern23 = 180;
	pattern24 = 270;

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
	if (timer > shootpatterndelay)
	{
		switch (patternnum)
		{
		case 1:
			Pattern1();
			break;
		case 2:
			Pattern2(pattern21);
			Pattern2(pattern22);
			Pattern2(pattern23);
			Pattern2(pattern24);

			break;
		default:
			break;
		}
		timer = 0;
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
void Boss::Pattern2(/*startrotation nees to be 0 ~ 360*/float& startrotation)
{
	cout <<"start : " <<startrotation << endl;

	if (startrotation > 360)
		startrotation = 0;


	for (int r = 0; r < 360; r += 10)
	{
		if (startrotation == r)
		{
			float x = (cos(r * (3.141592 / 180)));
			float y = (sin(r * (3.141592 / 180)));
			BossBulletMNG::GetInstance()->SpawnBullet({ x,y });
		}
	}
	startrotation += 10;
}

void Boss::Update()
{



	if (HP > 70)
	{
		PatternMNG(2, 0.1f);
	}
	else if (HP > 40)
	{
		PatternMNG(2, 0.3f);
	}
	else
	{
		PatternMNG(2, 0.3f);

	}


	BossMoveMent(0, 1.0f, 0.8f);

	if (HP <= 0)
		_visible = false;

}



void BossMNG::CreateBoss()
{
	boss = new Boss();
}