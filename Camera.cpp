#include "DXUT.h"
#include "Camera.h"

void Camera::CameraInit()
{
	//이거 전부 제데로
	D3DXMatrixOrthoLH(&OM, 360, -720, 0, 1);
	D3DXMatrixIdentity(&IM);
	_CameraSize = 5;
}

void Camera::Update()
{
	//이거 전부 제데로
	VM = D3DXMATRIX{
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		-_camPos.x,-_camPos.y,0,1 };
	D3DXMatrixOrthoLH(&OM,360 * _CameraSize,-720 * _CameraSize,0,1);
	DXUTGetD3D9Device()->SetTransform(D3DTS_PROJECTION, &OM);
	DXUTGetD3D9Device()->SetTransform(D3DTS_WORLD, &IM);
	DXUTGetD3D9Device()->SetTransform(D3DTS_VIEW, &VM);
}
