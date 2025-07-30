#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern int computeAcceleration(float Vinit,float Vfinal,float time);
int main() {
	
	int sum = computeAcceleration(0.0f,62.5f,10.1f);
	printf("Acceleration: %d\n", sum);
	sum = computeAcceleration(60.0f, 122.3f, 5.5f);
	printf("Acceleration: %d\n", sum);
	sum = computeAcceleration(30.0f, 160.7f, 7.8f);
	printf("Acceleration: %d\n", sum);
	return 0;
}