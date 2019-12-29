#pragma once
#include "Scene.h"
#include "Types.h"
#include "Sprite.h"
#include "Camera.h"
#include "MainScene.h"
#include "Boss.h"
#include "Player.h"
#include "Monsters.h"
#include "Bullet.h"
#include "BossBullet.h"
#include "Items.h"
#define PlayerPos PlayerMNG::GetInstance()->player->_position

class GameScene :
	public Scene
{
public:
	Sprite* BackGroundScroll[2];
	Sprite* Blood;
	Sprite* PlayerHP[3];
	vector2 cameraPos;
	float shootingtimer;
	float monsterspawntimer;
	void Init() override;
	void Update() override;
	void OnExit() override;
};

