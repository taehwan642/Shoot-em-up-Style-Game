#include "DXUT.h"
#include "GameScene.h"

void GameScene::Init()
{
	BossMNG::GetInstance()->CreateBoss();
	PlayerMNG::GetInstance()->CreatePlayer();
	BulletMNG::GetInstance()->CreateBullet();
	collider = new Sprite();
	collider->Create(L"collider.png");
	collider->isUI = true;
	cout << "Game" << endl;
}

void GameScene::Update()
{
	collider->_position = PlayerMNG::GetInstance()->player->_position;

	if (DXUTIsKeyDown(VK_SPACE))
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
