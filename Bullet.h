#pragma once
#include "Sprite.h"
class Bullet :
	public Sprite
{
public:
	Bullet();

};

class BulletMNG : public Singleton<BulletMNG>
{

};