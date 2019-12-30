#include "DXUT.h"
#include "Monsters.h"

Monsters::Monsters()
{
	fHP = 3;
	fSpeed = 8;
	monsternum = 0;
	timer = 0;
	newx = 0;
	newy = 0;
	circletime = 0;
	radius = 4;
	newpos = { 0,0 };
	firstx = 0;
	firsty = 0;
	Create(L"grayplane.png");

	_position = { newx,newy };
	_scale = { 2,2 };
	_visible = false;
	isUI = false;
}

void Monsters::Movement()
{
	if (circletime == 24)
		monsternum = 2;
	switch (monsternum)
	{
	case 0:
		if (_position.y < firsty)
			_position.y += fSpeed / 4;
		else
		{
			firstx = _position.x;
			newy = firsty;
			monsternum = 1;
		}
		break;
	case 1:
		timer += Time::deltaTime * fSpeed;
		newx += radius * cos(timer);
		newy += radius * sin(timer);
		newpos = { newx,newy };
		_position = newpos;
		if ((firstx - newx) > 0.01f)
		{
			circletime++;
		}
		//cout << newx << " " << firstx << endl;
		break;
	case 2:
		_position.y += fSpeed / 4;
		break;
	default:
		break;
	}
}

void Monsters::Collision()
{
	if (!_visible)
		return;
	RECT rr;
	if (IntersectRect(&rr, &PlayerMNG::GetInstance()->player->GetRect(), &GetRect()))
	{
		PlayerMNG::GetInstance()->player->HP--;
		HealthMNG::GetInstance()->HealthControl(1);
		_visible = false;
	}

	for (auto it : BulletMNG::GetInstance()->bullets)
	{
		if (!it->ishit && it->_visible)
		{
			RECT rrr;
			if (IntersectRect(&rrr, &it->GetRect(), &GetRect()))
			{
				it->ishit = true;
				fHP--;
			}
		}
	}
}

void Monsters::Update()
{
	if (!_visible)
		return;
	//cout << _position.x << " " << _position.y << endl;
	Movement();
	Collision();

	if (fHP < 0)
	{
		_visible = false;
		int randnum = (rand() % 1);
		if (randnum == 0)
		{
			for (auto it : ItemMNG::GetInstance()->itemss)
			{
				if (!it->_visible)
				{
					it->_position = _position;
					it->_visible = true;
					cout << "!!!!@#!!@" << endl;

					//이거 랜덤값으로 수정해야하는데일단하자
					it->itemnum = 0;
					return;
				}
			}
		}
	}
}

MonstersMNG::MonstersMNG()
{
	monshealth = 3;
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
		if (!it->_visible)
		{
			it->monsternum = monsternumber;
			it->fHP = monshealth;
			it->newy = -10;
			int randx = ((rand() % 300) + 30);
			it->newx = randx;
			it->circletime = 0;
			it->_position = { it->newx,it->newy };
			//30 180
			it->firsty = (rand() % 150) + 30;
			it->_visible = true;
			return;

		}
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
