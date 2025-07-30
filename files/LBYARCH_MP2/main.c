#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern int computeAcceleration(float Vinit,float Vfinal,float time);
int main() {
	
	int sum = computeAcceleration(60.0,122.3,5.5);
	printf("Acceleration: %d\n", sum);
	return 0;
}