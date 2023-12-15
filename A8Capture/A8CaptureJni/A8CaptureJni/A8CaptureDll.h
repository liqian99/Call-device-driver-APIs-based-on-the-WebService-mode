#pragma once

#include "PubDefines.h"
#include <Windows.h>

class A8CaptureDll
{
public:
	A8CaptureDll();
	~A8CaptureDll();

private:
	typedef int  (__stdcall *pIO_OpenDevice)(int modules, void* hWnd);
	typedef void (__stdcall *pIO_CloseDevice)();
	typedef int  (__stdcall *pIO_CaptureBuf)(unsigned char *ir, int *irw, int *irh, int *irbits,
						unsigned char *wh, int *whw, int *whh, int *whbits,
						unsigned char *uv, int *uvw, int *uvh, int *uvbits, int cardtype);
	typedef int  (__stdcall *pIO_SaveFile)(const char *fileName, unsigned char *img, int w, int h, int bits, int quality);
	typedef int  (__stdcall *pIO_CaptureFileFullImage)(const char *irFileName,
						const char *whFileName,
						const char *uvFileName);
	//
	typedef char* (__stdcall *pIO_GetAppDataPath)();
	typedef char* (__stdcall *pIO_GetMainDllPath)();

	pIO_OpenDevice            IO_OpenDevice;
	pIO_CloseDevice           IO_CloseDevice;
	pIO_CaptureBuf            IO_CaptureBuf;	
	pIO_CaptureFileFullImage  IO_CaptureFileFullImage;
	pIO_SaveFile              IO_SaveFile;
	
	pIO_GetAppDataPath        IO_GetAppDataPath;
	pIO_GetMainDllPath        IO_GetMainDllPath;

public:
	int  openDevice(int module);
	void closeDevice();
	int  captureFileFullImage(const char *irFileName,
			const char *whFileName,
			const char *uvFileName);
	int captureBuf(unsigned char *ir, int *irw, int *irh, int *irbits,
			unsigned char *wh, int *whw, int *whh, int *whbits,
			unsigned char *uv, int *uvw, int *uvh, int *uvbits, int cardtype);
	int saveFile(const char *fileName, unsigned char *img, int w, int h, int bits, int quality);
	
	char *getAppDataPath();
	char *getMainDllPath();


	char *GetDllPath();
private:
	HINSTANCE     m_hdll;
	bool          m_opened;
	char          m_MainDllPath[MAX_PATH];
};

