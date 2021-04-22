#include "mathfuncs.h"
#include <stdio.h>     // printf

int sign(double d) { return (d >= 0)*2 - 1; }

double abs(double d) { return sign(d) * d; }

int round(double d)
{
	int i = d; // integer version
	// add 1 to the integer version in the direction of d if  the decimal is >= 0.5
	// otherwise add nothing
	return i + (abs(d - i) >= 0.5) * sign(d);
}

double fmod(double de, double dv) { return de - (int)(de / dv) * dv; }

float pow(float x, int n)
{
	float result = 1;
	for (int i = 0; i < n; i++) result *= x;
	return result;
}

int factorial(int n)
{
	int result = n;
	// decrement to 1, multiplying result by the next one
	for (n--; n > 1; n--) result *= n;
	return result;
}

float sin(float theta, int precision)
{
	// mod it to keep precision (only look at the most accurate section)
	theta = fmod(theta + M_PI, 2*M_PI) - M_PI;
	// essentially does theta^1 / 1! - theta^3 / 3! + theta^5 / 5! - theta^7 / 7!...
	float result = 0;
	// account for incrementing n by 2
	precision *= 2;
	for (int n = 1; n <= precision; n += 2)
		result += ( ((n - 1) % 4) ? -1 : 1 ) * pow(theta, n) / factorial(n);
		/*printf("%i * %f^%i / %i!\t",
			((n - 1) % 4) ? -1 : 1,
			theta,
			n,
			n
		);*/
	// printf("\n");
	return result;
}
