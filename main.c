/**=============================================================================
// keyboard4x4.s
// Luís Henrique Beltrão Santana
// 25/10/2018
=============================================================================**/

#include <stdint.h>
#include "gpio.h"
#include "utils.h"
#include "keyboard.h"

#define KSM_RUN 0
#define KSM_AQUISITION 1
#define KSM_WRITE 2
#define KSM_WAINT 3
#define KSM_RESET 4

int main(void)
{
	//iniciando
	PLL_Init();
	SysTick_Init();
	uint32_t gpio = 
		GPIO_PORTC | GPIO_PORTK | GPIO_PORTL | GPIO_PORTM;
	EnableGpio(gpio);
	clearAmsel(C);
	clearAmsel(K);
	clearAmsel(L);
	clearAmsel(M);
	clearPCTL(C);
	clearPCTL(K);
	clearPCTL(L);
	clearPCTL(M);
	ioDirection(C,0x0);
	ioDirection(K,0xFF);
	ioDirection(L,P0|P1|P2|P3);
	ioDirection(M,P0|P1|P2);
	clearAfsel(C);
	clearAfsel(K);
	clearAfsel(L);
	clearAfsel(M);
	digitalEnable(C,P4|P5|P6|P7);
	digitalEnable(K,0xFF);
	digitalEnable(L,P0|P1|P2|P3);
	digitalEnable(M,P0|P1|P2);
	enablePullUp(C,P4|P5|P6|P7);
	
	char u = 'x',v = ' ';
	int i = 0;
	int ksm = 0;
	while (1)
	{
		switch(ksm){
			case KSM_RUN:
				v = kb4x4(i++);
				if(v != ' ') ksm = KSM_AQUISITION;
				if(i > 3) i = 0;
				break;
			case KSM_AQUISITION:
				u = kb4x4(i++);
				if(v == ' ') ksm = KSM_WRITE;
				if(i > 3) i = 0;
				break;
			case KSM_WRITE:
				break;
			case KSM_RESET:
				v = ' ';
				i = 0;
				ksm = KSM_RUN;
				break;
			default: break;
		}
	}
}
