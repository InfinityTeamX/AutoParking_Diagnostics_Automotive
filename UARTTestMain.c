
//Elghzaly

#include <stdint.h>
//#include "CPX/PLL/PLL.h"
#include "CPX/UART/UART.h"
#include "SAL/UDS.h"
#include "os/os.h"
#include "SAL/tp_transiver.h"
//Test
#include "SAL/stack.h"
//Interactive Task with TP layer
int count0,count1,count2,count3,count4,count5,count6;
#define THREADFREQ 1000


uint32 SearchDTC_ID(uint32 Stack_Value);
g_stack_t DTC_Stack;
void Task0(){

			while(1){
				 count0++;
					/*							
				 tp_receiver(DataMain,&DataLen);
				 count0++;
				 if(DataLen !=0){
				 UART_OutStringLen((char*)DataMain,DataLen);
				 }	
				*/
				
				UDS_Handle_Request_Message();
	     }
}

//Idle Task
void Task1(){
	while(1){
		//tp_sender("ROUND 7 Test X", 15);
		count1++;
		
	}
}

void Task2(){
	while(1){
		count2++;
	}
}

void Task3(){
	while(1){
		count3++;
	}
}

void Task4(){
	while(1){
		count4++;
	}
}

void Task5(){
	while(1){
		count5++;
	}
}

void Task6(){
	while(1){
		count6++;
	}
}

/*
//---------------------OutCRLF---------------------
// Output a CR,LF to UART to go to a new line
// Input: none
// Output: none
void static OutCRLF(void){
  UART_OutChar(CR);
  UART_OutChar(LF);
}
*/
//debug code
 char ch;
int main(void){
   uint32 SteeringAngle =0x12345678 ,RaderY=0x76859432;
   uint32 RaderX=0x76894537;
   
	
	OS_Init();
	
	CreateStack(&DTC_Stack);
	Push(&DTC_Stack,0x05020301); //DTC_ID =0x05020300 //DTC_Status=0x01 =>Active not confirmed
	Push(&DTC_Stack,0x5322F309); //DTC_ID =0x5322F300 //DTC_Status=0x09 (1001) =>Active & confirmed
	Push(&DTC_Stack,0x12345608); //DTC_ID =0x12345600 //DTC_Status=0x08 =>confirmed & not active
  UDS_init();
	


	
	
	
	g_VarsID_t Dummy;
  Dummy.ID= 0x5151;
	Dummy.Pvar =&SteeringAngle;
	Dummy.varLengthInBytes=4;
	UDS_Add_Vars_ID(Dummy);
	Dummy.ID= 0xD001;
	Dummy.Pvar =&RaderX;
	Dummy.varLengthInBytes=4;
	UDS_Add_Vars_ID(Dummy);
	Dummy.ID= 0xD002;
	Dummy.Pvar =&RaderY;
	Dummy.varLengthInBytes=4;
	UDS_Add_Vars_ID(Dummy);	
	
  OS_AddThreads(&Task0,0,&Task1,0,&Task2,0,&Task3,0,&Task4,0,&Task5,0,&Task6,0);
		

	OS_Launch(OS_Clock_GetFreq()/THREADFREQ); // doesn't return, interrupts enabled in here
	while(1){
  // tp_sender("Mohab Adel bla",15);
		

	}
}




