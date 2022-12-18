#include "../../Includes.h"

Graphics::Graphics(LPDIRECT3DDEVICE9 pd3dDevice)
{
	this->pd3dDevice = pd3dDevice;
}

Graphics::~Graphics()
{

}

void Graphics::ClearScreen(int r, int g, int b)
{
	if (FAILED(pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(r, g, b), 1.0f, 0)))
		MessageBoxA(NULL, "Failed to clear the screen!", NULL, NULL);
}

void Graphics::DrawTexture(LPDIRECT3DTEXTURE9 texture, LPD3DXSPRITE sprite, D3DXVECTOR2 pos, RECT src, D3DCOLOR color)
{
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXVECTOR3 spritePos = D3DXVECTOR3(pos.x, pos.y, 0.0f);
	if (FAILED(sprite->Draw(texture, &src, NULL, &spritePos, color)))
		MessageBoxA(NULL, "Failed to draw a sprite!", NULL, NULL);

	sprite->End();
}

IDirect3DSurface9* Graphics::GetSurfaceFromBitmap(std::string filename, int imageWidth, int imageHeight)
{
	HRESULT hResult;
	D3DXIMAGE_INFO imageInfo;
	IDirect3DSurface9* surface = NULL;

	// Get image info
	if (FAILED(D3DXGetImageInfoFromFileA(filename.c_str(), &imageInfo)))
		return NULL;

	// Create surface
	if (FAILED(pd3dDevice->CreateOffscreenPlainSurface(imageWidth, imageHeight, D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT, &surface, NULL)))
		return NULL;

	// Load bitmap to file
	if (FAILED(D3DXLoadSurfaceFromFileA(surface, NULL, NULL, filename.c_str(), NULL, D3DX_DEFAULT, 0, NULL)))
		return NULL;

	// Return the created surface
	return surface;
}

void Graphics::GetImageInfo(LPCWSTR fileName, D3DXIMAGE_INFO& info)
{
	if (FAILED(D3DXGetImageInfoFromFile(fileName, &info)))
		MessageBoxA(NULL, "Failed to get image data!", NULL, NULL);
}

//// Set rotation and translation matrices
//pd3dDevice->SetTransform(D3DTS_WORLD, &(matRotate * matTranslate));
D3DXMATRIX Graphics::MatrixRotation(float rotationIndexX, float rotationIndexY, float rotationIndexZ)
{
	// a matrices to store the rotation information
	D3DXMATRIX matRotateX;
	D3DXMATRIX matRotateY;
	D3DXMATRIX matRotateZ;

	// build a matrix to rotate the model based on the increasing float value
	D3DXMatrixRotationX(&matRotateX, rotationIndexX);
	D3DXMatrixRotationY(&matRotateY, rotationIndexY);
	D3DXMatrixRotationZ(&matRotateZ, rotationIndexZ);

	return matRotateX * matRotateY * matRotateZ;
}

D3DXMATRIX Graphics::MatrixTranslation(float translateX, float translateY, float translateZ)
{
	D3DXMATRIX matTranslate;

	D3DXMatrixTranslation(&matTranslate, translateX, translateY, translateZ);

	return matTranslate;
}

//pd3dDevice->SetTransform(D3DTS_VIEW, &matView);    // set the view transform to matView
D3DXMATRIX Graphics::MatrixView(D3DXVECTOR3 cameraPos, D3DXVECTOR3 lookAtPos, D3DXVECTOR3 upDir)
{
	D3DXMATRIX matView;

	D3DXMatrixLookAtLH(&matView,
		&cameraPos,    // the camera position
		&lookAtPos,    // the look-at position
		&upDir);    // the up direction

	return matView;
}

//pd3dDevice->SetTransform(D3DTS_PROJECTION, &matProjection);    // set the projection
D3DXMATRIX Graphics::MatrixProjection(float nearViewPlane, float farViewPlane, float horizontalFOV)
{
	D3DXMATRIX matProjection;     // the projection transform matrix

	D3DXMatrixPerspectiveFovLH(&matProjection,
		D3DXToRadian(horizontalFOV),    // the horizontal field of view
		(FLOAT)800 / (FLOAT)600, // aspect ratio // HARD CODED
		nearViewPlane,    // the near view-plane
		farViewPlane);    // the far view-plane

	return matProjection;
}

// pd3dDevice->SetTransform(D3DTS_WORLD, &matScale);
D3DXMATRIX Graphics::MatrixScale(float scaleX, float scaleY, float scaleZ)
{
	D3DXMATRIX matScale;
	D3DXMatrixScaling(&matScale, scaleX, scaleY, scaleZ);

	return matScale;
}