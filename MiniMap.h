#pragma once
#include "Sprite.h"

class MiniMap : public Sprite
{
public:
	MiniMap();
	~MiniMap();
	void Update() override;
	Sprite* fog;
	void SetMiniMap();

	Sprite* s;
};

