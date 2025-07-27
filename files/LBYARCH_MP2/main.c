#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern double computeAcceleration(double Vinit,double Vfinal,double time);
int main() {
	
	double sum = computeAcceleration(60.0,122.3,5.5);
	printf("Acceleration: %1.lf\n", sum);
	return 0;
}