#pragma once
#include "Scene.h"
#include "Types.h"
#include "Sprite.h"
#include "Camera.h"
#include "MainScene.h"
#include "Boss.h"
#include "Player.h"
#include "Bullet.h"
#include "BossBullet.h"

#define PlayerPos PlayerMNG::GetInstance()->player->_position

class GameScene :
	public Scene
{
public:
	Sprite* collider;
	Sprite* BackGroundScroll[2];
	Sprite* Blood;
	vector2 cameraPos;
	vector2 mousepointer;
	vector2 bossbulletdir;
	void Init() override;
	void Update() override;
	void OnExit() override;
};

