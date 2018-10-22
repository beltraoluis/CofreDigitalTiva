
#ifndef __GPIO__
#define __GPIO__

#define A (0x1)
#define B (0x2)
#define C (0x3)
#define D (0x4)
#define E (0x5)
#define F (0x6)
#define G (0x7)
#define H (0x8)
#define J (0x9)
#define K (0xA)
#define L (0xB)
#define M (0xC)
#define N (0xD)
#define P (0xE)
#define Q (0xF)

#define GPIO_PORTA (0x0001)
#define GPIO_PORTB (0x0002)
#define GPIO_PORTC (0x0004)
#define GPIO_PORTD (0x0008)
#define GPIO_PORTE (0x0010)
#define GPIO_PORTF (0x0020)
#define GPIO_PORTG (0x0040)
#define GPIO_PORTH (0x0080)
#define GPIO_PORTJ (0x0100)
#define GPIO_PORTK (0x0200)
#define GPIO_PORTL (0x0400)
#define GPIO_PORTM (0x0800)
#define GPIO_PORTN (0x1000)
#define GPIO_PORTP (0x2000)
#define GPIO_PORTQ (0x4000)

/**
  *  1. Ativar o clock para a(s) porta(s) necessária(s)
 **/
void SYSCTL_RCGCGPIO(void);

/**
  *  2. Ativar o clock para a(s) porta(s) necessária(s)
 **/
void GPIO_Init(void);
#endif
