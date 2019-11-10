#pragma once
#include "Scene.h"
#include "Types.h"
#include "Sprite.h"
#include "Camera.h"
#include "MainScene.h"
#include "Boss.h"
#include "Player.h"
#include "Bullet.h"
class GameScene :
	public Scene
{
public:
	Sprite* collider;
	Sprite* backGround;
	void Init() override;
	void Update() override;
	void OnExit() override;
};

