#pragma once
#include "Sprite.h"
class Fog :
	public Sprite
{
public:
	Fog();
	void SetFog();
	void SetFog(vector2 _pos);
	void Update() override;

	COLOR xclr2[25000000];
	D3DLOCKED_RECT LockRect;
	DWORD* pColor;
};

