//AXI GPIO driver
#include "xgpio.h"

//send data over UART
#include "xil_printf.h"

//information about AXI peripherals
#include "xparameters.h"

void change_state(u32 params)
{
	if(params == 1)
		xil_printf("\r Boton 0 presionado);
		return;	
	if(params == 2)
		xil_printf("\r Boton 1 presionado);
		return;
	if(params == 4)
		xil_printf("\r Boton 2 presionado);
		return;
	if(params == 8)
		xil_printf("\r Boton 3 presionado);
		return;
	xil_printf("\r 0 o mas botones siendo presionados, valor: %08x", btn);
	return;
}

int main()
{
	XGpio gpio;
	u32 btn, ss;
	
	XGpio_Initialize(&gpio, 0);

	XGpio_SetDataDirection(&gpio, 1, 0xFFFFFFFF); // set BTN GPIO channel tristates to All Input
	ss = 0
	while (1)
	{
		btn = XGpio_DiscreteRead(&gpio, 1);
		
		if (btn != ss) // turn all LEDs on when any button is pressed
			ss = btn;
			change_state(btn);
		else
			led = 0x00000000;

	}
}