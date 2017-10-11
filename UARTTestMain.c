
#include <stdint.h>
//#include "CPX/PLL/PLL.h"
#include "CPX/UART/UART.h"
#include "SAL/tp_transiver.h"
#include "os/os.h"
//Interactive Task with TP layer
int count0,count1,count2,count3,count4,count5,count6;
#define THREADFREQ 1000
uint8 DataMain[40];
uint8 DataLen;

void Task0(){
// ??????
			while(1){
				// tp_sender("ROUND 7 Test X", 15);
				
				 tp_receiver(DataMain,&DataLen);
				 count0++;
				 if(DataLen !=0){
				 UART_OutStringLen((char*)DataMain,DataLen);
			   }	
	     }
}

//Idle Task
void Task1(){
	while(1){
	//	tp_sender("ROUND 7 Test X", 15);
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
 

	OS_Init();
  OS_AddThreads(&Task0,0,&Task1,0,&Task2,0,&Task3,0,&Task4,0,&Task5,0,&Task6,0);
	tp_Init();
	OS_Launch(OS_Clock_GetFreq()/THREADFREQ); // doesn't return, interrupts enabled in here
	while(1){
  // tp_sender("Mohab Adel bla",15);
		

	}
}




