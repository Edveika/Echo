#include "../../Includes.h"

Keyboard::Keyboard(HINSTANCE hInstance)
{
	// Create direct input object
	if (!CreateDirectInputObject(hInstance))
		MessageBoxA(NULL, "Failed to create Direct input object!", NULL, NULL);

	// Create direct input device
	if (!CreateDirectInputDevice())
		MessageBoxA(NULL, "Failed to create Direct input device!", NULL, NULL);

	// Set directin input format
	if (!SetDataFormat())
		MessageBoxA(NULL, "Failed to set data format!", NULL, NULL);

	// Acquire access
	if (!AcquireAccess())
		MessageBoxA(NULL, "Failed to acquire access!", NULL, NULL);
}

Keyboard::~Keyboard()
{

}

void Keyboard::GetInput()
{
	// Get keyboard input
	directInputDevice->GetDeviceState(sizeof(buffer), (LPVOID)&buffer);
}

bool Keyboard::IsPressed(char key)
{
	// If they key is down
	if (buffer[key] & 0x80)
		// Return true
		return true;

	// Else return false
	return false;
}

bool Keyboard::CreateDirectInputObject(HINSTANCE hInstance)
{
	HRESULT hr;

	// Create the direct input object
	hr = DirectInput8Create
	(
		hInstance, // hInstance
		DIRECTINPUT_VERSION, // version of direct input(default value)
		IID_IDirectInput8, // identifier of the required device(default value)
		(void**)&directObj, // direct input is going to be created in this variable
		NULL // null(default value)
	);

	// If creating the obj failed
	if (FAILED(hr))
		// Return fail
		return false;

	// Return ok
	return true;
}

bool Keyboard::CreateDirectInputDevice()
{
	HRESULT hr;

	// Create direct input device
	hr = directObj->CreateDevice
	(
		GUID_SysKeyboard, // can be GUID_SysKeyboard/mouse or any value returned from EnumDevices
		&directInputDevice, // create device in this variable
		NULL // NULL(default value)
	);

	// If creating the device failed
	if (FAILED(hr))
		// Return fail
		return false;

	// Return ok
	return true;
}

bool Keyboard::SetDataFormat()
{
	HRESULT hr;

	// Sets data format to keyboard
	//hr = directInputDevice->SetDataFormat(&c_dfDIKeyboard);

	hr = directInputDevice->SetDataFormat(&c_dfDIKeyboard);

	if (FAILED(hr))
		return false;

	return true;
}

bool Keyboard::AcquireAccess()
{
	HRESULT hr;
	HRESULT Aqcuire(VOID);

	hr = directInputDevice->Acquire();

	if (FAILED(hr))
		return false;

	return true;
}