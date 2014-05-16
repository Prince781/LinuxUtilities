// standard math demo

#include <stdio.h>
#include <stdlib.h>

#include "mathf.h"
#include <math.h>

#include <time.h>

int main(int argc, char **argv) {
	float val = sqrtf(64);
	// compare to math.h
	float val2 = (float) sqrt(64);
	
	return 0;
}
