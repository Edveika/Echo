#include "../../../Includes.h"

Mouse::Mouse(HINSTANCE hInstance)
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

Mouse::~Mouse()
{

}

void Mouse::GetInput()
{
	HRESULT hr;

	hr = directInputDevice->GetDeviceState(sizeof(mouseState), (LPVOID)&mouseState);

	if (FAILED(hr))
	{
		hr = directInputDevice->Acquire();

		while (hr == DIERR_INPUTLOST)
		{
			hr = directInputDevice->Acquire();

			continue;
		}
	}
}

int Mouse::TravelX()
{
	return mouseState.lX;
}

int Mouse::TravelY()
{
	return mouseState.lY;
}

int Mouse::TravelZ()
{
	return mouseState.lZ;
}

bool Mouse::IsPressed(int button)
{
	if (mouseState.rgbButtons[button] & 0x80)
		return true;
	
	return false;
}

bool Mouse::CreateDirectInputObject(HINSTANCE hInstance)
{
	if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directObj, NULL)))
		return false;

	return true;
}

bool Mouse::CreateDirectInputDevice()
{
	if (FAILED(directObj->CreateDevice(GUID_SysMouse, &directInputDevice, NULL)))
		return false;

	return true;
}

bool Mouse::SetDataFormat()
{
	if (FAILED(directInputDevice->SetDataFormat(&c_dfDIMouse)))
		return false;

	return true;
}

bool Mouse::AcquireAccess()
{
	HRESULT Aqcuire(VOID);

	if (FAILED(directInputDevice->Acquire()))
		return false;

	return true;
}