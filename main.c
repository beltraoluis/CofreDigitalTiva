/**=============================================================================
// keyboard4x4.s
// Luís Henrique Beltrão Santana
// 25/10/2018
=============================================================================**/

#include <stdint.h>
#include "gpio.h"
#include "utils.h"

int main(void)
{
	//iniciando
	PLL_Init();
	SysTick_Init();
	//iniciando GPIO
	uint32_t gpio = GPIO_PORTJ;
	
	void setRcgcgpio(gpio);
	while (1)
	{
        //Se a USR_SW2 estiver pressionada
		if (PortJ_Input() == 0x1)
			PortN_Output(0x1);
        //Se a USR_SW1 estiver pressionada
		else if (PortJ_Input() == 0x2)
			PortN_Output(0x2);
        //Se ambas estiverem pressionadas
		else if (PortJ_Input() == 0x0)
			PortN_Output(0x3);
        //Se nenhuma estiver pressionada
		else if (PortJ_Input() == 0x3)
			PortN_Output(0x0);        
	}
}
