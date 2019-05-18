#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#include <wiringPi.h>
#include <mcp3422.h>

int leds[] = {27,24,28,29};

void led_on (int ratio) {
	int i;
	int limit = ratio / 512;

	for (i = 0; i < 4; i++) {
		if (i <= limit) digitalWrite(leds[i], HIGH);
		else digitalWrite(leds[i], LOW);
	}
}

int main (void) {
	int i;
	wiringPiSetup();

	mcp3422Setup (400, 0x6a, 0, 0);

	for (i = 0; i < 4; i++) {
		pinMode(leds[i], OUTPUT);
		digitalWrite(leds[i], LOW);
	}

	for (;;) {
		int reading = analogRead(403);
		printf("%d\n", reading);
		led_on(reading);
		delay(1000);
	}
}
