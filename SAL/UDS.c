#include "UDS.h"

#define ARRAY_VARS_ID_SIZE   3
static uint8 tp_message[8];
static uint8 message_len;
static g_VarsID_t ELEMENTS[ARRAY_VARS_ID_SIZE];





/*
 *this file receive requests from tp layer for to performe tasks like read ID , write ID , Read DTC , 
 */
 
 
 
/****************************** Function Prototypes ******************************************/
//g_ServiceType_t UDS_check_requested_service(void);
 
void UDS_init(void){
  tp_Init();
}	


void UDS_Read_Request_Message(){ //Interract with TP layer
//	g_ServiceType_t Service_Type;
	tp_receiver(tp_message,&message_len);
	if(message_len!=0){
		//Service_Type=check_requested_service();  //decodes the request
		g_DiaRequest_t* RequestMessage;
		RequestMessage =(g_DiaRequest_t*)tp_message;
		if(RequestMessage->ServiceID == Read_by_ID){
			g_DiagReadIDRequest_t* ReadIDRequest;
			ReadIDRequest = (g_DiagReadIDRequest_t*)tp_message;
			UDS_Read_Value_by_ID(ReadIDRequest->ElementID);
			
		}
		else if(RequestMessage->ServiceID == Write_by_ID){
			
		}
		
		
	}
	
}

g_errorUDS_t UDS_Add_Vars_ID(g_VarsID_t Data){
	g_errorUDS_t res= PASS_UDS;
	static uint8 count=0;
	if(count == ARRAY_VARS_ID_SIZE){
	res = ID_ELEMENTS_FULL;
	}
	else{
		ELEMENTS[count]=Data;
		count ++;
	}
	
	
	return res;
	
	
}


void UDS_Write_Value_by_ID(uint16 ID_requested,uint32 value){
	uint8 ErrorFlag=1;
	for(int i=0;i< ARRAY_VARS_ID_SIZE;i++){
		if(ELEMENTS[i].ID==ID_requested){
			(*(ELEMENTS[i].Pvar))=value;
			ErrorFlag=0;
		 break;
		}
	}
	if(ErrorFlag==1){
		//send_negative_response //NRC ID not supported
	}

	
}

void UDS_Read_Value_by_ID(uint16 ID_requested){
		uint8 ErrorFlag=1;
	  uint32 value=0;
	  int i=0;
	for(int i=0;i< ARRAY_VARS_ID_SIZE;i++){
		if(ELEMENTS[i].ID==ID_requested){
			value=(*(ELEMENTS[i].Pvar));
			ErrorFlag=0;
		 break;
		}
	}
	if(ErrorFlag==1){
		//send_negative_response //NRC ID not supported
	}
	else if (ErrorFlag ==0){
		//send_value_in a frame
		tp_sender((uint8*)&value,ELEMENTS[i].varLengthInBytes );  //Beaware of Little and big endian
	  
	}
  
}



/*
g_ServiceType_t UDS_check_requested_service(void){
	g_ServiceType_t ServiceType;
	
	if(tp_message[0]==Read_by_ID){
		ServiceType=Read_by_ID;
	}
	else if(tp_message[0]==Write_by_ID){
		ServiceType=Write_by_ID;
	}
	else if(tp_message[0]==Read_DTC){
		ServiceType=Read_DTC;
	}
	
	
	return ServiceType;
}



*/
