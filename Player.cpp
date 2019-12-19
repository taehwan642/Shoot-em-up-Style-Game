#include "DXUT.h"
#include "Player.h"

Player::Player()
{
	Create(L"redplane.png");
	fmovespeed = 6.5f;
	isUI = false;
	_scale = { 0.7f,0.7f };
	_position.x = 180;
	_position.y = 500;
	_visible = true;
}

void Player::MoveMent()
{
	//cout << _position.x << " " << _position.y << endl;
	if (DXUTIsKeyDown('W') && _position.y - 13 > 0)
	{
		_position.y += -fmovespeed;
	}
	if (DXUTIsKeyDown('A') && _position.x + 13 > 0)
	{
		_position.x += -fmovespeed;
	}
	if (DXUTIsKeyDown('S') && _position.y - 10 < 720) //708.5f
	{
		_position.y += fmovespeed;
	}
	if (DXUTIsKeyDown('D') && _position.x + 10 < 360)
	{
		_position.x += fmovespeed;
	}
}

void Player::Update()
{
	if (DXUTIsKeyDown(VK_LCONTROL))
	{
		fmovespeed = 2.5f;
	}
	else
	{
		fmovespeed = 6.5f;
	}
	MoveMent();
}

void PlayerMNG::CreatePlayer()
{
	player = new Player();
}
