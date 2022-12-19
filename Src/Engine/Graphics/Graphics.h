#pragma once

class Graphics
{
public:
	LPDIRECT3DDEVICE9 pd3dDevice;

public:
	Graphics(LPDIRECT3DDEVICE9 pd3dDevice);
	~Graphics();

	void ClearScreen(int r, int g, int b);
	void DrawTexture(LPDIRECT3DTEXTURE9 texture, LPD3DXSPRITE sprite, D3DXVECTOR2 pos, RECT src, D3DCOLOR color);
	IDirect3DSurface9* GetSurfaceFromBitmap(std::string filename, int imageWidth, int imageHeight);
	void GetImageInfo(LPCWSTR fileName, D3DXIMAGE_INFO& info);
	D3DXMATRIX MatrixRotation(float rotationIndexX, float rotationIndexY, float rotationIndexZ);
	D3DXMATRIX MatrixTranslation(float translateX, float translateY, float translateZ);
	D3DXMATRIX MatrixView(D3DXVECTOR3 cameraPos, D3DXVECTOR3 lookAtPos, D3DXVECTOR3 upDir);
	D3DXMATRIX MatrixProjection(float nearViewPlane, float farViewPlane, float horizontalFOV);
	D3DXMATRIX MatrixScale(float scaleX, float scaleY, float scaleZ);
};