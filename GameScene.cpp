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
	PlayerMNG::GetInstance()->CreatePlayer();
	BulletMNG::GetInstance()->CreateBullet();
	BossBulletMNG::GetInstance()->CreateBullet();
	BossMNG::GetInstance()->CreateBoss();
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
#pragma region UIinit
	Blood = new Sprite();
	Blood->Create(L"Blood.png");
	Blood->_position = { 180,700 };
	Blood->AddRenderTarget();
#pragma endregion

}

void GameScene::Update()
{
	Blood->_scale = { (BossMNG::GetInstance()->boss->HP / 7),1 };
	for (int i = 0; i < 2; i++)
	{
		if (BackGroundScroll[i]->_position.y > 710)
		{
			BackGroundScroll[i]->_position.y = -720;
		}
		BackGroundScroll[i]->_position.y += 5.0f;
	}

	collider->_position = PlayerPos;



	if (DXUTWasKeyPressed(VK_SPACE))
	{
		BulletMNG::GetInstance()->SpawnBullet();
	}

	if (DXUTWasKeyPressed('P'))
		Director::GetInstance()->ChangeScene(new MainScene);

	Camera::GetInstance()->Update();
}

void GameScene::OnExit()
{
	for (int i = 0; i < 2; i++)
	{
		delete BackGroundScroll[i];
	}
	delete BossMNG::GetInstance()->boss;
	delete PlayerMNG::GetInstance()->player;
	BulletMNG::GetInstance()->DeleteBullet();
	BossBulletMNG::GetInstance()->DeleteBullet();
	delete collider;
}
