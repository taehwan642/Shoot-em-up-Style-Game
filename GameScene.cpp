#include "DXUT.h"
#include "GameScene.h"

void GameScene::Init()
{
	BossMNG::GetInstance()->CreateBoss();
	cout << "Game" << endl;

}

void GameScene::Update()
{
	if (DXUTWasKeyPressed('P'))
		Director::GetInstance()->ChangeScene(new MainScene);
}

void GameScene::OnExit()
{
	delete BossMNG::GetInstance()->boss;

}
