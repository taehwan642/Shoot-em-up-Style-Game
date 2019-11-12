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
	cameramovedistance = PlayerMNG::GetInstance()->player->_position;

	mousepointer = { 0,0 };

	Camera::GetInstance()->_CameraSize = 1;

}

void GameScene::Update()
{
	Camera::GetInstance()->Update();
	Camera::GetInstance()->SetPos(PlayerMNG::GetInstance()->player->_position);
	//카메라디스턴스   카메라가 움직인 거리 만큼, 0,0에서 카메라가 움직인 만큼 더 가줘야함

	vector2 campos = PlayerMNG::GetInstance()->player->_position;

	collider->_position = PlayerMNG::GetInstance()->player->_position;

	mousepointer = Director::GetInstance()->GetMousePos() * Camera::GetInstance()->_CameraSize;
	//180 * 2

	//360 -= (180 - 100) * 2 = 200
	// 160 -> 
	//원하는 값 = 100
	//360 - 360 - 100;


	//mousepointer -= { (180 - campos.x/2) * Camera::GetInstance()->_CameraSize
	//	, (360 - campos.y/2) * Camera::GetInstance()->_CameraSize};
	mousepointer -= {180 * 1 - campos.x, 360 * 1 - campos.y};
	//??????!?!??!?!?!?
	//2배로 움직이는걸 막으면, 완벽한 놈이 됨 그걸 해보도ㅗ록 하자 :)
	//카메라가 움직이면, 카메라가 움직인 만큼 Sprite도 더 가야함.

	cout << campos.x << " " << mousepointer.x << endl;
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
