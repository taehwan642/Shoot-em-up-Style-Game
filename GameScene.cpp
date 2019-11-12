#include "DXUT.h"
#include "GameScene.h"

void GameScene::Init()
{
	backGround = new Sprite();
	backGround->Create(L"ENGINE_1.jpg");
	backGround->isUI = false;
	backGround->_scale = { 1,1 };
	BossMNG::GetInstance()->CreateBoss();
	PlayerMNG::GetInstance()->CreatePlayer();
	BulletMNG::GetInstance()->CreateBullet();

	Camera::GetInstance()->CameraInit();
	collider = new Sprite();
	collider->Create(L"collider.png");
	collider->isUI = false;
	cout << "Game" << endl;

	PlayerPos = { 0,0 };
	cameramovedistance = PlayerPos;

	mousepointer = { 0,0 };

	Camera::GetInstance()->_CameraSize = 2;

}

void GameScene::Update()
{
	Camera::GetInstance()->Update();
	Camera::GetInstance()->SetPos(PlayerPos);

	vector2 campos = PlayerPos;

	collider->_position = PlayerPos;

	mousepointer = Director::GetInstance()->GetMousePos() * CameraSize;



	//mousepointer -= { (180 - campos.x/2) * Camera::GetInstance()->_CameraSize
	//	, (360 - campos.y/2) * Camera::GetInstance()->_CameraSize};
	mousepointer -= {180 * CameraSize - campos.x, 360 * CameraSize - campos.y};
	//??????!?!??!?!?!?

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
}

void GameScene::OnExit()
{
	delete BossMNG::GetInstance()->boss;
	delete PlayerMNG::GetInstance()->player;
	BulletMNG::GetInstance()->DeleteBullet();
	delete collider;
}
