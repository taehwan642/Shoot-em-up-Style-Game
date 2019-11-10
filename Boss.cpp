#include "DXUT.h"
#include "Boss.h"

Boss::Boss()
{
	Create(L"grayplane.png");
	cout << "SIBAL" << endl;
	fTime = 0;
	fPos = 0;
	HP = 10;
	/*_scale.x = 0.005f;
	_scale.y = 0.005f;*/
	_scale = { 1,1 };
	_position.x = 180;
	_position.y = 30;
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

void Boss::BossMoveMent(float position ,float cycle, float radius)
{
	fTime += Time::deltaTime * cycle;
	position = cos(fTime) * radius;
	_position.x += position;
}

void Boss::Pattern1()
{

}





void Boss::Update()
{
	BossMoveMent(0 ,1.0f, 0.8f);

	if (HP <= 0)
		_visible = false;

}



void BossMNG::CreateBoss()
{
	boss = new Boss();
}