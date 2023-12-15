package com.qianlee;

import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.QueryParam;
import javax.ws.rs.core.Response;
import org.json.JSONException;
import org.json.JSONObject;

@Path("/a8capture")
public class A8Capture {
	private final static String STATUS_KEY = "status";
	private final static int    STATUS_VAL = 200;
    private static A8CaptureJni mA8CaptureJni = null;
	
	
	/**
	 * http://localhost:8080/A8CaptureWebService/a8capture/opendevice?modules=1
	 * {"status",0}
	 * **/
	@GET
	@Path("/opendevice")
	@Produces("application/json")
	public Response openDevice(@QueryParam("modules") Integer modules) throws JSONException {		
		DLog.getInstance().I("******* <<openDevice>> start(" + modules + ") *******");	
		
		if(mA8CaptureJni == null) {
			mA8CaptureJni = new A8CaptureJni();
			mA8CaptureJni.loadLib("D:/Work/Web/WebService/A8Capture/A8CaptureNative/lib/A8CaptureJni.dll");
		}
					
        int   ret = mA8CaptureJni.IO_OpenDevice(modules.intValue());
        DLog.getInstance().I("<<openDevice>> IO_OpenDevice return : " + ret);
	           
		JSONObject jsonObject = new JSONObject();
		jsonObject.put(STATUS_KEY, ret);

		DLog.getInstance().I("******* <<openDevice>> end *******");	
		
		return Response.status(STATUS_VAL).entity(jsonObject.toString()).build();
	}
}
