#include "DXUT.h"
#include "MiniMap.h"
#include "GameScene.h"
MiniMap::MiniMap()
{
	Create(L"a.png");
	_pivot = { 0,1 };
	_scale = { 0.03,0.03 };
	_position = { 0,720 };
	isUI = true;

	fog = new Sprite;
	fog->Create(L"fog.png");
	fog->_pivot = { 0,1 };
	fog->_position = { 0,720 };
	fog->isUI = true;
	fog->_layer = 11;
	fog->_scale = { 0.04,0.04 };

	s = new Sprite;
	s->Create(L"ENGINE_1.jpg");
	s->isUI = true;
	s->_layer = 12;
	s->_scale = { 0.1,0.1 };
}

MiniMap::~MiniMap()
{
}

void MiniMap::Update()
{
	cout << GameScene::hi.x << endl;
		s->_position = { _position.x - (5000 * _scale.x) + (GameScene::hi.x * _scale.x), (GameScene::hi.y * _scale.y)  };
}

void MiniMap::SetMiniMap()
{
}
