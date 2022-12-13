#pragma once
#pragma comment (lib,"dxguid.lib") 
#pragma comment (lib,"dinput8.lib")
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <fstream>
#include <tchar.h>

#include <d3d9.h>
#include <d3dx9.h>
#include <XAudio2.h>
#include <dinput.h>

#include "Engine/Graphics/DirectX/DirectX9.h"
#include "Engine/Audio/XAudio2/XAudio2.h"
#include "Engine/Input/Keyboard/Keyboard.h"
#include "Engine/Input/Mouse/Mouse.h"
#include "Engine/Graphics/Sprite/Sprite.h"
#include "Engine/Math/Math.h"

#include "Enum.h"
#include "Game/Game.h"
#include "Game/Map/Map.h"
#include "Game/Player/Player.h"