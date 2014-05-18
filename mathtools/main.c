/**
 * MathF - math tools
 */
#include "mathf.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	float val1 = sqrtf(64);
	// compare to math.h
	float val2 = (float) sqrt(64);
	printf("val1 (mathf.h): %f, val2 (math.h): %f\n", val1, val2);

	unsigned long int val = factorial(10);
	printf("factorial(%lu) = %lu\n", 10L, val);
	return 0;
}
