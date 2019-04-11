
#include <stdio.h>
#include <string.h>
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


void showDigit(int value, int select) {
	int i;

	if (value < 0 || value > 9) {
		printf("out of index .. %d \n", value);
		return;
	}

	// point arr 로 전달 받아서 출력 
	int *arr = num[value];

	// == 활용해서 1,0 판단하는거 잘 확인 
	for (i = 1; i <= 3; i++) {
		digitalWrite(i, i == select);
	}

	for (i = 0; i < 8; i++) {
		digitalWrite(led[i],arr[i]);
	}
}

void count() {
	
	int n;
	int i;
	int value;
	int arr[3]; // 3자리 표현 

	for (n = 0; n <= 999; n++) {
	
		value = n ;
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
	
}

// void 적어줘라. 
int main(void) {

	int i;
	wiringPiSetup();

	for (i = 0; i < 8; i++) {
		pinMode(i + 1, OUTPUT);
	}

	for (i = 0; i < 3; i++) {
		pinMode(i + 1, OUTPUT);
	}

	count();
}
