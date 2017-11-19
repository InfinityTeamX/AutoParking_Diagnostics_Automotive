//*****************************************************************************
//
// Watchdog Timer registers (WATCHDOG0)
//
//*****************************************************************************
#define WATCHDOG0_LOAD_R        (*((volatile unsigned long *)0x40000000))
#define WATCHDOG0_VALUE_R       (*((volatile unsigned long *)0x40000004))
#define WATCHDOG0_CTL_R         (*((volatile unsigned long *)0x40000008))
#define WATCHDOG0_ICR_R         (*((volatile unsigned long *)0x4000000C))
#define WATCHDOG0_RIS_R         (*((volatile unsigned long *)0x40000010))
#define WATCHDOG0_MIS_R         (*((volatile unsigned long *)0x40000014))
#define WATCHDOG0_TEST_R        (*((volatile unsigned long *)0x40000418))
#define WATCHDOG0_LOCK_R        (*((volatile unsigned long *)0x40000C00))
	


#define SYSCTL_RCGCWD_R         (*((volatile unsigned long *)0x400FE600))
#define WATCHDOG0_MIS_R         (*((volatile unsigned long *)0x40000014))
#define NVIC_EN0_R              (*((volatile unsigned long *)0xE000E100))
#define NVIC_PRI4_R             (*((volatile unsigned long *)0xE000E410))

//*****************************************************************************

void WDT_Init(int periode);
void WDT_Start(void);
void WDT_Stop(void);
void WDT_Reload(void);


