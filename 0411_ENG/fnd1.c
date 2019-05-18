
#include <stdio.h>

#include <wiringPi.h>

int led[8] = { 11, 10, 13, 12, 14, 15, 16, 0 };
//				a  b  c  d  e  f  g  dot

// lookup table
int num[10][8] = {
	{ 1, 1, 1, 1, 1, 1, 0, 0 }, //0
	{ 0, 1, 1, 0, 0, 0, 0, 0 },
	{ 1, 1, 0, 1, 1, 0, 1, 0 },
	{ 1, 1, 1, 1, 0, 0, 1, 0 },
	{ 0, 1, 1, 0, 0, 1, 1, 0 },
	{ 1, 0, 1, 1, 0, 1, 1, 0 },
	{ 1, 0, 1, 1, 1, 1, 1, 0 },
	{ 1, 1, 1, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 1, 1, 1, 1, 0, 1, 1, 0 }
};


void showDigit(int value) {
	int i;

	if (value < 0 || value > 9) {
		printf("out of index .. %d \n", value);
		return;
	}

	// point arr 로 전달 받아서 출력 
	int *arr = num[value];

	for (i = 0; i < 8; i++) {
		digitalWrite(led[i],arr[i]);
	}
}

// void 적어줘라. 
int main(void) {

	int i;
	wiringPiSetup();

	for (i = 0; i < 8; i++) {
		pinMode(i + 1, OUTPUT);
	}
	
	while(1) {
		showDigit(7);
		delay(1);
	}
}
