Call device driver APIs based on the WebService mode

Preface

WebService mode has the following advantages when call device drivers APIs.
·It is highly compatible, friendly to programs developed based on BS architecture, and can be called by any browser.
·Low coupling, any language can be called based on its own HTTP, no longer need to focus on the language and platform of the driver itself.

Procedures

Now let's use “A8Capture.dll” as an example to describe how to implement it,“A8Capture.dll”is the device driver。


Environment

·Windows11 64bit
·VS 2017
·eclipse-win32
·jdk-8u241-windows-i586
.Tomcat 9.0


Directory

1、“A8CaptureJni” is JNI secondary packaging device driver dll file.

2、“A8CaptureNative” is the driver dll files, the "A8Capture.dll" is the mail dll.

3、“A8CaptureWebService”， Web Service sample.

4、“doc” is the document.

5、“JniSample” is the java call c++ dll sample.
