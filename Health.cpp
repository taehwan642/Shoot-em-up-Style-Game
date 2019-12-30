#include "DXUT.h"
#include "Health.h"

Health::Health()
{
	Create(L"redplane.png");
	_visible = true;
}

void HealthMNG::CreateHealth()
{
	for (int i = 0; i < PlayerMNG::GetInstance()->player->HP; i++)
	{
		Health* health = new Health();
		healths.push_back(health);
	}
}

void HealthMNG::SetHealth()
{
	float addpos = 0;
	for (auto it : healths)
	{
		it->_position = { 330,(addpos * 50) + 30 };
		addpos++;
	}
}

void HealthMNG::HealthControl(int num)
{
	if (num == 0)
	{
		if (healths[0]->_visible && healths[1]->_visible && healths[2]->_visible)
			return;

		if (healths[0]->_visible && healths[1]->_visible && !healths[2]->_visible)
		{
			healths[2]->_visible = true;
			return;
		}

		for (int i = 0; i < healths.size(); i++)
		{
			if (healths[i]->_visible)
			{
				healths[i - 1]->_visible = true;
				PlayerMNG::GetInstance()->player->HP++;
				break;
			}
		}
	}
	else if (num == 1)
	{
		for (int i = 0; i < healths.size(); i++)
		{
			if (healths[i]->_visible)
			{
				PlayerMNG::GetInstance()->player->HP--;
				healths[i]->_visible = false;
				break;
			}
		}
	}
}
