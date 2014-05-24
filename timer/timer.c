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
#include <string.h>

#include "stopwatch.h" // unique stopwatch utilities
#include "options.h" // glorious POSIX option parsing

/**
 * Displays all help information/messages.
 */
void display_help() {
	printf("Timer - v%d.%d\n\n", VERSION_MAJOR, VERSION_MINOR);
	printf("Usage: timer [OPTIONS] ...\n");
	
	// timeout option
	for (int i=0; long_options[i].name != 0; i++)
		printf("\t--%s | -%c\t%s\n", long_options[i].name,
			long_options[i].val, opt_descr[i]);
}

int main(int argc, char **argv) {
	int c, n = 0;
	
	while ((c=getopt_long(argc, argv, "h::s::t:",
		long_options, &option_i)) != -1)
		switch (c) {
			case 's':
				stopwatch();
				n++;
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
