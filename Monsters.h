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
	//�� ���ͳѹ��� �갡 ���� �ൿ�� ���� ������. �� �� �����۵� �Ȱ��� �����ϸ��
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