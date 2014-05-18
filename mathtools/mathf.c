#include "mathf.h"
#include <math.h>

float sqrtf(float n) {
	float s1 = 1, s2 = 2;
	int i;
	
	for (i=0; s2 - s1 > SQRTF_THRESHOLD; i++) {
		if (i%2) s2 = s1 - (s1*s1 - n)/(2*s1);
		else s1 = s2 - (s2*s2 - n)/(2*s2);
	}
	
	return i%2 ? s1 : s2;
}

unsigned long int factorial(int n) {
	float sum = 0;
	int i;
	for (i=2; i<=n; i++)
		sum += log(i);
	
	return (unsigned long int)(exp(sum)+1);
}
