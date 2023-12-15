package com.qianlee;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;

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
	 * @ref    Load library
	 * @param  libPath: it is to specify the directory
	 * **/
	public void loadLib(String libPath) {	
		System.out.println("<<A8CaptureJni>> libPath=" + libPath);
		try {				
			InputStream inputStream = A8CaptureJni.class.getResourceAsStream(libPath);
			final File dllFile = new File(libPath);
			if (!dllFile.exists()) {
				FileOutputStream outputStream = new FileOutputStream(dllFile);
				byte[] array = new byte[1024];
				int bytesRead = -1;
				while ((bytesRead = inputStream.read(array)) != -1) {
					outputStream.write(array, 0, bytesRead);
				}
				outputStream.flush();
				outputStream.close();
			}
			System.load(dllFile.getPath());
		} catch (Throwable e) {
			throw new RuntimeException("<<A8CaptureJni>> Load dll error,please check the dll in the right path!", e);		
		}
   }
}
