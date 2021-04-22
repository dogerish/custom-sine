#include <iostream>    // cout
#include "mathfuncs.h" // sin
#include <unistd.h>    // usleep
#define TERMINALWIDTH 209

// draw bar with length l
void bar(int l, char stroke = '-', char end = '#')
{
	for (l; l > 0; l--) std::cout << stroke;
	std::cout << end << std::endl;
}

int main()
{
	float ANGINC = M_PI / 36;
	for (float angle = 0; true; angle += ANGINC)
	{
		bar(round((sin(angle) + 1) * (TERMINALWIDTH - 1) / 2), ' ');
		usleep(1e5);
	}
	return 0;
}
