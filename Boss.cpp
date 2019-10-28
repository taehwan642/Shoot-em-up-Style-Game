#include "DXUT.h"
#include "Boss.h"

Boss::Boss()
{
	Create(L"Boss.png");
	cout << "SIBAL" << endl;
	fTime = 0;
	fPos = 0;
	HP = 0;
	_scale.x = 0.005f;
	_scale.y = 0.005f;
	_position.y = 0.9f;
	_visible = true;
}

//Boss Needs 3 Patterns;

void Boss::Pattern1()
{
	
}





void Boss::Update()
{
	fTime += Time::deltaTime * 1.0f;
	fPos = cos(fTime) * 0.008f;
	_position.x += fPos;
	cout << fPos << endl;

	if (HP <= 0) 
		_visible = false;

}



void BossMNG::CreateBoss()
{
	bos = std::make_unique<Boss>();
}