/**=============================================================================
// keyboard4x4.s
// Lu�s Henrique Beltr�o Santana
// 30/10/2018
=============================================================================**/

#include "keyboard.h"
#include "gpio.h"
#include "utils.h"

const uint32_t val[4] = {0x7, 0xB, 0xD, 0xE};

char kb4x4(int ki){
	char c = ' ';
	uint32_t v1, v2;
	PortL_Output(val[ki]);
	v1 = PortC_Input() >> 4;
	SysTick_Wait1ms(300);
	v2 = PortC_Input() >> 4;
	v2 &= 0xF;
	if(v1 == v2){
		switch(val[ki]){
			case 0x7: 	
				switch(v2){
					case 0x7: c = '1'; break;
					case 0xB: c = '4'; break;
					case 0xD: c = '7'; break;
					case 0xE: c = '*'; break;
					default: break;
				}
				break;
			case 0xB: 	
				switch(v2){
					case 0x7: c = '2'; break;
					case 0xB: c = '5'; break;
					case 0xD: c = '8'; break;
					case 0xE: c = '0'; break;
					default: break;
				}
				break;
			case 0xD: 	
				switch(v2){
					case 0x7: c = '3'; break;
					case 0xB: c = '6'; break;
					case 0xD: c = '9'; break;
					case 0xE: c = '#'; break;
					default: break;
				}
				break;
			case 0xE: 	
				switch(v2){
					case 0x7: c = 'A'; break;
					case 0xB: c = 'B'; break;
					case 0xD: c = 'C'; break;
					case 0xE: c = 'D'; break;
					default: break;
				}
				break;
		}
	}
	return c;

}
