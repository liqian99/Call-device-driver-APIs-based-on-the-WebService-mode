#include "pch.h"
#include "com_qianlee_A8CaptureJni.h"
#include "A8CaptureDll.h"

A8CaptureDll  g_A8CaptureDll;

static char* jstring2char(JNIEnv* env, jstring jstr)
{
	int length = (env)->GetStringLength(jstr);
	if (length < 1)
		return NULL;
	const jchar* jcstr = (env)->GetStringChars(jstr, 0);
	char* rtn = new char[length * 2 + 1];
	int size = 0;
	size = WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)jcstr, length, rtn,
		(length * 2 + 1), NULL, NULL);
	if (size <= 0) {
		(env)->ReleaseStringChars(jstr, jcstr);
		delete[] rtn;
		return NULL;
	}
	(env)->ReleaseStringChars(jstr, jcstr);
	rtn[size] = 0;
	return rtn;
}


/*
 * Class:     com_qianlee_A8CaptureJni
 * Method:    IO_OpenDevice
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_qianlee_A8CaptureJni_IO_1OpenDevice
(JNIEnv *env, jobject object, jint mode) {
	return g_A8CaptureDll.openDevice(mode);
}

/*
 * Class:     com_qianlee_A8CaptureJni
 * Method:    IO_CloseDevice
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_qianlee_A8CaptureJni_IO_1CloseDevice
(JNIEnv *env, jobject object) {
	g_A8CaptureDll.closeDevice();
}

/*
 * Class:     com_qianlee_A8CaptureJni
 * Method:    IO_CaptureFileFullImage
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_qianlee_A8CaptureJni_IO_1CaptureFileFullImage
(JNIEnv *env, jobject object, jstring irFilename, jstring whFilename, jstring uvFilename) {
	char *irfilename = jstring2char(env, irFilename);
	char *whfilename = jstring2char(env, whFilename);
	char *uvfilename = jstring2char(env, uvFilename);

	int ret = g_A8CaptureDll.captureFileFullImage(irfilename, whfilename, uvfilename);

	if (irfilename)
		delete[] irfilename;
	if (whfilename)
		delete[] whfilename;
	if (uvfilename)
		delete[] uvfilename;

	return ret;
}

/*
 * Class:     com_qianlee_A8CaptureJni
 * Method:    IO_CaptureBuf
 * Signature: ([B[I[I[I[B[I[I[I[B[I[I[II)I
 */
JNIEXPORT jint JNICALL Java_com_qianlee_A8CaptureJni_IO_1CaptureBuf
(JNIEnv *env, jobject object, jbyteArray ir, jintArray irw, jintArray irh, jintArray irbits,
	jbyteArray wh, jintArray whw, jintArray whh, jintArray whbits,
	jbyteArray uv, jintArray uvw, jintArray uvh, jintArray uvbits,
	jint cardtype) {
	unsigned char *pir = NULL;
	jbyte *byteir = NULL;
	jint  *intirw = NULL;
	int *pirw = NULL;
	jint  *intirh = NULL;
	int *pirh = NULL;
	jint  *intirbits = NULL;
	int *pirbits = NULL;

	jbyte *bytewh = NULL;
	unsigned char *pwh = NULL;
	jint  *intwhw = NULL;
	int *pwhw = NULL;
	jint  *intwhh = NULL;
	int *pwhh = NULL;
	jint  *intwhbits = NULL;;
	int *pwhbits = NULL;

	jbyte *byteuv = NULL;
	unsigned char *puv = NULL;
	jint  *intuvw = NULL;
	int *puvw = NULL;
	jint  *intuvh = NULL;
	int *puvh = NULL;
	jint  *intuvbits = NULL;
	int *puvbits = NULL;

	if (ir) {
		byteir = (jbyte*)env->GetByteArrayElements(ir, 0);
		pir = (unsigned char *)byteir;
	}
	if (irw) {
		intirw = (jint*)env->GetIntArrayElements(irw, 0);
		pirw = (int *)intirw;
	}
	if (irh) {
		intirh = (jint*)env->GetIntArrayElements(irh, 0);
		pirh = (int *)intirh;
	}
	if (irbits) {
		intirbits = (jint*)env->GetIntArrayElements(irbits, 0);
		pirbits = (int *)intirbits;
	}

	if (wh) {
		bytewh = (jbyte*)env->GetByteArrayElements(wh, 0);
		pwh = (unsigned char *)bytewh;
	}
	if (whw) {
		intwhw = (jint*)env->GetIntArrayElements(whw, 0);
		pwhw = (int *)intwhw;
	}
	if (whh) {
		intwhh = (jint*)env->GetIntArrayElements(whh, 0);
		pwhh = (int *)intwhh;
	}
	if (whbits) {
		intwhbits = (jint*)env->GetIntArrayElements(whbits, 0);
		pwhbits = (int *)intwhbits;
	}

	if (uv) {
		byteuv = (jbyte*)env->GetByteArrayElements(uv, 0);
		puv = (unsigned char *)byteuv;
	}
	if (uvw) {
		intuvw = (jint*)env->GetIntArrayElements(uvw, 0);
		puvw = (int *)intuvw;
	}
	if (uvh) {
		intuvh = (jint*)env->GetIntArrayElements(uvh, 0);
		puvh = (int *)intuvh;
	}
	if (uvbits) {
		intuvbits = (jint*)env->GetIntArrayElements(uvbits, 0);
		puvbits = (int *)intuvbits;
	}

	int ret = g_A8CaptureDll.captureBuf(pir, pirw, pirh, pirbits, pwh, pwhw, pwhh, pwhbits, puv, puvw, puvh, puvbits, cardtype);

	if (byteir)
		env->ReleaseByteArrayElements(ir, byteir, 0);
	if (intirw)
		env->ReleaseIntArrayElements(irw, intirw, 0);
	if (intirh)
		env->ReleaseIntArrayElements(irh, intirh, 0);
	if (intirbits)
		env->ReleaseIntArrayElements(irbits, intirbits, 0);

	if (bytewh)
		env->ReleaseByteArrayElements(wh, bytewh, 0);
	if (intwhw)
		env->ReleaseIntArrayElements(whw, intwhw, 0);
	if (intwhh)
		env->ReleaseIntArrayElements(whh, intwhh, 0);
	if (intwhbits)
		env->ReleaseIntArrayElements(whbits, intwhbits, 0);

	if (byteuv)
		env->ReleaseByteArrayElements(uv, byteuv, 0);
	if (intuvw)
		env->ReleaseIntArrayElements(uvw, intuvw, 0);
	if (intuvh)
		env->ReleaseIntArrayElements(uvh, intuvh, 0);
	if (intuvbits)
		env->ReleaseIntArrayElements(uvbits, intuvbits, 0);

	return ret;
}

/*
 * Class:     com_qianlee_A8CaptureJni
 * Method:    IO_SaveFile
 * Signature: (Ljava/lang/String;[BIIII)I
 */
JNIEXPORT jint JNICALL Java_com_qianlee_A8CaptureJni_IO_1SaveFile
(JNIEnv *env, jobject object, jstring fileName, jbyteArray arrayImg, jint w, jint h, jint bits, jint quality) {
	char *filename = jstring2char(env, fileName);

	jbyte *byteImg = (jbyte*)env->GetByteArrayElements(arrayImg, 0);
	unsigned char *pImg = (unsigned char *)byteImg;

	int ret = g_A8CaptureDll.saveFile(filename, pImg, w, h, bits, quality);

	env->ReleaseByteArrayElements(arrayImg, byteImg, 0);
	if (filename)
		delete[] filename;

	return ret;
}