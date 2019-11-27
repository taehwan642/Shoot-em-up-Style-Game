#include "DXUT.h"
#include "GameScene.h"

void GameScene::Init()
{
#pragma region BackGroundInit
	for (int i = 0; i < 2; i++)
	{
		BackGroundScroll[i] = new Sprite();
		BackGroundScroll[i]->Create(L"BackGround.png");
		BackGroundScroll[i]->_visible = true;
		BackGroundScroll[i]->_pivot = { 0, 0 };
		BackGroundScroll[i]->_scale = { 1,1 };
		BackGroundScroll[i]->isUI = false;
		BackGroundScroll[i]->_position = { 180,360 };
	}
	BackGroundScroll[0]->_position = { 0,0 };
	BackGroundScroll[1]->_position = { 0,-720 };
	BackGroundScroll[0]->AddRenderTarget();
	BackGroundScroll[1]->AddRenderTarget();
#pragma endregion
#pragma region MNGinit
	Camera::GetInstance()->CameraInit();
	BossMNG::GetInstance()->CreateBoss();
	PlayerMNG::GetInstance()->CreatePlayer();
	BulletMNG::GetInstance()->CreateBullet();
	BossBulletMNG::GetInstance()->CreateBullet();
#pragma endregion
	collider = new Sprite();
	collider->Create(L"collider.png");
	collider->isUI = false;
	cout << "Game" << endl;

	PlayerPos = { 0,0 };

	mousepointer = { 0,0 };
	bossbulletdir = {0,1};
	Camera::GetInstance()->_CameraSize = 1.0f;
	cameraPos = { 180,360 };
	Camera::GetInstance()->SetPos(cameraPos);
}

void GameScene::Update()
{

	for (int i = 0; i < 2; i++)
	{
		if (BackGroundScroll[i]->_position.y > 714)
		{
			BackGroundScroll[i]->_position.y = -720;
		}
		BackGroundScroll[i]->_position.y += 5.5f;
	}

	collider->_position = PlayerPos;



	if (DXUTWasKeyPressed(VK_SPACE))
	{
		BulletMNG::GetInstance()->SpawnBullet();
	}

	if (DXUTWasKeyPressed('O'))
	{
		// 0, 1
		//0,5 ,1
		// -0.5 ,1
	/*	BossBulletMNG::GetInstance()->SpawnBullet({ 0,1 });
		BossBulletMNG::GetInstance()->SpawnBullet({0.5f, 1});
		BossBulletMNG::GetInstance()->SpawnBullet({-0.5f,1});*/
		for (int r = 60; r <= 125; r += 10)
		{
			float x = (cos(r * (3.141592 / 180)));
			float y = (sin(r * (3.141592 / 180)));
			BossBulletMNG::GetInstance()->SpawnBullet({ x,y });

		}

	}

	if (DXUTWasKeyPressed('P'))
		Director::GetInstance()->ChangeScene(new MainScene);
	Camera::GetInstance()->Update();
}

void GameScene::OnExit()
{
	delete BossMNG::GetInstance()->boss;
	delete PlayerMNG::GetInstance()->player;
	BulletMNG::GetInstance()->DeleteBullet();
	delete collider;
}
