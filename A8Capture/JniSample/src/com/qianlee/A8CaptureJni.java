package com.qianlee;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.util.StringTokenizer;

public class A8CaptureJni {
	/**
	 * We only implement these few functions, 
	 * please refer to the relevant documentation for function description
	 **/
	public native int  IO_OpenDevice(int modules);
	public native void IO_CloseDevice();
	public native int  IO_CaptureFileFullImage(String irFileName,
									           String whFileName,
									           String uvFileName);
	public native int  IO_CaptureBuf(byte[] ir,int[] irw,int[] irh,int[] irbits,
                                     byte[] wh,int[] whw, int[] whh, int[] whbits,
                                     byte[] uv,int[] uvw, int[] uvh, int[] uvbits,
                                     int cardtype);
    public native int  IO_SaveFile(String fileName,byte[] img, int w, int h, int bits,int quality);
    
    
    /**
	 * Load library
	 **/
	static {
	   System.load("D:/Work/Web/WebService/A8Capture/A8CaptureNative/lib/A8CaptureJni.dll");	
	}
	

}
