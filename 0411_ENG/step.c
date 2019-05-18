
/*
	name : armkernel
	date : 2019 04 11
	descriptor : step motor.. 1-2 여상 
 */


#include <stdio.h>
#include <stdlib.h>

#include <wiringPi.h>

#define STEP1 27
#define STEP2 24
#define STEP3 28
#define STEP4 29

int pin[4] = { STEP1, STEP2, STEP3, STEP4 };

// 1-2 상 여자
// 1상과 2상의 동작을 번갈아 수행한다.

int seq[][4] = {
	{ 1,0,0,1 },
	{ 1,0,0,0 },
	{ 1,1,0,0 },
	{ 0,1,0,0 },
	{ 0,1,1,0 },
	{ 0,0,1,0 },
	{ 0,0,1,1 },
	{ 0,0,0,1 },
};

void forward(int step) {
	int i, j, k;

	for (i = 0; i < step; ++i) {
		for (j = 0; j < 8; ++j) {
			for (k = 0; k < 4; ++k) {
				digitalWrite(pin[k], seq[j][k]);
			}
			// 자석이 힘을 잡고 돌 시간이 필요하다. 
			delayMicroseconds(800);	// 800us
		}
	}
}

void backward(int step) {
	int i, j, k;

	for (i = 0; i < step; ++i) {
		for (j = 0; j < 8; ++j) {
			for (k = 0; k < 4; ++k) {
				digitalWrite(pin[k], seq[8- j -1][k]);
			}
			// 자석이 힘을 잡고 돌 시간이 필요하다. 
			delayMicroseconds(800);	// 800us
		}
	}
}

int main(void) {

	int i;

	wiringPiSetup();

	for (i = 0; i < 4; ++i) {
		pinMode(pin[i], OUTPUT);
	}

	while(1) {
		// 임의로 개발.. (경험적 추론..) 
		forward(1024);
		backward(1024);
		delay(100);
	}

	return 0;
}	

