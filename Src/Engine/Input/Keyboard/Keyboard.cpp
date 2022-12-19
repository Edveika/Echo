#include "../../../Includes.h"

Keyboard::Keyboard(HINSTANCE hInstance)
{
	// Create direct input object
	if (!CreateDirectInputObject(hInstance))
		MessageBoxA(NULL, "Failed to create Direct input object!", NULL, NULL);

	// Create direct input device
	if (!CreateDirectInputDevice())
		MessageBoxA(NULL, "Failed to create Direct input device!", NULL, NULL);

	// Set direct input format
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
	if (FAILED(directInputDevice->GetDeviceState(sizeof(buffer), (LPVOID)&buffer)))
		MessageBoxA(NULL, "Failed to get input from a direct input device!", NULL, NULL);
}

bool Keyboard::IsPressed(int key)
{
	if (buffer[key] & 0x80)
		return true;

	return false;
}

bool Keyboard::CreateDirectInputObject(HINSTANCE hInstance)
{
	if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directObj, NULL)))
		return false;

	return true;
}

bool Keyboard::CreateDirectInputDevice()
{
	if (FAILED(directObj->CreateDevice(GUID_SysKeyboard, &directInputDevice, NULL)))
		return false;

	return true;
}

bool Keyboard::SetDataFormat()
{
	if (FAILED(directInputDevice->SetDataFormat(&c_dfDIKeyboard)))
		return false;

	return true;
}

bool Keyboard::AcquireAccess()
{
	HRESULT Aqcuire(VOID);

	if (FAILED(directInputDevice->Acquire()))
		return false;

	return true;
}