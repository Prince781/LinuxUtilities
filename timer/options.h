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

#include <getopt.h>
#include <stdbool.h>

#define VERSION_MAJOR 0
#define VERSION_MINOR 1

static struct option long_options[] = {
	{"help", no_argument, 0, 'h'},
	{"timeout", required_argument,	0, 't'},
	{0, 0, 0, 0}
};

static char *opt_descr[] = {
	"Prints out this help message.",
	"Creates a timed response that occurs after [N] seconds. Useful\n\
	\t\t\tfor timing something."
};

static int option_i; // option index

static bool TIMER_DEBUG = false;

/**
 * Displays all help information/messages.
 */
static void display_help() {
	printf("Timer - v%d.%d\n\n", VERSION_MAJOR, VERSION_MINOR);
	printf("Usage: timer [OPTIONS] ...\n");
	
	// timeout option
	for (int i=0; long_options[i].name != 0; i++)
		printf("\t--%s | -%c\t\t%s\n", long_options[i].name,
			long_options[i].val, opt_descr[i]);
	
	
}
