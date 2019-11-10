#include "DXUT.h"
#include "GameScene.h"

void GameScene::Init()
{
	backGround = new Sprite();
	backGround->Create(L"ENGINE_1.jpg");
	backGround->isUI = false;
	backGround->_scale = { 20,10 };
	BossMNG::GetInstance()->CreateBoss();
	PlayerMNG::GetInstance()->CreatePlayer();
	BulletMNG::GetInstance()->CreateBullet();

	Camera::GetInstance()->CameraInit();
	collider = new Sprite();
	collider->Create(L"collider.png");
	collider->isUI = false;
	cout << "Game" << endl;

	


	Camera::GetInstance()->_CameraSize =1;

}

void GameScene::Update()
{
	Camera::GetInstance()->Update();
	Camera::GetInstance()->SetPos(PlayerMNG::GetInstance()->player->_position);

	collider->_position = PlayerMNG::GetInstance()->player->_position;

	PlayerMNG::GetInstance()->player->Goto(Director::GetInstance()->GetMousePos(),500);

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
