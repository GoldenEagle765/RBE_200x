#include "pico/stdlib.h"//Initialize standard pico library
#include "hardware/adc.h"//Initialize hardware ADC library
#include "hardware/gpio.h"//Initialize hardware GPIO library

int main() {
	adc_init(); //Initialize the ADC
	adc_gpio_init(26); //Intialize GPIO 26 as an ADC pin
	gpio_init(20);//Initialize GPIO 20
	gpio_set_dir(20,GPIO_OUT);//Set GPIO 20 as an output
	adc_select_input(26);//Set GPIO 26 as an ADC input
	gpio_set_pulls(20,true,false);
	float factor=3.3/(1<<12); //Create a factor to convert ADC readings to voltage
	  while(true){
		if(adc_read()*factor>0.132){//If the voltage is greated than 0.3v
		  gpio_put(20,0);//Set GPIO 20 to Logic 0
		  sleep_ms(20/((adc_read()*factor)/3.3));//Dynamic sleep based on voltage
		  gpio_put(20,1);//Set GPIO 20 to Logic 1
		  sleep_ms(20/((adc_read()*factor)/3.3));//Dynamic sleep based on voltage
		  }
		else{
		   gpio_put(20,1);//Set GPIO 20 to Logic 1
		}
		}
	
	
		
}
