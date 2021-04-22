#include <iostream>    // cout
#include "mathfuncs.h" // sin
#include <unistd.h>    // usleep
#include <wiringPi.h>  // pinMode digitalWrite
#define NUMPINS 8

// draw bar with length l
void bar(int l, char stroke = '-', char end = '#')
{
	for (l; l > 0; l--) std::cout << stroke;
	std::cout << end << std::endl;
}

void display(const int pins[], int i, int value)
{
	digitalWrite(pins[i], value);
	digitalWrite(pins[NUMPINS - 1 - i], value);
}

int main()
{
	wiringPiSetupGpio();
	int pins[] = { 17, 18, 27, 22, 23, 24, 25, 5 };
	// set all to output
	for (int i = 0; i < NUMPINS; i++) pinMode(pins[i], OUTPUT);
	float ANGINC = M_PI / 8;
	int prev = -1;
	for (float angle = 0; true; angle += ANGINC)
	{
		// turn off the prev one and turn on this one
		int cur = round((sin(angle) + 1) * (NUMPINS - 1)/2);
		if (cur != prev)
		{
			if (prev >= 0) display(pins, prev, 0);
			display(pins, cur, 1);
			prev = cur;
		}
		usleep(1e5);
	}
	return 0;
}
