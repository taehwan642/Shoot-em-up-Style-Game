#include "DXUT.h"
#include "Player.h"

Player::Player()
{
	Create(L"Player.png");
	fmovespeed = 6.5f;
	isUI = true;
	_scale = { 2,2 };
	_position.x = 180;
	_position.y = 500;
	_visible = true;
}

void Player::MoveMent()
{
	if (DXUTIsKeyDown('W'))
	{
		_position.y += -fmovespeed;
	}
	if (DXUTIsKeyDown('A'))
	{
		_position.x += -fmovespeed;
	}
	if (DXUTIsKeyDown('S'))
	{
		_position.y += fmovespeed;
	}
	if (DXUTIsKeyDown('D'))
	{
		_position.x += fmovespeed;
	}
}

void Player::Update()
{
	MoveMent();
}

void PlayerMNG::CreatePlayer()
{
	player = new Player();
}
