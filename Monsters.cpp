#include "DXUT.h"
#include "Monsters.h"

Monsters::Monsters()
{
	fHP = 3;
	fSpeed = 4;
	monsternum = 0;
	timer = 0;
	newx = 300;
	newy = 180;
	radius = 1;
	newpos = { 0,0 };
	Create(L"grayplane.png");
	_scale = { 0.8f,0.8f };
	_visible = false;
	isUI = false;
}

void Monsters::Movement()
{
	switch (monsternum)
	{
	case 1:
		timer += Time::deltaTime * fSpeed;
		newx += radius * cos(timer);
		newy += radius * sin(timer);
		newpos = { newx,newy };
		_position = newpos;
		break;
	default:
		break;
	}
}

void Monsters::Update()
{
	if (!_visible)
		return;
	cout << _position.x << " " << _position.y << endl;
	Movement();
}

void MonstersMNG::CreateMonster()
{
	for (int i = 0; i < 300; i++)
	{
		Monsters* mon = new Monsters();
		mons.push_back(mon);
	}
}

void MonstersMNG::SpawnMonster(int monsternumber)
{
	for (auto it : mons)
	{
		it->monsternum = monsternumber;
		it->_position = { 180 ,300 };
		it->_visible = true;
		return;
	}
}

void MonstersMNG::DeleteMonster()
{
	for (auto it : mons)
	{
		delete it;
	}
	mons.clear();
}
