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

	PlayerMNG::GetInstance()->player->_position = { 0,0 };


	mousepointer = { 0,0 };

	Camera::GetInstance()->_CameraSize = 1;

}

void GameScene::Update()
{
	Camera::GetInstance()->Update();
	Camera::GetInstance()->SetPos(PlayerMNG::GetInstance()->player->_position);

	collider->_position = PlayerMNG::GetInstance()->player->_position;

	mousepointer = Director::GetInstance()->GetMousePos();

	mousepointer -= { (360/2) * Camera::GetInstance()->_CameraSize , (720/2) * Camera::GetInstance()->_CameraSize};

	//카메라가 움직이면, 카메라가 움직인 만큼 Sprite도 더 가야함.

	cout << PlayerMNG::GetInstance()->player->_position.x << " " << mousepointer.x << endl;
	// - 180, -360 더 가야함
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
