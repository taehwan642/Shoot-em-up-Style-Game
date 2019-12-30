#pragma once
#include "Sprite.h"
#include "Player.h"
class Health :
	public Sprite
{
public:
	Health();

};

class HealthMNG : public Singleton<HealthMNG>
{
public:
	vector<Health*> healths;
	void CreateHealth();
	void SetHealth();
	void HealthControl(int num);
};