#include "DXUT.h"
#include "Fog.h"


Fog::Fog()
{
	Create(L"fog.png");
	_pivot = { 0,0 };
	_layer = 2;

	SetFog();
}

void Fog::SetFog()
{
	texture->_texture->LockRect(0, &LockRect, 0, D3DLOCK_DISCARD);
	pColor = (DWORD*)LockRect.pBits;

	for (int y = 0; y < 5000; ++y)
	{
		for (int x = 0; x < 5000; ++x)
		{
			int nIdx = y * 5000 + x;

			COLOR xclr = pColor[nIdx];
			xclr2[nIdx].r = xclr.r;
			xclr2[nIdx].g = xclr.g;
			xclr2[nIdx].b = xclr.b;

			xclr.r = 0.01f;
			xclr.g = 0.01f;
			xclr.b = 0.01f;
			xclr.a = 0.8f;
			pColor[nIdx] = xclr;
		}
	}
	texture->_texture->UnlockRect(0);
}

void Fog::SetFog(vector2 _pos)
{
	texture->_texture->LockRect(0, &LockRect, 0, D3DLOCK_DISCARD);
	pColor = (DWORD*)LockRect.pBits;

	for (int i = _pos.y - 100; i <= _pos.y + 100; i++)
	{
		for (int j = _pos.x - 100; j <= _pos.x + 100; j++)
		{
			int d = (int)sqrt((i - _pos.y) * (i - _pos.y) + (j - _pos.x) * (j - _pos.x));
			if (d <= 100)
			{
				int nIdx = i * 5000 + j;
				if (nIdx >= 25000000 || nIdx <= 0)
				{
					return;
				}
				COLOR xclr = pColor[nIdx];
				if (xclr.a > 0)
				{
					xclr.a = 0;
					pColor[nIdx] = xclr;
				}
			}
		}
	}
	texture->_texture->UnlockRect(0);
}

void Fog::Update()
{
}
