package com.qianlee;

import java.util.logging.ConsoleHandler;
import java.util.logging.Level;
import java.util.logging.Logger;

public class DLog {
	 private Logger mLog = null;
	    private static DLog mInstance = null;
		
		private void init() {
			try {
				mLog = Logger.getLogger("lavasoft"); 
				mLog.setLevel(Level.INFO); 
			   
			    //Control
			    ConsoleHandler consoleHandler =new ConsoleHandler(); 
			    consoleHandler.setLevel(Level.INFO); 
			    mLog.addHandler(consoleHandler); 
			    
		        //File
//			    FileHandler fileHandler;	
//				fileHandler = new FileHandler("D:/A8CaptureWebService.log");
//				fileHandler.setLevel(Level.INFO); 
//				mLog.addHandler(fileHandler); 
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} 
	 
		}
		
		public static DLog getInstance(){
			if(mInstance==null) {
				mInstance = new DLog();
				mInstance.init();
			}
			
			return mInstance;
		} 
		
		public void I(String msg) {
			if(mLog!=null)
				mLog.info(msg);
		}
}
