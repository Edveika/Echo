#pragma once

#ifdef _XBOX //Big-Endian
#define fourccRIFF 'RIFF'
#define fourccDATA 'data'
#define fourccFMT 'fmt '
#define fourccWAVE 'WAVE'
#define fourccXWMA 'XWMA'
#define fourccDPDS 'dpds'
#endif

#ifndef _XBOX //Little-Endian
#define fourccRIFF 'FFIR'
#define fourccDATA 'atad'
#define fourccFMT ' tmf'
#define fourccWAVE 'EVAW'
#define fourccXWMA 'AMWX'
#define fourccDPDS 'sdpd'
#endif

class XAudio2
{
private:
	IXAudio2* pXAudio2 = nullptr;
	IXAudio2MasteringVoice* pMasterVoice = nullptr;

	WAVEFORMATEXTENSIBLE wfx = { 0 };
	XAUDIO2_BUFFER buffer = { 0 };

	DWORD dwChunkSize;
	DWORD dwChunkPosition;

public:
	XAudio2();
	~XAudio2();

	bool InitXAudio2();
	IXAudio2SourceVoice* LoadAudioData(LPCWSTR fileName);
	bool StartAudio(IXAudio2SourceVoice* pSourceVoice);
	bool StopAudio(IXAudio2SourceVoice* pSourceVoice);

private:
	bool CreateXAudio2Device();
	bool CreateIXAudio2MasteringVoiceObj();
	HRESULT FindChunk(HANDLE hFile, DWORD fourcc, DWORD& dwChunkSize, DWORD& dwChunkDataPosition);
	HRESULT ReadChunkData(HANDLE hFile, void* buffer, DWORD buffersize, DWORD bufferoffset);
};