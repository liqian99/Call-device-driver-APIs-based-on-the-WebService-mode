#pragma once

#include "PubDefines.h"

#ifdef A8CAPTURE_EXPORTS
#define A8CAPTURE_API __declspec(dllexport)
#else
#define A8CAPTURE_API __declspec(dllimport)
#endif

extern "C"
{

	/*
	@brief Open the device and initialize all resources. 
	@param modules[in] is external device type.
	       1 is only A8 Capture
		   2 can support OCR
		   4 can support barcode
		   8 is china's second generation card reader
    @param hWnd[in] is the handle of a window or control, will show
	      camera preview while is not null(reserved).
    @return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_OpenDevice(int modules, void* hWnd);

	/*
	@brief Close the device and release all resources.
	@param void
	@return void
	*/
	A8CAPTURE_API void __stdcall IO_CloseDevice();

	A8CAPTURE_API void __stdcall IO_CloseDeviceEx();

	/*
	@brief calibrate the device, should call the function while the device used on the host of the first time.
	@param void
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_Calibrate();
	

	/*
	@brief Capture image buffer from device. If the parameter of a certain light is empty, 
	       this image is not generated.
	@param ir[out] is infrared image��need to allocate enough memory in advance��NULL is not capture.
	@param irw[out] is infrared image width.
	@param irh[out] is infrared image height.
	@param irbits[out] is infrared image bits per pixel(8��24).
	@param wh[out] is color image��need to allocate enough memory in advance��NULL is not capture.
	@param whw[out] is color image width.
	@param whh[out] is color image height.
	@param whbits[out] is color image bits per pixel(8��24).
	@param uv[out] is ultraviolet image��need to allocate enough memory in advance��NULL is not capture.
	@param uvw[out] is ultraviolet image width.
	@param uvh[out] is ultraviolet image height.
	@param uvbits[out] is ultraviolet image bits per pixel(8��24).
	@param cardtype[in] is card type
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_CaptureBuf(unsigned char *ir,int *irw,int *irh,int *irbits,
	                                          unsigned char *wh, int *whw, int *whh, int *whbits,
		                                      unsigned char *uv, int *uvw, int *uvh, int *uvbits,
	                                          int cardtype);

	/*
	@brief Capture image files from device. If the parameter of a certain light is empty,
		   this image is not generated.
	@param irFileName[in] is infrared image file name, will not generate if the filename is NULL.
	@param whFileName[in] is color image file name, will not generate if the filename is NULL.
	@param uvFileName[in] is ultraviolet image file name, will not generate if the filename is NULL.
	@param cardtype[in] is card type
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_CaptureFile(const char *irFileName,
		                                       const char *whFileName,
		                                       const char *uvFileName,
		                                       int cardtype);
	A8CAPTURE_API int __stdcall IO_CaptureFileEx(const char *irFullFileName, const char *irCroppedFileName,
											     const char *whFullFileName, const char *whCroppedFileName,
											     const char *uvFullFileName, const char *uvCroppedFileName,
											     int cardtype);

	/*
	@brief Capture the full image files without cut  from device. If the parameter of a certain light is empty,
		   this image is not generated.
	@param irFileName[in] is infrared image file name, will not generate if the filename is NULL.
	@param whFileName[in] is color image file name, will not generate if the filename is NULL.
	@param uvFileName[in] is ultraviolet image file name, will not generate if the filename is NULL.
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_CaptureFileFullImage(const char *irFileName,
		const char *whFileName,
		const char *uvFileName);


	/*
	@brief save image as a file.
	@param img[in] is image buffer.
	@param w[in] is image width.
	@param h[in] is image height.
	@param bits[in] is image bits per pixel(8��24).
	@param quality[in] is image quality while save as jpeg 
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_SaveFile(const char *fileName,unsigned char *img, int w, int h, int bits,int quality);

	/*
	@brief load image buffer form file.
	@param fileName[in] the image file path and name.
	@param img[out] is image buffer, after used,the buffer need call IO_BuffFree to release.
	@param w[out] is image width.
	@param h[out] is image height.
	@param bits[out] is image bits per pixel(8��24).
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_LoadFile(const char *fileName, unsigned char **img, int *w, int *h, int *bits);

	/*
	@brief release image buffer.
	@param img[in] is image buffer, this buffer is generated by IO_LoadFile.
	@return void.
	*/
	A8CAPTURE_API void __stdcall IO_BufFree(unsigned char *img);

	/*
	@brief beep duration.
	@param delay[in] is duration,unit is millisecond.
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_Beep(int delay);

	/*
	@brief led light.
	@param mode[in] is Lighting color, 
	       0 is off. 1 is green on,2 is red on,3 is all on.
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_SetLed(int mode);

	/*
	@brief camera sensor light.
	@param mode[in] camera sensor light, 0 is off. 
	       1 is ir,2 is color(white),3 is uv.
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_SetSensorLight(int mode);

	/*
	@brief check card on the device or not.
	@param status[out] 
	      0 is unknown status, 1 is the card is not on the device, 2 is the card on the device   
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_GetCardStatus(int *status);

	/*
	@brief get the device pid and vid.
	@param vid[out] the device vid
	@param pid[out] the device pid
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_GetVidPid(unsigned short *vid,unsigned short *pid);

	/*
	@brief get the device serial number
	@param sn[out] the serial number,should malloc buffer in advance
	@param len[out] the serial number string length.
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_GetSN(char *sn,int *len);

	/*
	@brief get the device firmware version
	@param version[out] the firmware version,should malloc buffer in advance
	@param len[out] the firmware version string length.
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_GetFirmwareVersion(char *version, int *len);

	/*
	@brief reboot the device
	@param void
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_RebootDevice();


	/*******************************************************
	* china second ID reader
	*******************************************************/
	/*
	@brief read the china second ID contents;
	@param imgFileName[in] the head portrait file path and name.
	@param cardDetails[out] the second ID contents.
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_ReadID(const char *imgFileName, CardDetails *cardDetails);

	/*
	@brief get the second ID reader SAM ID
	@param samID[out] the SAM ID,should malloc buffer in advance
	@param len[out] the SAM ID string length.
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_GetSAMID(char *samID, int *len);

	/************************************************************
	*  OCR
	*************************************************************/
	/*
	@brief recognize image buffer(OCR)
	@param img[in] the image buffer.
	@param w[in] the image width.
	@param h[in] the image height.
	@param bits[in] the bits of per pixel(8 or 24).
	@param cardType[in] the card type.
	@param cardDetails[out] the contents of recognized.
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_RecognizeBuf(unsigned char *img,int w,int h,int bits,int cardType, CardDetails *cardDetails);

	/*
	@brief recognize image file(OCR)
	@param imgFileName[in] the image file.
	@param cardType[in] the card type.
	@param cardDetails[out] the contents of recognized.
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_RecognizeFile(const char *imgFileName, int cardType, CardDetails *cardDetails);

	/*
	@brief capture image file and recognize(OCR).
	@param imgFileNameIr[in] is infrared image file name, will not generate if the filename is NULL.
	@param imgFileNameWh[in] is color image file name, will not generate if the filename is NULL.
	@param imgFileNameUv[in] is ultraviolet image file name, will not generate if the filename is NULL.
	@param cardType[in] the card type.
	@param cardDetails[out] the contents of recognized.
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_CaptureAndRecognizeFile(const char *imgFileNameIr, const char *imgFileNameWh, const char *imgFileNameUv, 
		                       int cardType, CardDetails *cardDetails);


	/***********************************************************
	*  Barcode
	***********************************************************/
	/*
	@brief decode image buffer(Barcode)
	@param img[in] the image buffer.
	@param w[in] the image width.
	@param h[in] the image height.
	@param bits[in] the bits of per pixel(8 or 24).
	@param barType[in] the barcode type.
	@param muti[in] false is only decode one barcode; true can decode two barcodes
	@param result[out] the barcode contents array,need malloc buffer in advance.
	@param resultSize[out] the barcode contents array size.
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_DecodeBuf(unsigned char *img, int w, int h,int bits,
								unsigned int  barType, bool muti,
								BarcodeResult *result, int *resultSize);

	/*
	@brief decode image file(Barcode)
	@param imgFileName[in] the image file name.
	@param barType[in] the barcode type.
	@param muti[in] false is only decode one barcode; true can decode two barcodes
	@param result[out] the barcode contents array,need malloc buffer in advance.
	@param resultSize[out] the barcode contents array size.
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_DecodeFile(const char *imgFileName,
								unsigned int  barType, bool muti,
								BarcodeResult *result, int *resultSize);

	/*
	@brief decode image file(Barcode)
	@param imgFileNameIr[in] is infrared image file name, will not generate if the filename is NULL.
	@param imgFileNameWh[in] is color image file name, will not generate if the filename is NULL.
	@param imgFileNameUv[in] is ultraviolet image file name, will not generate if the filename is NULL.
	@param barType[in] the barcode type.
	@param muti[in] false is only decode one barcode; true can decode two barcodes
	@param result[out] the barcode contents array,need malloc buffer in advance.
	@param resultSize[out] the barcode contents array size.
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_CaptureAndDecodeFile(const char *imgFileNameIr, const char *imgFileNameWh, const char *imgFileNameUv,
								unsigned int  barType, bool muti,
								BarcodeResult *result, int *resultSize);

	/**************************************************************
    *  use callback mode for functions
    **************************************************************/	
	/*
	@brief Open the device and initialize all resources.
	@param modules[in] is external device type.
		    1 is only A8 Capture
		    2 can support OCR
		    4 can support barcode
		    8 is china's second generation card reader
	@param hWnd[in] is the handle of a window or control, will show
		  camera preview while is not null.
    @param callback[out] the callback function.
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_OpenDeviceCB(int modules, void* hWnd, CallbackResult callback);

	/*
	@brief Close the device and release all resources.
	@param callback[out] the callback function.
	@return void
	*/
	A8CAPTURE_API int __stdcall IO_CloseDeviceCB(CallbackResult callback);

	/*
	@brief calibrate the device, should call the function while the device used on the host of the first time.
	@param callback[out] the callback function.
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_CalibrateCB(CallbackResult callback);

	/*
	@brief Capture image buffer from device. If the parameter of a certain light is empty,
		   this image is not generated.
	@param ir[out] is infrared image��need to allocate enough memory in advance.
	@param wh[out] is color image��need to allocate enough memory in advance.
	@param uv[out] is ultraviolet image��need to allocate enough memory in advance.
	@param callback[out] the callback function.
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_CaptureBufCB(unsigned char *ir, unsigned char *wh, unsigned char *uv, CallbackCaptureBuf callback);

	/*
	@brief Capture image files from device. If the parameter of a certain light is empty,
		   this image is not generated.
	@param irFileName[in] is infrared image file name, will not generate if the filename is NULL.
	@param whFileName[in] is color image file name, will not generate if the filename is NULL.
	@param uvFileName[in] is ultraviolet image file name, will not generate if the filename is NULL.
	@param callback[out] the callback function.
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_CaptureFileCB(const char *irFileName, const char *whFileName, const char *uvFileName, CallbackCaptureFile callback);

	/*
	@brief read the china second ID contents;
	@param imgFileName[in] the head portrait file path and name.
	@param cardDetails[out] the second ID contents.
	@param callback[out] the callback function.
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_ReadIDCB(const char *imgFileName, CallbackReadID callback);

	/*
	@brief capture image file and recognize(OCR).
	@param imgFileNameIr[in] is infrared image file name, will not generate if the filename is NULL.
	@param imgFileNameWh[in] is color image file name, will not generate if the filename is NULL.
	@param imgFileNameUv[in] is ultraviolet image file name, will not generate if the filename is NULL.
	@param cardType[in] the card type.
	@param cardDetails[out] the contents of recognized.
	@param callback[out] the callback function.
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_CaptureAndRecognizeFileCB(const char *imgFileNameIr, const char *imgFileNameWh, const char *imgFileNameUv,
		int cardType, CallbackCaptureAndRecognizeFile callback);

	/*
	@brief decode image file(Barcode)
	@param imgFileNameIr[in] is infrared image file name, will not generate if the filename is NULL.
	@param imgFileNameWh[in] is color image file name, will not generate if the filename is NULL.
	@param imgFileNameUv[in] is ultraviolet image file name, will not generate if the filename is NULL.
	@param barType[in] the barcode type.
	@param muti[in] false is only decode one barcode; true can decode two barcodes
	@param result[out] the barcode contents array,need malloc buffer in advance.
	@param resultSize[out] the barcode contents array size.
	@param callback[out] the callback function.
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_CaptureAndDecodeFileCB(const char *imgFileNameIr, const char *imgFileNameWh, const char *imgFileNameUv,
		unsigned int  barType, bool muti,
		CallbackCaptureAndDecodeFile callback); 

	/*
	@brief get the app data path
	@param void.
	@return app data path.
	*/
	A8CAPTURE_API char* __stdcall IO_GetAppDataPath();

	/*
	@brief get the main dll path
	@param void.
	@return main dll path.
	*/
	A8CAPTURE_API char* __stdcall IO_GetMainDllPath();

	/*
	@brief Capture and recognize E Card, such as EPassport
	@param imgFileNameIr[in] is infrared image file name, will not generate if the filename is NULL.
	@param imgFileNameWh[in] is color image file name, will not generate if the filename is NULL.
	@param imgFileNameUv[in] is ultraviolet image file name, will not generate if the filename is NULL.
	@param cardType[in] the card type.
	@param cardDetails[out] the contents of recognized.
	@param imgPortraitFileName[in] is portrait file name,will not generate if the filename is NULL.
	@return 0 is succes, else is failed.
	*/
	A8CAPTURE_API int __stdcall IO_CaptureAndRecognizeECard(const char *imgFileNameIr, const char *imgFileNameWh, const char *imgFileNameUv,
		int cardType, const char *imgPortraitFileName, CardDetails *cardDetails);

	/*
	@brief This function is used with IO_RecognizeArea, For example, it gets the position of the MRZ in the image.
	       The position get after call IO_RecognizeBuf/IO_RecognizeFile/IO_CaptureAndRecognizeFile
	@param x[out] The anchor area x coordinates
	@param y[out] The anchor area y coordinates
	@param w[out] The anchor area width
	@param h[out] The anchor area height
	@return
	*/
	A8CAPTURE_API int __stdcall IO_GetAnchor(int *x,int *y,int *w,int *h);

	/*
	@brief This function is used with IO_GetAnchor, For example, it gets the position coordinates of the machine readable code in the image.
	@param x0[in] The anchor area x coordinates(top-left), which get by IO_GetAnchor.
	@param y0[in] The anchor area y coordinates(top-left), which get by IO_GetAnchor.
	@param offx1[in] The recognize area top-left coordinates distance from The anchor area left-top coordinates
	@param offy1[in] The recognize area top-left coordinates distance from The anchor area left-top coordinates
	@param w1[in] The recognize area width
	@param h1[in] The recognize area height
	@param lan[in] 0=numbers and uppercase letters.
	               1=numbers��uppercase letters��lowercase letters;
	@param result[out] The recognized result
	@param resultLen[out] The recognized result length
	@param imgFileName[out] The recognized area image filename,if null will not create file. 
	@return
	*/
	A8CAPTURE_API int __stdcall IO_RecognizeArea(int x0, int y0,
		int offx1, int offy1, int w1, int h1,
		int lan,
		char *result, int *resultLen,
		const char *imgFileName);


	/*
	@brief sample for test
	*/
	A8CAPTURE_API int __stdcall IO_TestAPI();
}