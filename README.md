# Zynq
Initial small projects on MicroZed Zynq

1st project- Led blinking
--------------------------
XGpioPS struct is used in this program.
LookUpconfig function to get the configuration data for gpios. This data is given to CfgInitialize function to do the initial configuration of Gpios on Zynq.
Pin 47 is the led pin which is configured as an output pin. The value on this pin is toggled and a delay is inserted between the toggle so that toggling is visible to human eye. Delay of 2 sec is designed using for loop.

