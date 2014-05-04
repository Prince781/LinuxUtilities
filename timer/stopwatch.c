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
	
	while (difftime(start, time(&end)) < seconds);

	// timed out

	return end;
} 
