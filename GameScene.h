#pragma once
#include "Scene.h"
#include "Types.h"
#include "Sprite.h"
#include "Camera.h"
#include "MainScene.h"
#include "Boss.h"
#include "Player.h"
#include "Bullet.h"

#define  CameraSize  Camera::GetInstance()->_CameraSize
#define PlayerPos PlayerMNG::GetInstance()->player->_position

class GameScene :
	public Scene
{
public:
	Sprite* collider;
	Sprite* backGround;
	vector2 cameramovedistance;
	vector2 mousepointer;
	void Init() override;
	void Update() override;
	void OnExit() override;
};

