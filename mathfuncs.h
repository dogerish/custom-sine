#ifndef MATHFUNCS
#define MATHFUNCS
#ifndef M_PI
	#define M_PI 3.14159265358979323846
#endif

// get sign of number
int sign(double);
// get absolute value
double abs(double);
// round to nearest integer
int round(double);
// modulus for floats
float fmod(float, float);
// raise x to the power of n
float pow(float, int);
// calculate the factorial of n
int factorial(int);
// calculate sin for angle theta (radians)
// higher precision makes a more accurate sine wave, but improvements are logarithmic
float sin(float, int = 6);
#endif
