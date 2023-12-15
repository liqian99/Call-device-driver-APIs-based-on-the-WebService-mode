#pragma once


//the device support modules
#define SUPPORT_DEFAULT                  1    // only support capture image
#define SUPPORT_OCR                      2    // support ocr
#define SUPPORT_BARCODE                  4    // support barcode decode
#define SUPPORT_CHINA_SECOND_READER      8    // support china id and residence reader 
#define SUPPORT_ECARD_READER             16   // support e card, such as epassport 

//return value
#define A8C_SUCC                      0         //success
#define A8C_OFFLINE                   -100       //device offline
#define A8C_OPEN_FAILURE              -101       //device open fail
#define A8C_FILEREAD_ERR              -102       //read file error
#define A8C_FILEWRITE_ERR             -103       //write file error
#define A8C_LOAD3RDDLL_ERR            -104       //load 3rd dll error
#define A8C_LOAD3RDFUNCTIONS_ERR      -105       //load 3rd funcitons error
#define A8C_WRITE_REGISTER_ERR        -106       //write register error
#define A8C_READ_REGISTER_ERR         -107       //read register error
#define A8C_ASICINIT_ERR              -108       //init asic error
#define A8C_CALIB_NOTFIND_RETANGLE    -109       //not find black retangle wile calibrating
#define A8C_CALIB_WRITEDATA_ERR       -110       //write calibrate data error
#define A8C_CALIB_READDATA_ERR        -111       //read calibrate data error,may had not cablirated
#define A8C_CALIB_FAILURE             -112       //calibrate fail
#define A8C_IMG_FORMAT_ERR            -113       //image format error
#define A8C_OPEN_IDREADER_ERR         -114       //open ID reader error
#define A8C_AUTHENTICATE_ERR          -115       //ID authenticate error
#define A8C_IDREADER_READ_ERR         -116       //read ID contents error
#define A8C_NOT_SUPPORT               -117       //not support functions
#define A8C_PARAMETERS_ERR            -118       //parameters error
#define A8C_DEVICE_BUSYING            -119       //device is busying
#define A8C_OCR_INIT_FAILURE          -120       //OCR init failure
#define A8C_OCR_PARAS_ERR             -121       //OCR parameters error
#define A8C_OCR_NOTGETROI             -122       //OCR not decteced ROI
#define A8C_OCR_FAILURE               -123       //OCR fail
#define A8C_OCR_NOTSUPPORT_CARDTYPE   -124       //not support card type
#define A8C_BARCODE_NOT_DETECTED      -125       //no barcode be detected
#define A8C_BARCODE_ILLEGAL_ARGUMENT  -126       //illegal argument while decode barcode
#define A8C_BARCODE_DECODE_FAILED     -127       //barcode decode failed
#define A8C_BARCODE_RESULT_FAILED     -128       //barcode decode result verifiy failed
#define A8C_NO_AUTHORIZATION          -129       //no authorization,please connect the vendor
#define A8C_GET_PATH_FAILURE          -130       //get app data path fail
#define A8C_CURL_INIT_ERR             -131       //curl init error
#define A8C_CURL_GET_TIMEOUT          -132       //curl get timeout
#define A8C_CURL_DATA_ERR             -133       //received data analyze error
#define A8C_TOMCAT_FILE_NOTFIND       -134       //not find tomcat file
#define A8C_TOMCAT_STARTUP_FAILURE    -135       //tomcat startup fail   
#define A8C_TOMCAT_STARTUP_ABOUT      -136       //tomcat startup abouted
#define A8C_FLASH_GET_TYPE_ERR        -137       //get flash type error
#define A8C_FLASH_WRITE_ERR           -138       //write flash error
#define A8C_FLASH_READ_ERR            -139       //read flash error
#define A8C_NOTFIND_HOTAREA           -140       //the specified area was not found

  
//max camera capture image size
#define MAX_IMG_WIDTH         3840    //max image width
#define MAX_IMG_HEIGHT        2160    //max image height

//Led light
#define LED_LIGHT_ALL_OFF    0
#define LED_LIGHT_GREEN_ON   1
#define LED_LIGHT_RED_ON     2
#define LED_LIGHT_ALL_ON     3

//camera sensor light
#define SENSOR_LIGHT_OFF  0
#define SENSOR_LIGHT_IR   1    
#define SENSOR_LIGHT_WH   2
#define SENSOR_LIGHT_UV   3

//card status
#define CARD_STATUS_UNKNOW    0   //dont check card status right
#define CARD_STATUS_OFF       1   //check card not on device
#define CARD_STATUS_ON        2   //check card on device

//card types
#define CARD_TYPE_UNKNOWN                  0  //unknown card type or the full image
#define CARD_TYPE_CHINESE_ID               1  //中国二代证               China second generation certificate    
#define CARD_TYPE_HMT_RESIDENCE            2  //港澳台居住证             Hong Kong, Macao and Taiwan residence permit
#define CARD_TYPE_FOREIGNER_RESIDENCE      3  //外国人居住证             Foreigner Residence Permit
#define CARD_TYPE_HKM_RETURNCARD           4  //港澳人员返乡证           Return Permit for Hong Kong and Macau Residents
#define CARD_TYPE_TAIWAN_RETURNCARD        5  //台湾人员返乡证           Taiwanese Return Home Permit
#define CARD_TYPE_HKM_PERMITCARD           6  //大陆人去港澳通行证       Hong Kong and Macau Pass
#define CARD_TYPE_INTERNATIONAL_ID         7  //国际带三行机读码的证件   Document with three-line machine readable code
#define CARD_TYPE_CN_PASSPORT              8  //中国护照                 Chinese passport
#define CARD_TYPE_IN_PASSPORT              9  //国际护照、其它国家护照   Passports of other countries
#define CARD_TYPE_BARCODE                  10 //只识读条型码             Barcode read only 
#define CARD_TYPE_HK_ID                    11 //香港身份证               Hong Kong Identity Card



//the card details
typedef struct __CardDetails {
	char cnName[32];            // 中文姓名              Chinese name
	char cnSurname[32];         // 中文姓                Chinese surname
	char cnGivenname[32];       // 中文名                Chinese first name
	char enName[120];           // 英文姓名              English name
	char enSurname[120];        // 英文姓                English surname
	char enGivenname[120];      // 英文名                English first name
	char cnGender[4];           // 中文性别              Chinese gender 
	char enGender[4];           // 英文性别              English gender
	char nation[22];            // 民族、国籍、地区代码  Nation 
	char dateOfBirth[22];       // 出生日期              Date of birth 
	char address[72];           // 住址                  Address 
	char identityNumber[36];    // 身份证号码            Identify number
	char cardNumber[36];        // 证件号码              Card number
	char cnAuthority[32];       // 中文签发机关          Chinese authority
	char enAuthority[64];       // 英文签发机关          English authority
	char dateOfIssue[22];       // 有效期起始日期        Date of issue
	char dateOfExpiry[22];      // 有效期结束日期        Date of expiry
	char dateOfDepart[22];      // 最晚离开日期          Date of depart 
	char timesOfIssue[16];      // 签发次数              Times of issue
	char types[36];             // 证件类型              type
	char cnPlaceOfBirth[36];    // 中文出生地点          Chinese place of birth
	char enPlaceOfBirth[72];    // 英文出生地点          English place of birth
	char cnPlaceOfIssue[36];    // 中文签发地点          Chinese place of issue
	char enPlaceOfIssue[72];    // 英文签发地点          English place of issue
	char career[32];            // 职业                  Career
	char cardVersion[6];        // 证件版本号            Card version
	char firstMRZ[46];          // 第一行机读码          First MRZ 
	char secondMRZ[46];         // 第二行机读码          Second MRZ
	char thirdMRZ[46];          // 第三行机读码          Third MRZ
	unsigned char image[1024];  // 头像                  Image
	unsigned char finger[1024]; // 指纹（如果有）        Fingerprint
}CardDetails;

//decode barcode result
typedef struct __BarcodeResult {
	char data[4096];
	int  dataLen;
	int  type;
	int  x;
	int  y;
	int  w;
	int  h;
}BarcodeResult;

//barcode type
#define  BARCODE_AZTEC                 (1<<1)
#define  BARCODE_CODABAR               (1<<2)
#define  BARCODE_CODE_39               (1<<3)
#define  BARCODE_CODE_93               (1<<4)
#define  BARCODE_CODE_128              (1<<5)   
#define  BARCODE_DATA_MATRIX           (1<<6)
#define  BARCODE_EAN_8                 (1<<7)
#define  BARCODE_EAN_13                (1<<8)
#define  BARCODE_ITF                   (1<<9)
#define  BARCODE_MAXICODE              (1<<10)
#define  BARCODE_PDF_417               (1<<11)
#define  BARCODE_QR_CODE               (1<<12)
#define  BARCODE_RSS_14                (1<<13)
#define  BARCODE_RSS_EXPANDED          (1<<14) 
#define  BARCODE_UPC_A                 (1<<15)
#define  BARCODE_UPC_E                 (1<<16)
#define  BARCODE_UPC_EAN_EXTENSION     (1<<17) 

/******************************************************
* the callback functions
******************************************************/
/*
* the callback function of only return value.
*/
typedef void (CALLBACK *CallbackResult)(int result);

/*
* the callback function of IO_CaptureBufCB.
* the parameters please refer to IO_CaptureBuf
*/
typedef void (CALLBACK *CallbackCaptureBuf)(int result
	, unsigned char *ir, int irw, int irh, int irbits
	, unsigned char *wh, int whw, int whh, int whbits
	, unsigned char *uv, int uvw, int uvh, int uvbits);

/*
* the callback function of IO_CaptureFileCB.
* the parameters please refer to IO_CaptureFile
*/
typedef void (CALLBACK *CallbackCaptureFile)(int result
	, char *irFileName
	, char *whFileName
	, char *uvFileName);

/*
* the callback function of IO_ReadIDCB.
* the parameters please refer to IO_ReadID
*/
typedef void (CALLBACK *CallbackReadID)(int result
	, char *imgFileName, CardDetails *cardDetails);

/*
* the callback function of IO_CaptureAndRecognizeFileCB.
* the parameters please refer to IO_CaptureAndRecognizeFile
*/
typedef void (CALLBACK *CallbackCaptureAndRecognizeFile)(int result
	, char *irFileName
	, char *whFileName
	, char *uvFileName
	, int cardType
	, CardDetails *cardDetails);

/*
* the callback function of IO_CaptureAndDecodeFileCB.
* the parameters please refer to IO_CaptureAndDecodeFile
*/
typedef void (CALLBACK *CallbackCaptureAndDecodeFile)(int result
	, char *irFileName
	, char *whFileName
	, char *uvFileName
	, unsigned int barType
	, bool muti
	, BarcodeResult *barcodeResult
	, int barcodeResultSize);