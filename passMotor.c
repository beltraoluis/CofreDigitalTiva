
#include "keyboard.h"
#include "gpio.h"
#include "utils.h"
#include "passMotor.h"

void passControll(int v){
	switch(v){
		case 0:
			PortH_Output(0xC);
			break;
		case 1:
			PortH_Output(0x6);
			break;
		case 2:
			PortH_Output(0x3);
			break;
		case 3:
			PortH_Output(0x9);
			break;
		
	}
}

void pass(int passes){
	int actualPass = 0;
    if(passes > 0){
        for(int i = 0; i<passes; i++){
            actualPass++;
            if(actualPass > 3) actualPass = 0;
            passControll(actualPass);
        }
    }else if(passes < 0){
        for(int i = 0; i>passes; i--){
            actualPass--;
            if(actualPass < 1) actualPass = 4; 
            passControll(actualPass); 
        }
    }
}

void angle(int angle){
	pass((int) angle/1.8);
}
