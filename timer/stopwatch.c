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

time_t timeout(double seconds) {
	time_t start, end;
	time(&start); // initialize time
	
	double diff, last_diff = 0;

	while ((diff = difftime(time(&end), start)) < seconds)
		if (diff - last_diff > 0) {
			last_diff = diff;
			printf("Time: %d / %d\n", (int) diff, (int) seconds);
		}

	// timed out

	return end;
} 
