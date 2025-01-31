#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/gpio.h"

int main() {
	adc_init();
	adc_gpio_init(26);
	gpio_init(0);
	gpio_set_dir(0,GPIO_IN);
	gpio_init(20);
	gpio_set_dir(20,GPIO_OUT);
	adc_select_input(0);
	gpio_pull_down(0);
	float factor=3.3/(1<<12);
	
	  while(true){
	      if(gpio_get(0)==1){
		if(adc_read()*factor>0.3){
		  gpio_put(20,0);
		  sleep_ms(20/((adc_read()*factor)/3.3));
		  gpio_put(20,1);
		  sleep_ms(20/((adc_read()*factor)/3.3));
		  }
		else{
		   gpio_put(20,1);
		}
		}
		else{
		  gpio_put(20,1);
		}
		}
	
	
		
}
