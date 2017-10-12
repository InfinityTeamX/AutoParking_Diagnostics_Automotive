







#ifndef UDS_H_
#define UDS_H_

#include "tp_transiver.h"
#include "stack.h"
#include "../os/os.h"
//all frames here are 7 bytes only
typedef enum ServiceID{
	Session_Control=0x10,
	Tester_Present = 0x3E,
	ECU_Reset = 0x11,
	Comm_Control = 0x28,
	Read_by_ID =0x22,
	Write_by_ID = 0x2E,
	Routine_Control = 0x31,
	
	Read_DTC_INFO =0x19,
	Clear_DTC = 0x14,
	Control_DTC = 0x85,
	
	DOWNLOAD =0x34,
	TRANSFER =0x36,
	EXIT =0x37
	
}g_ServiceType_t;


typedef enum sub_function{
	HARD_RESET=0x01,
	ON_KEY=0x02,
	SW_RESET=0x03,
	R_DTC_NUMS_BY_SM=0x01,
	R_DTC_IDS_BY_SM=0x02,
	R_SNAP_SHOOT_DATA=0x04,
	R_EXTENDED_DATA_RECORD=0x06,
	R_SUPPORTED_DTC=0x0A,
	DEFAULT_SESSION=0x01,
	PROGRAMMING_SESSION=0x02,
	EXTENDED_SESSION=0x03,
	/*DTC subfunctions*/
	REPORT_DTC_NUM_BY_SM =0x01,
	REPORT_DTC_ID_BY_SM=0x02,
	REPORT_DTC_SNAPSHOT_RECORDS_BY_DTC_ID=0x04,
	REPORT_DTC_RECORDS_BY_DTC_ID= 0x06,
	REPORT_DTC_SUPPORTED=0x0A
	
}g_SubFunction_t;

typedef enum NRC{
	GR=0x10,  //general reject
	SNS=0x11, //Service not supported
	SFNS=0x12, //sub_function not supported
	IMLOIF=0x13,  //incorrect message length or invalid format
	RTL=0x14,  //Response too long
	BRR=0x21,  //Busy repeat request
	CNC=0x22,  //conditions not correct
	RSE=0x24,  //Request sequence error
	NRFSC=0x25, //NO response drom sun-net component
	FPEORA=0x26, //Failure prevents execution of requested action
	ROOR=0x31, //Request out of range
	SAD=0x33, //security access denied 
	IK=0x35,  //Invaild key
	ENOA=0x36, //Exceeded number of attempts
	RTDNE=0x37, //Required time delay not expired
	UDNA=0x70,  //upload/Download not accepted
	TDS=0x71,  //Transfer data suspended
	GPF=0x72, //General programming failure
	WBSC=0x73, //Wrond Block sequence Counter
	RCRRP=0x78, //Request correctly received,but response is pending
	SFNSIAS=0x7E,//sub_function not supported in active session
	SNSIAS=0x7F //Service not supported in active session
}g_NRC_t;


typedef struct DiagRequest{
	uint8 ServiceID;
	uint8 SubFunctionID;
	uint8 RemBytes[5]; 	
}g_DiaRequest_t;

typedef struct DiagPosRes{
	uint8 ServiceID; //ServiceID+0x40
    uint8 sub_function; 	
	uint8 Data[5];
}g_DiagPosRes_t;

typedef struct DiagNegRes{
	uint8 NegativeID;
	uint8 ServiceID;
	uint8 NRC;
	uint8 RemByte[4];
}g_DiagNegRes_t;

typedef struct GDiagNegRes{
	uint8 NegativeID;
	uint8 NRC;
	uint8 RemByte[5];
}g_General_DiagNegRes_t;


/*
typedef struct DiagReadIDRequest{

	uint8 ServiceID;
	uint16 ElementID;
	uint8 RemaBytes[4];
}g_DiagReadIDRequest_t; //7 byte
*/

typedef struct DiagReadIDRequest{

	uint8 ServiceID;
	uint8 ElementID_HighByte;
	uint8 ElementID_LowByte;
	uint8 RemaBytes[4];
}g_DiagReadIDRequest_t;

typedef struct DiagPosReadIDRes{
	uint8 ServiceID;
	uint8 ElementID_HighByte;
	uint8 ElementID_LowByte;
	uint8 Data[4];
}g_DiagPosReadIDRes_t;



typedef struct DiagPosWriteIDRes{
	uint8 ServiceID;
	uint8 ElementID_HighByte;
	uint8 ElementID_LowByte;
	uint8 Data[4];
}g_DiagPosWriteIDRes_t;

typedef struct DiagWriteIDRequest{
	uint8 ServiceID;
	uint8 ElementID_HighByte;
	uint8 ElementID_LowByte;
	uint8 Data[4];
}g_DiagWriteIDRequest_t;





typedef struct DiagReadDTCbySM{
	uint8 ServiceID;
	uint8 SubFunctionID;
	uint8 StatusMask;
	uint8 RemBytes[4]; 
	
}g_DiagReadDTCbySM_t;

typedef struct VARS_ID{
	uint16 ID;
	uint32* Pvar;
	uint16 varLengthInBytes;
}g_VarsID_t;

typedef enum ERROR_UDS{
	PASS_UDS , FAIL , ID_ELEMENTS_FULL, ID_Not_Found
	
}g_errorUDS_t;
void UDS_init(void);
g_errorUDS_t UDS_Add_Vars_ID(g_VarsID_t Data);
void UDS_Handle_Request_Message(void);

#endif
