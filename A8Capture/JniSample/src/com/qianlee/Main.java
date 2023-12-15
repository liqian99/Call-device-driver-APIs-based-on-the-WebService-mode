package com.qianlee;

public class Main {
	public static void main(String[] args){
		A8CaptureJni sample = new A8CaptureJni();
		
		int ret = sample.IO_OpenDevice(1);
		if(ret != 0) {
			System.out.println("IO_OpenDevice Failed! ret=" + ret);
			return;
		}
		System.out.println("IO_OpenDevice Sucess!");
		
		sample.IO_CaptureFileFullImage("d:/ir.jpg", "d:/wh.jpg", "");
		
		sample.IO_CloseDevice();
		
		System.out.println("IO_CloseDevice Sucess!");
	}
}
