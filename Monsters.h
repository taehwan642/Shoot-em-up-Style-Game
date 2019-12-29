#pragma once
#include "Sprite.h"
#include "Types.h"
#include "Player.h"
#include "Bullet.h"
class Monsters : public Sprite
{
public:
	float fHP;
	float fSpeed;
	//이 몬스터넘버로 얘가 무슨 행동을 할지 정해짐. 그 걔 아이템도 똑같이 설계하면됨
	int monsternum;
	float timer;
	float newx;
	float newy;
	float firstx;
	float firsty;
	int circletime;
	float radius;
	vector2 newpos;
	Monsters();
	void Movement();
	void Collision();
	void Update() override;
};

class MonstersMNG : public Singleton <MonstersMNG>
{
public:
	vector<Monsters*> mons;
	void CreateMonster();
	void SpawnMonster(int monsternumber);
	void DeleteMonster();
};