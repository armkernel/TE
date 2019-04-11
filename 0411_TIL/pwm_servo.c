/*
	name : armkernel
	date : 2019 04 11
	desciptor : servo test 
 */


#include <stdio.h>
#include <stdlib.h>

#include <wiringPi.h>
#include <softServo.h>

#define SERVO_GPIO 25 // 설계도 참고

// softServo.c 소스 파일을.. 같이 빌드해야함 
// $ gcc pwm_servo.c -lwiringPi ~/wiringPi/wiringPi/softServo.c 

int main(void) {

	if (wiringPiSetup() == -1) {
		exit(1);
	}

	// 동시에 여러개로 쓸 수 있다. 
	// 관절 자체
	softServoSetup(SERVO_GPIO, -1, -1, -1, -1, -1, -1, -1);

	// -250 ~ 1250 (각도 범위) 

	while (1) {
		printf("0\n");
		softServoWrite(SERVO_GPIO, 0);
		getchar(); 
		printf("-250\n");
		softServoWrite(SERVO_GPIO, -250);
		getchar();
		printf("500\n");
		softServoWrite(SERVO_GPIO, 500);
		getchar();
		printf("1250\n");
		softServoWrite(SERVO_GPIO, 1250);
		getchar();

	}


}
