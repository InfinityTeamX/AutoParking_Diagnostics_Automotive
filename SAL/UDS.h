







#ifndef UDS_H_
#define UDS_H_

#include "tp_transiver.h"
typedef enum ServiceID{
	Session_Control=0x10,
	Tester_Present = 0x3E,
	ECU_Reset = 0x11,
	Comm_Control = 0x28,
	Read_by_ID =0x22,
	Write_by_ID = 0x2E,
	Routine_Control = 0x31,
	
	Read_DTC =0x19,
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
	EXTENDED_SESSION=0x03
}g_SubFunction_t;


typedef struct DiagRequest{
g_ServiceType_t ServiceID;
g_SubFunction_t SubFunctionID; 	
}g_DiaRequest_t;

typedef struct DiagPosRes{
	uint8 ServiceID; 
	uint8 Data[7];
}g_DiagPosRes_t;

typedef struct DiagNegRes{
	uint8 NegativeID;
	uint8 ServiceID;
	uint8 NRC;
	uint8 RemByte[5];
}g_DiagNegRes_t;



typedef struct DiagReadIDRequest{

	uint8 ServiceID;
	uint8 ElementID;
	uint8 RemaBytes[6];
}g_DiagReadIDRequest_t;


typedef struct VARS_ID{
	uint16 ID;
	uint32* Pvar;
	uint16 varLengthInBytes;
}g_VarsID_t;

typedef enum ERROR_UDS{
	PASS_UDS , FAIL , ID_ELEMENTS_FULL
	
}g_errorUDS_t;
void UDS_init(void);
g_errorUDS_t UDS_Add_Vars_ID(g_VarsID_t Data);
void UDS_Write_Value_by_ID(uint16 ID_requested,uint32 value);
void UDS_Read_Value_by_ID(uint16 ID_requested);
#endif
