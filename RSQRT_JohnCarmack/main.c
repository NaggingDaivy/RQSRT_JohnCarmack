
#include <stdio.h>

//typedef int bool;
//#define true 1
//#define false 0
// bool in c

float Q_rsqrt(float number)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y = number;
	i = *(long *)&y; // evil floating point bit level hacking
	i = 0x5f3759df - (i >> 1); // what the fuck?
	y = *(float *)&i;
	y = y * (threehalfs - (x2 * y * y)); // 1st iteration
	// y = y * ( threehalfs - ( x2 * y * y ) ); // 2nd iteration, this can be removed

#ifndef Q3_VM
#ifdef __linux__
	assert(!isnan(y)); // bk010122 - FPE?
#endif
#endif
	return y;
}


int main(int argc, char * argv[])
{
	float fResult = 0;

	printf("Enter value : ");
	scanf("%f", &fResult);

	fResult = Q_rsqrt(4.0f);

	printf("Result : %f \n", fResult);
	
}


