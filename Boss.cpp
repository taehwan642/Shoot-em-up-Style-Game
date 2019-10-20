#include "DXUT.h"
#include "Boss.h"

Boss::Boss()
{
	Create(L"Boss.jpg");
	_visible = true;
	cout << "SIBAL" << endl;

}

void Boss::Update()
{
}

void BossMNG::CreateBoss()
{
	bos = std::make_unique<Boss>();
}

