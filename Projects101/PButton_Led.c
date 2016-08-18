// PButton_Led.c
// v1.0 - Led glows when button is pressed
// Company: Tau Science
// Developer: Harsh Momaya
// Platform: MicroZed Zynq FPGA

// Include header files
#include <stdio.h>
#include "platform.h"
#include "xgpiops.h"
#include "xparameters.h"

// external variables and functions

// #define(s)

// Global variables and constants

// Prototype of private functions

// Main function
int main() {

	// Local variables, pointers and objects
	int Status;
	XGpioPs my_gpio;				//my_gpio is object to class XGpioPs
	XGpioPs_Config *gpio_config;    // This pointer transfers the configuration data from LookUp to ConfigInit function
	int Value;

	// These 2 vars are declared as consts because these are locations of LED and Push Buttons on uZed which are fixed
	const int LED = 47;
	const int PButton = 51;

	init_platform();

	//LookUP function just requires the device id which is available from xparameters.
	// It returns the config data which is assigned to gpio_config pointer.
	gpio_config = XGpioPs_LookupConfig(XPAR_PS7_GPIO_0_DEVICE_ID);

	// Data from this pointer will be given to ConfigInit
	Status = XGpioPs_CfgInitialize(&my_gpio, gpio_config, gpio_config -> BaseAddr);

	//Configuring the LED with 3 functions:
	//SetDirection(XGpioPs *InstancePtr, int pin, int Direction)
	//SetOutputEnable(XGpioPs *InstancePtr, u32 Pin, u32 OpEnable)
	//WritePin(XGpioPs *InstancePtr, int pin, int Data)

	XGpioPs_SetDirectionPin(&my_gpio, LED, 1);
	XGpioPs_SetOutputEnablePin(&my_gpio, LED, 1);

	XGpioPs_SetDirectionPin(&my_gpio, PButton, 1);

	while(1){
		Value = XGpioPs_ReadPin(&my_gpio,PButton);
		XGpioPs_WritePin(&my_gpio, LED, Value);
	}

	cleanup_platform();
	return 0;
}
