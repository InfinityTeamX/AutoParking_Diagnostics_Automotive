#include "WDT.h"

static int Periode;
void WDT_Init(int periode){volatile unsigned long delay;
Periode=periode;	
SYSCTL_RCGCWD_R |=0x01;
delay = SYSCTL_RCGCWD_R; 
WATCHDOG0_LOAD_R=Periode;	
WATCHDOG0_CTL_R|=0x02;
}

void WDT_Start(){
WATCHDOG0_CTL_R|=0x01;
WATCHDOG0_MIS_R=0x1;
NVIC_EN0_R|=0X40000;
NVIC_PRI4_R&=~0XE00000;
}


void WDT_Reload(){
WATCHDOG0_LOAD_R=Periode;
}


void WDT_Stop(){
SYSCTL_RCGCWD_R &=~0x01;


}
