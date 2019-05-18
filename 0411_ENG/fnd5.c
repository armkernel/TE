
#include <stdio.h>
#include <string.h>
#include <wiringPi.h>
#include <pthread.h>
#include <mcp3422.h>

int led[8] = { 11, 10, 13, 12, 14, 15, 16, 0 };
//				a  b  c  d  e  f  g  dot

#if 0
int num[10][8] = {
	{ 1, 1, 1, 1, 1, 1, 0, 0 }, //0xFC
	{ 0, 1, 1, 0, 0, 0, 0, 0 }, //0x60
	{ 1, 1, 0, 1, 1, 0, 1, 0 }, //0xDA
	{ 1, 1, 1, 1, 0, 0, 1, 0 }, //0xF2
	{ 0, 1, 1, 0, 0, 1, 1, 0 }, //0x66
	{ 1, 0, 1, 1, 0, 1, 1, 0 }, //0xB6
	{ 1, 0, 1, 1, 1, 1, 1, 0 }, //0xBE
	{ 1, 1, 1, 0, 0, 0, 0, 0 }, //0xE0
	{ 1, 1, 1, 1, 1, 1, 1, 0 }, //0xFE
	{ 1, 1, 1, 1, 0, 1, 1, 0 }  //0xF6
};
#endif

// bit로 하기 
int num[10] = {
	0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6
};

// num 0 ~ 9
int fnd_value;

void showDigit(int value, int select) {
	int i;
	int n;	

	if (value < 0 || value > 9) {
		printf("out of index .. %d \n", value);
		return;
	}

	// point arr 로 전달 받아서 출력 
	n = num[value];

	// == 활용해서 1,0 판단하는거 잘 확인 
	for (i = 1; i <= 3; i++) {
		digitalWrite(i, i == select);
	}

	for (i = 0; i < 8; i++) {
		// shift 연산을 통한 비트 마스크! 
		digitalWrite(led[i], n & (1 << (7 - i)));
	}
}

void showDigit3(int value) {
	
	int i;
	int arr[3]; // 3자리 표현 
			
	memset(arr, 0, sizeof arr);
	i = 0;
	while (value > 0) {
		arr[i++] = value % 10;
		value /= 10;
	}

		// 사람 눈에 보여주기 위해서 
		for (i = 0; i < 100; i++) {
			showDigit(arr[2], 1);
			delay(1); // led가 온되는 걸 기다림
			showDigit(arr[1], 2);
			delay(1);
			showDigit(arr[0], 3);
			delay(1);
		}

}

void *fnd_thread(void *arg) {
	while(1) {
		showDigit3(fnd_value);
	}
}

// void 적어줘라. 
int main(void) {

	int i;
	pthread_t thread;
	wiringPiSetup();
	mcp3422Setup(400, 0x6a, 0, 0);

	for (i = 0; i < 8; i++) {
		pinMode(i + 1, OUTPUT);
	}

	for (i = 0; i < 3; i++) {
		pinMode(i + 1, OUTPUT);
	}

	pthread_create(&thread, NULL, fnd_thread, NULL);
	pthread_detach(thread);

	while (1) {
		int reading = analogRead(401);
		double voltage = reading / 1000.;
		double temp = (voltage - 0.5) * 100;

		printf("temp: %lf\n", temp);
		fnd_value = temp;

		delay(1000);
	}

	//count();
}
