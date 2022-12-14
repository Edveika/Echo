#include "../../Includes.h"

XAudio2::XAudio2()
{
	if (!CreateXAudio2Device())
		MessageBoxA(NULL, "Failed to create XAudio2 device!", NULL, NULL);

	if (!CreateIXAudio2MasteringVoiceObj())
		MessageBoxA(NULL, "Failed to create a voice!", NULL, NULL);
}

XAudio2::~XAudio2()
{

}

bool XAudio2::CreateXAudio2Device()
{
	HRESULT hr;

	// Create xAudio2 device
	hr = XAudio2Create(&pXAudio2, 0, XAUDIO2_DEFAULT_PROCESSOR);

	if (FAILED(hr))
		return false;

	return true;
}

bool XAudio2::CreateIXAudio2MasteringVoiceObj()
{
	HRESULT hr;

	// Creates a IXAudio2MasteringVoice object
	hr = pXAudio2->CreateMasteringVoice(&pMasterVoice);

	if (FAILED(hr))
		return false;

	return true;
}

HRESULT XAudio2::FindChunk(HANDLE hFile, DWORD fourcc, DWORD& dwChunkSize, DWORD& dwChunkDataPosition)
{
	HRESULT hr = S_OK;
	if (INVALID_SET_FILE_POINTER == SetFilePointer(hFile, 0, NULL, FILE_BEGIN))
		return HRESULT_FROM_WIN32(GetLastError());

	DWORD dwChunkType;
	DWORD dwChunkDataSize;
	DWORD dwRIFFDataSize = 0;
	DWORD dwFileType;
	DWORD bytesRead = 0;
	DWORD dwOffset = 0;

	while (hr == S_OK)
	{
		DWORD dwRead;
		if (0 == ReadFile(hFile, &dwChunkType, sizeof(DWORD), &dwRead, NULL))
			hr = HRESULT_FROM_WIN32(GetLastError());

		if (0 == ReadFile(hFile, &dwChunkDataSize, sizeof(DWORD), &dwRead, NULL))
			hr = HRESULT_FROM_WIN32(GetLastError());

		switch (dwChunkType)
		{
		case fourccRIFF:
			dwRIFFDataSize = dwChunkDataSize;
			dwChunkDataSize = 4;
			if (0 == ReadFile(hFile, &dwFileType, sizeof(DWORD), &dwRead, NULL))
				hr = HRESULT_FROM_WIN32(GetLastError());
			break;

		default:
			if (INVALID_SET_FILE_POINTER == SetFilePointer(hFile, dwChunkDataSize, NULL, FILE_CURRENT))
				return HRESULT_FROM_WIN32(GetLastError());
		}

		dwOffset += sizeof(DWORD) * 2;

		if (dwChunkType == fourcc)
		{
			dwChunkSize = dwChunkDataSize;
			dwChunkDataPosition = dwOffset;
			return S_OK;
		}

		dwOffset += dwChunkDataSize;

		if (bytesRead >= dwRIFFDataSize) return S_FALSE;

	}

	return S_OK;
}

HRESULT XAudio2::ReadChunkData(HANDLE hFile, void* buffer, DWORD buffersize, DWORD bufferoffset)
{
	HRESULT hr = S_OK;
	if (INVALID_SET_FILE_POINTER == SetFilePointer(hFile, bufferoffset, NULL, FILE_BEGIN))
		return HRESULT_FROM_WIN32(GetLastError());

	DWORD dwRead;
	if (0 == ReadFile(hFile, buffer, buffersize, &dwRead, NULL))
		hr = HRESULT_FROM_WIN32(GetLastError());

	return hr;
}

IXAudio2SourceVoice* XAudio2::LoadAudioData(LPCWSTR fileName)
{
	HRESULT hr;
	IXAudio2SourceVoice* pSourceVoice;

	// Open the file
	HANDLE hFile = CreateFile
	(
		fileName,
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		0,
		NULL
	);

	if (INVALID_HANDLE_VALUE == hFile)
		return NULL;

	if (INVALID_SET_FILE_POINTER == SetFilePointer(hFile, 0, NULL, FILE_BEGIN))
		return NULL;

	//check the file type, should be fourccWAVE or 'XWMA'
	FindChunk(hFile, fourccRIFF, dwChunkSize, dwChunkPosition);
	DWORD filetype;
	ReadChunkData(hFile, &filetype, sizeof(DWORD), dwChunkPosition);
	if (filetype != fourccWAVE)
		return NULL;

	FindChunk(hFile, fourccFMT, dwChunkSize, dwChunkPosition);
	ReadChunkData(hFile, &wfx, dwChunkSize, dwChunkPosition);

	//fill out the audio data buffer with the contents of the fourccDATA chunk
	FindChunk(hFile, fourccDATA, dwChunkSize, dwChunkPosition);
	BYTE* pDataBuffer = new BYTE[dwChunkSize];
	ReadChunkData(hFile, pDataBuffer, dwChunkSize, dwChunkPosition);

	buffer.AudioBytes = dwChunkSize;  //size of the audio buffer in bytes
	buffer.pAudioData = pDataBuffer;  //buffer containing audio data
	buffer.Flags = XAUDIO2_END_OF_STREAM; // tell the source voice not to expect any data after this buffer

	if (FAILED(hr = pXAudio2->CreateSourceVoice(&pSourceVoice, (WAVEFORMATEX*)&wfx)))
		return NULL;

	if (FAILED(hr = pSourceVoice->SubmitSourceBuffer(&buffer)))
		return NULL;

	return pSourceVoice;
}

bool XAudio2::StartAudio(IXAudio2SourceVoice* pSourceVoice)
{
	HRESULT hr;

	if (FAILED(hr = pSourceVoice->Start(0)))
		return false;
	
	return true;
}

bool XAudio2::StopAudio(IXAudio2SourceVoice* pSourceVoice)
{
	HRESULT hr;

	if (FAILED(hr = pSourceVoice->Stop(0)))
		return false;

	return false;
}