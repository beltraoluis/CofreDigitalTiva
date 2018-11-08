/**=============================================================================
// keyboard4x4.s
// Luís Henrique Beltrão Santana
// 25/10/2018
=============================================================================**/

#include <stdint.h>
#include <string.h>
#include "gpio.h"
#include "utils.h"
#include "keyboard.h"
#include "passMotor.h"

#define KSM_RUN 0
#define KSM_AQUISITION 1
#define KSM_WRITE 2
#define KSM_CHECK 3
#define KSM_RESET 4
#define KSM_CLOSE 5
#define KSM_OPEN 6
#define KSM_OPENING 7
#define KSM_CLOSING 8

int main(void)
{
	char key[16] = "";
	char password[16] = "";
	int pos = 0;
	bool locked = FALSE;
	//iniciando
	PLL_Init();
	SysTick_Init();
	uint32_t gpio = 
		GPIO_PORTC | GPIO_PORTH | GPIO_PORTK | GPIO_PORTL | GPIO_PORTM;
	EnableGpio(gpio);
	clearAmsel(C);
	clearAmsel(H);
	clearAmsel(K);
	clearAmsel(L);
	clearAmsel(M);
	clearPCTL(C);
	clearPCTL(H);
	clearPCTL(K);
	clearPCTL(L);
	clearPCTL(M);
	ioDirection(C,P_NONE);
	ioDirection(H, P0|P1|P2|P3);
	ioDirection(K,P_ALL);
	ioDirection(L,P0|P1|P2|P3);
	ioDirection(M,P0|P1|P2);
	clearAfsel(C);
	clearAfsel(H);
	clearAfsel(K);
	clearAfsel(L);
	clearAfsel(M);
	digitalEnable(C,P4|P5|P6|P7);
	digitalEnable(H,P0|P1|P2|P3);
	digitalEnable(K,P_ALL);
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
				if(u == ' ') ksm = KSM_WRITE;
				if(i > 3) i = 0;
				break;
			case KSM_WRITE:
				if(v == '*'|| v == '#' || pos == 15){
					password[pos] = '\0';
					ksm = KSM_CHECK;
				}
				else{
					password[pos++] = v;
					ksm = KSM_RUN;
				}
				break;
			case KSM_CHECK:
				ksm = KSM_RESET;
				if(locked){
					if(strcmp(password,key) == 0){
						ksm = KSM_OPENING;
						strcpy(password,"");
						strcpy(key,"");
					}
				}
				else{
					if(v == '#'){
						strcpy(key,password);
						strcpy(password,"");
						ksm = KSM_CLOSING;
					}
				}
				break;
			case KSM_OPENING:
				angle(-180);
				ksm = KSM_OPEN;
				break;
			case KSM_OPEN:
				locked = FALSE;
				break;
			case KSM_CLOSING:
				angle(180);
				ksm = KSM_CLOSE;
				break;
			case KSM_CLOSE:
				locked = TRUE;
				break;
			case KSM_RESET:
				strcpy(password,"");
				pos = 0;
				v = ' ';
				u = '*';
				i = 0;
				ksm = KSM_RUN;
				break;
			default: break;
		}
	}
}
