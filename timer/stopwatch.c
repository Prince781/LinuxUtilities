/***************************************************
 * Timer
 * ------------------------------------------------
 * A simple command-line utility to use as a timer,
 * stopwatch, etc.
 * ------------------------------------------------
 * Blah blah, GNU General Public License v3, blah
 * this program is open-source, blah, you should've
 * received your copy of Stallman's Bible at 123
 * MUH FREEDOMS Ave, Boston, MA.
 * ------------------------------------------------
 * 2014 Princeton Ferro
****************************************************/

#include "stopwatch.h"
#include <stdlib.h>
#include <unistd.h>

time_t timeout(double seconds) {
	time_t start, end;
	time(&start); // initialize time
	
	double diff, last_diff = 0;

	while ((diff = difftime(time(&end), start)) < seconds) {
		if (diff - last_diff > 0) {
			last_diff = diff;
			printf("Time: %ds / %ds\n", (int) diff, (int) seconds);
			fflush(stdout);
			// printf("\b\b\b\b");
		} sleep(1);
	}

	// timed out

	return end;
}

void stopwatch() {
	time_t start = time(NULL);
	double diff, last_diff = 0;
	int c;
	
	while ((c = getchar()) != EOF) {
		if (c == 'c')
			printf("Breakpoint entered.");
		
		diff = difftime(time(NULL), start);
		if (diff - last_diff > 0) {
			last_diff = diff;
			printf("Time: %f\n", (float) diff); // print elapsed
		}

		fflush(stdin);
	}
}
