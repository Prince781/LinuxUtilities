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

#include <stdio.h>
#include <stdlib.h>

#include "stopwatch.h" // unique stopwatch utilities
#include "options.h" // glorious POSIX option parsing

int main(int argc, char **argv) {
	int c, n = 0;
	
	while ((c=getopt_long(argc, argv, "h::s::t:",
		long_options, &option_i)) != -1)
		switch (c) {
			case 's':
				stopwatch();
				break;
			case 't':
				timeout(atof(optarg)); // run our timeout function
				n++;
				break;
			case 'h':
			default:
				display_help();
				return 0;
		}
	
	if (n == 0)
		display_help();

	return 0;
}
