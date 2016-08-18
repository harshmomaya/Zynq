# Zynq
Initial small projects on MicroZed Zynq

Led blinking
--------------------------------------------------------------------------------------------------------------------------------------
XGpioPS struct is used in this program.
LookUpconfig function to get the configuration data for gpios. This data is given to CfgInitialize function to do the initial configuration of Gpios on Zynq.
Pin 47 is the led pin which is configured as an output pin. The value on this pin is toggled and a delay is inserted between the toggle so that toggling is visible to human eye. Delay of 2 sec is designed using for loop.


PButton_Led
--------------------------------------------------------------------------------------------------------------------------------------
Led will glow on button press.
Pin 51 is set as output. XGpioPs_ReadPin function is used to read value from button and this value is provided to Led.


AXI Bram interface
--------------------------------------------------------------------------------------------------------------------------------------
Interfaced a bram memory with ARM cpu using AXI. Xil_io library was used to read and write data to bram.
Xil_In8(addr) - to read 8bit data from memory location who's addr is mentioned in the parenthesis. This addr is part of Bram, hence we are reading from Bram memory.
Xil_Out32(addr,data) - to write 32bit data to the memory location "addr".  

