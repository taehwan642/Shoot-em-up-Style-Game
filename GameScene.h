#pragma once
#include "Scene.h"
#include "Types.h"
#include "Sprite.h"
#include "Camera.h"
#include "MainScene.h"
#include "Boss.h"
class GameScene :
	public Scene
{
public:
	void Init() override;
	void Update() override;
	void OnExit() override;
};

