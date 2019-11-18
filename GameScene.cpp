#include "DXUT.h"
#include "GameScene.h"

void GameScene::Init()
{
	for (int i = 0; i < 2; i++)
	{
		BackGroundScroll[i] = new Sprite();
		BackGroundScroll[i]->Create(L"BackGround.png");
		BackGroundScroll[i]->_visible = true;
		BackGroundScroll[i]->_pivot = { 0, 0 };
		BackGroundScroll[i]->_scale = { 1.5f,1.5f };
		BackGroundScroll[i]->isUI = false;
		BackGroundScroll[i]->_position = { 180,360 };
	}
	BackGroundScroll[0]->_position = { 0,0 };
	BackGroundScroll[1]->_position = { 0,-720 };
	BackGroundScroll[0]->AddRenderTarget();
	BackGroundScroll[1]->AddRenderTarget();
	

	backGround = new Sprite();
	backGround->Create(L"ENGINE_1.jpg");
	backGround->isUI = false;
	backGround->_scale = { 1,1 };
	Camera::GetInstance()->CameraInit();
	BossMNG::GetInstance()->CreateBoss();
	PlayerMNG::GetInstance()->CreatePlayer();
	BulletMNG::GetInstance()->CreateBullet();

	collider = new Sprite();
	collider->Create(L"collider.png");
	collider->isUI = false;
	cout << "Game" << endl;

	PlayerPos = { 0,0 };
	cameramovedistance = PlayerPos;

	mousepointer = { 0,0 };

	Camera::GetInstance()->_CameraSize = 1.5f;

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

	Camera::GetInstance()->SetPos(PlayerPos);

	vector2 campos = PlayerPos;

	collider->_position = PlayerPos;

	mousepointer = Director::GetInstance()->GetMousePos() * CameraSize;



	//mousepointer -= { (180 - campos.x/2) * Camera::GetInstance()->_CameraSize
	//	, (360 - campos.y/2) * Camera::GetInstance()->_CameraSize};


	mousepointer -= {180 * CameraSize - campos.x, 360 * CameraSize - campos.y};

	backGround->Goto(mousepointer, 500);

	if (Director::GetInstance()->OnMouseDown())
	{
		cout << PlayerMNG::GetInstance()->player->_position.x << " " << PlayerMNG::GetInstance()->player->_position.y << endl;
		cout << Director::GetInstance()->p.x << " " << Director::GetInstance()->p.y << endl;
	}


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
	delete BossMNG::GetInstance()->boss;
	delete PlayerMNG::GetInstance()->player;
	BulletMNG::GetInstance()->DeleteBullet();
	delete collider;
}
