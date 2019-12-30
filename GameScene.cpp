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
	BossBulletMNG::GetInstance()->CreateBullet();
	MonstersMNG::GetInstance()->CreateMonster();
	HealthMNG::GetInstance()->CreateHealth();
	HealthMNG::GetInstance()->SetHealth();

	BulletMNG::GetInstance()->CreateBullet();
	BossMNG::GetInstance()->CreateBoss();
#pragma endregion

	cout << "Game" << endl;


	Camera::GetInstance()->_CameraSize = 1.0f;
	cameraPos = { 180,360 };
	Camera::GetInstance()->SetPos(cameraPos);
#pragma region UIinit
	Blood = new Sprite();
	Blood->Create(L"Blood.png");
	Blood->_position = { 180,700 };
	Blood->_visible = false;
	Blood->AddRenderTarget();
	/*for (int i = 0; i < 3; i++)
	{
		PlayerHP[i] = new Sprite();
		PlayerHP[i]->Create(L"redplane.png");
		PlayerHP[i]->_position = {330,(float)(i * 50) + 30};
		PlayerHP[i]->_visible = false;
	}*/
#pragma endregion
	shootingtimer = 0;
	monsterspawntimer = 0;
	monsterhealthtimer = 0;
	bosscomeout = 0;
}

void GameScene::Update()
{

	//for (int i = 0; i < PlayerMNG::GetInstance()->player->HP; i++)
	//{
	//	PlayerHP[i]->_visible = true;
	//}
	if (BossMNG::GetInstance()->boss->breadyforaction)
		Blood->_visible = true;

	shootingtimer += Time::deltaTime;
	monsterspawntimer += Time::deltaTime;
	monsterhealthtimer += Time::deltaTime;
	bosscomeout += Time::deltaTime;
	Blood->_scale = { (BossMNG::GetInstance()->boss->HP / 7),1 };
	for (int i = 0; i < 2; i++)
	{
		if (BackGroundScroll[i]->_position.y > 710)
		{
			BackGroundScroll[i]->_position.y = -720;
		}
		BackGroundScroll[i]->_position.y += 5.0f;
	}

	if(bosscomeout > 120)
		BossMNG::GetInstance()->boss->breadyforaction = true;

	if (monsterspawntimer > 2)
	{
		MonstersMNG::GetInstance()->SpawnMonster(0);
		monsterspawntimer = 0;
	}


	if (DXUTIsKeyDown(VK_SPACE))
	{
		if (PlayerMNG::GetInstance()->player->freshootingtime < shootingtimer)
		{
			BulletMNG::GetInstance()->SpawnBullet();
			shootingtimer = 0;
		}
	}

	if (monsterhealthtimer > 30)
	{
		MonstersMNG::GetInstance()->monshealth++;
		monsterhealthtimer = 0;
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
	delete PlayerMNG::GetInstance()->player->collider;
	delete PlayerMNG::GetInstance()->player;
	for (int i = 0; i < 3; i++)
	{
		delete PlayerHP[i];
	}
	BulletMNG::GetInstance()->DeleteBullet();
	BossBulletMNG::GetInstance()->DeleteBullet();
	MonstersMNG::GetInstance()->DeleteMonster();
	delete Blood;
}
