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
	{"stopwatch", no_argument, 0, 's'},
	{"timeout", required_argument,	0, 't'},
	{0, 0, 0, 0}
};

static char *opt_descr[] = {
	"\tPrints out this help message.",
	"Starts an interactive stopwatch.",
	"\tCreates a timed response that occurs after [N]\n\
	\t\t\tseconds. Useful for timing something."
};

static int option_i; // option index

// static bool TIMER_DEBUG = false;


