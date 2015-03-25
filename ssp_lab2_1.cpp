// Do not remove the include below
#include "ssp_lab2_1.h"

//The setup function is called once at startup of the sketch

#define REAR_LED_PIN 9
#define DUTY_CYCLE 20
#define TIME 10000

int percent = 100;

void PWM_Write(int pin, int on_time_perc){
	int on_time = (DUTY_CYCLE/100.0)*percent;
	int off_time =DUTY_CYCLE-on_time;

	digitalWrite(pin,HIGH);
	delay(on_time);

	digitalWrite(pin,LOW);
	delay(off_time);
}
void myAnalogWrite(int pin, int percent, int time){


	for(int i=0;i<time;i+=DUTY_CYCLE){
		PWM_Write(pin,percent);
	}


}

void setup()
{
// Add your initialization code here
	pinMode(REAR_LED_PIN,OUTPUT);
}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
	int time = TIME/100;

	myAnalogWrite(REAR_LED_PIN,percent,time);
	if (percent !=0) {
		percent--;
	}

}
