#include "pch.h"
#include <stdio.h>
#include "A8CaptureDll.h"

extern HMODULE g_hDllMainModule;

A8CaptureDll::A8CaptureDll()
{
	m_hdll = NULL;
	IO_OpenDevice  = NULL;
	IO_CloseDevice = NULL;
	IO_CaptureBuf  = NULL;
	IO_CaptureFileFullImage = NULL;
	IO_SaveFile            = NULL;


	m_opened = false;
}


A8CaptureDll::~A8CaptureDll()
{
	closeDevice();
}

int A8CaptureDll::openDevice(int module) {
	char dllPath[MAX_PATH] = {0};
	m_opened = false;
	sprintf_s(dllPath, MAX_PATH, "%s/A8Capture.dll", GetDllPath());
	printf("A8Capture.dll path=%s\n",dllPath);
	m_hdll = LoadLibrary(dllPath);
	if (!m_hdll) {
		delete[] dllPath;
		return (A8C_LOAD3RDDLL_ERR);
	}

	IO_OpenDevice  = (pIO_OpenDevice)GetProcAddress(m_hdll, "IO_OpenDevice");
	IO_CloseDevice = (pIO_CloseDevice)GetProcAddress(m_hdll, "IO_CloseDevice");
	IO_CaptureBuf  = (pIO_CaptureBuf)GetProcAddress(m_hdll, "IO_CaptureBuf");
	IO_CaptureFileFullImage = (pIO_CaptureFileFullImage)GetProcAddress(m_hdll, "IO_CaptureFileFullImage");
	IO_SaveFile             = (pIO_SaveFile)GetProcAddress(m_hdll, "IO_SaveFile");
	
	IO_GetAppDataPath = (pIO_GetAppDataPath)GetProcAddress(m_hdll, "IO_GetAppDataPath");
	IO_GetMainDllPath = (pIO_GetMainDllPath)GetProcAddress(m_hdll, "IO_GetMainDllPath");
	
	int ret = IO_OpenDevice(module,NULL);
	if (ret == A8C_SUCC)
		m_opened = true;

	
	return ret;
}

void A8CaptureDll::closeDevice() {
	if (IO_CloseDevice)
		IO_CloseDevice();
	IO_CloseDevice = NULL;

	if (m_hdll)
		FreeLibrary(m_hdll);  //不知为什么webservice调这会崩
	m_hdll = NULL;
}


int A8CaptureDll::captureFileFullImage(const char *irFileName,
	const char *whFileName,
	const char *uvFileName) {

	if (m_opened)
		return IO_CaptureFileFullImage(irFileName,whFileName,uvFileName);

	return A8C_LOAD3RDDLL_ERR;
}

int A8CaptureDll::captureBuf(unsigned char *ir, int *irw, int *irh, int *irbits,
	unsigned char *wh, int *whw, int *whh, int *whbits,
	unsigned char *uv, int *uvw, int *uvh, int *uvbits, int cardtype) {

	if (m_opened) {
		return IO_CaptureBuf(ir, irw, irh, irbits,
			wh, whw, whh, whbits,
			uv, uvw, uvh, uvbits, cardtype);
	}

	return A8C_LOAD3RDDLL_ERR;
}

int A8CaptureDll::saveFile(const char *fileName, unsigned char *img, int w, int h, int bits, int quality) {

	if (m_opened)
		return IO_SaveFile(fileName, img, w, h, bits, quality);

	return A8C_LOAD3RDDLL_ERR;
}

char *A8CaptureDll::getAppDataPath() {
	if (m_opened)
		return IO_GetAppDataPath();
	return NULL;
}
char *A8CaptureDll::getMainDllPath() {
	if (m_opened)
		return IO_GetMainDllPath();
	return NULL;
}

char *A8CaptureDll::GetDllPath(){
	//主dll所在路径
	char *pchTemp = NULL;
	memset(m_MainDllPath, 0x00, sizeof(m_MainDllPath));
	GetModuleFileNameA((HMODULE)g_hDllMainModule, m_MainDllPath, MAX_PATH); //HMODULE 
	printf("Main dll path=%s\n", m_MainDllPath);
	pchTemp = m_MainDllPath + strlen(m_MainDllPath);
	while (*pchTemp != '\\')
		pchTemp--;
	*pchTemp = '\0';
	printf("Main dll path=%s\n", m_MainDllPath);
	return m_MainDllPath;
}
