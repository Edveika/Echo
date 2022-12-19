#include "../../Includes.h"

DirectX9::DirectX9(HINSTANCE hInstance)
{
	// Initialize the window
	if (!InitWindow(hInstance))
		MessageBoxA(NULL, "Failed to create a window!", NULL, NULL);

	// Initialize direct3d
	if (!InitDirect3D())
		MessageBoxA(NULL, "Failed to init Direct3D!", NULL, NULL);
}

DirectX9::~DirectX9()
{

}

bool DirectX9::InitWindow(HINSTANCE hInstance)
{
	// WNDCLASSEX struct describes how thw windows will look
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); // size of the struct
	wcex.style = CS_HREDRAW | CS_VREDRAW; // class style
	wcex.lpfnWndProc = (WNDPROC)WndProc; //window procedure callback
	wcex.cbClsExtra = 0; // extra bytes to allocate for this class
	wcex.cbWndExtra = 0; // extra bytes to allocate for this 
	wcex.hInstance = hInstance; // handle to the application instance
	wcex.hIcon = 0; //icon for the application
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW); // default cursor
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // background color
	wcex.lpszMenuName = L"Echo the game";    // name of menu resource 
	wcex.lpszClassName = L"Echo the game";  // name of window class 
	wcex.hIconSm = 0; // handle to the small icon
	RegisterClassEx(&wcex);

	// Create window
	wndHandle = CreateWindowW
	(
		L"Echo the game", // window class to use
		L"Echo the game", // window title
		WS_EX_TOPMOST // window style. window is going to be on top of every other window
		//| WS_POPUP  // no borders/buttons & other crap
		| WS_VISIBLE, // tells the window to display itself
		CW_USEDEFAULT, // starting x coordinate
		CW_USEDEFAULT, // starting y coordinate
		windowWidth, // window width(pixels)
		windowHeight, // window height(pixels)
		NULL, // parrent window; NULL for desktop
		NULL, // menu for the application
		hInstance, // handle to application instance
		NULL // no values passed to the window
	);

	// Make sure that the window handle created is valid
	if (!wndHandle)
		return false;

	// Render the window on the screen
	ShowWindow(wndHandle, SW_SHOW);
	UpdateWindow(wndHandle);

	// Return true, everything went ok
	return true;
}

bool DirectX9::InitDirect3D()
{
	pD3D = NULL;
	pd3dDevice = NULL;

	// Create the DirectX object
	if ((pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
		return false;

	// Gets adapter details
	D3DADAPTER_IDENTIFIER9 ident;
	pD3D->GetAdapterIdentifier(D3DADAPTER_DEFAULT, 0, &ident);

	// Collects the mode count this adapter has
	UINT numModes = pD3D->GetAdapterModeCount(D3DADAPTER_DEFAULT, D3DFMT_X8R8G8B8);

	// Use the collected mode count to gather info about each one
	for (int i = 0; i < numModes; ++i)
	{
		D3DDISPLAYMODE mode; // D3DDISPLAYMODE struct definition
		char modeStr[255]; // Temp char array

		// Get the displaymode struct for this adapter mode
		pD3D->EnumAdapterModes
		(
			D3DADAPTER_DEFAULT,
			D3DFMT_X8R8G8B8,
			i,
			&mode
		);

		// Add screen dimensions to the list
		supportedScreenDim.push_back({ (float)mode.Width, (float)mode.Height });

		// Add RefreshRate to the list
		supportedScreenRefreshRate.push_back(mode.RefreshRate);
	}

	// Fill the Present parameters struct
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferWidth = windowWidth;
	d3dpp.BackBufferHeight = windowHeight;
	d3dpp.hDeviceWindow = wndHandle;

	// Create a default DirectX device
	if (FAILED(pD3D->CreateDevice
	(
		D3DADAPTER_DEFAULT, // use the primary video adapter
		D3DDEVTYPE_REF, // create a device that uses a default Direct3D implementation
		wndHandle,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING, // ensures that your app runs on most hardware
		&d3dpp,
		&pd3dDevice // stores the created device in pd3dDevice
	)))
		return false;

	return true;
}

LRESULT CALLBACK DirectX9::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// Check any available messaged from the queue
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	// Always return the message to the default window
	// Procedure for further processing
	return DefWindowProc(hWnd, message, wParam, lParam);
}

int DirectX9::GetWindowWidth()
{
	return this->windowWidth;
}

int DirectX9::GetWindowHeight()
{
	return this->windowHeight;
}