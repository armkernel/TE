/*
	name : armkernel
	date : 20190411
	desciprot : today i learn pwm rgb led  
 */


#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#include <stdlib.h>

// red : 23, green 26, blue 22
#define RGB_LED1 26
#define RGB_LED2 23
#define RGB_LED3 22 // softPwm -> hw 핀이 모잘라서.. 

// user level에서는 동일하다.
// kernel build 에서는 무조건 void 넣어주는 게 좋다. 

int main(void) {

	int bright;

	printf("Raspberry Pi wiringPi PWM test program...\n");

	if (wiringPiSetup() == -1) {
		exit(1);
	}

	//PWM

	pinMode(RGB_LED1, PWM_OUTPUT);
	pinMode(RGB_LED2, PWM_OUTPUT);

	//soft pwm 

	pinMode(RGB_LED3, OUTPUT);
	
	// hw 는 1024 고정
	// sw 는 범위를 늘림 
	// 제어 목적으로 쓰기에는 포트가 적다. -> 완충하기 위해 led 연결 
	softPwmCreate(RGB_LED3, 0, 1024); //!! 

	pwmWrite(RGB_LED1, 0);
	pwmWrite(RGB_LED2, 0);
	softPwmWrite(RGB_LED3, 0);


	while(1) {
		for (bright = 0; bright < 1024; ++bright) {
			softPwmWrite(RGB_LED3, bright);
			//pwmWrite(RGB_LED1, bright);
			//pwmWrite(RGB_LED2, bright);
			delay(1);
		}


		for (bright = 1023; bright >= 0; --bright) {
			//pwmWrite(RGB_LED1, bright);
			softPwmWrite(RGB_LED3, bright);
			//pwmWrite(RGB_LED2, bright);
			delay(1);
		}
	}

}
