/*
// helloworld.c
// Writing an embedded C program for the 1st time.
// v1.0 - This is a simple blinking LED program.
// Company: Tau Science
// Developer: Harsh Momaya
// Platform: MicroZed Zynq FPGA
// Purpose: To understand struct and how to use them to develop applications

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xparameters.h"
#include "xgpiops.h"

// external variables and functions

// #define(s)

// Global variables and constants

// Prototype of private functions

int main()
{
    // Local variables, pointers and objects
	int Status;
	XGpioPs my_gpio;				//my_gpio is object to class XGpioPs
	XGpioPs_Config *gpio_config;    // This pointer transfers the configuration data from LookUp to ConfigInit function

	// These 2 vars are declared as consts because these are locations of LED and Push Buttons on uZed which are fixed
	const int LED = 47;
	//const int PButton = 51;

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
	XGpioPs_WritePin(&my_gpio, LED, 1);

	cleanup_platform();
	return 0;
}
*/


// main.c
// version 2 of blinking led project.
// In v1 we just lit the led. In this version, we are gonna flash the led.
// Company: Tau Science
// Developer: Harsh Momaya
// Platform: MicroZed Zynq FPGA SoC
//	Date: 08/15/2016
///////////////////////////////////////////////////////////////////////////////

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
	int data = 0;
	int delay;
	XGpioPs_Config *Gpio_Config;    // This pointer transfers the configuration data from LookUp to ConfigInit function
	XGpioPs my_gpio;				//my_gpio is object to class XGpioPs

	// These 2 vars are declared as consts because these are locations of LED and Push Buttons on uZed which are fixed
	const int LED = 47;
	//const int PButton = 51;

	init_platform();

	//LookUP function just requires the device id which is available from xparameters.
	// It returns the config data which is assigned to gpio_config pointer.
	printf ("It's Working!\n");
	Gpio_Config = XGpioPs_LookupConfig(XPAR_PS7_GPIO_0_DEVICE_ID);

	// Data from this pointer will be given to ConfigInit
	Status = XGpioPs_CfgInitialize(&my_gpio, Gpio_Config, Gpio_Config -> BaseAddr);

	//Configuring the LED with 3 functions:
	//SetDirection(XGpioPs *InstancePtr, int pin, int Direction)
	//SetOutputEnable(XGpioPs *InstancePtr, u32 Pin, u32 OpEnable)
	//WritePin(XGpioPs *InstancePtr, int pin, int Data)

	XGpioPs_SetDirectionPin(&my_gpio, LED, 1);
	XGpioPs_SetOutputEnablePin(&my_gpio, LED, 1);

	int count;
	for(count = 0; count<500;count++){

		//This technique is better as compared to the 2nd one.
//		XGpioPs_WritePin(&my_gpio, LED, 1);
//			for(delay=0; delay<500; delay++)			//5s
//			{
//				printf("Delay value is: %d ", delay);
//			}
//
//		XGpioPs_WritePin(&my_gpio, LED, 0);
//			for(delay=0; delay<500; delay++)			//5s
//			{
//				printf("Delay value is: %d ", delay);
//			}

		//2nd technique
		XGpioPs_WritePin(&my_gpio, LED, data);
			for(delay=0; delay<2000; delay++)			//5s
			{
				printf(".");
			}
			data = ~data;
	}


	cleanup_platform();
	return 0;
}
