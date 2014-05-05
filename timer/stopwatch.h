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
#include <time.h>

/**
 * Starts a timer from NOW to NOW+seconds.
 */
extern time_t timeout(double seconds);

/**
 * Starts an interactive stopwatch, which may be cancelled at any time by the
 * EOF character. Specific breakpoints in the stopwatch can be controlled by
 * entering "c".
 */
extern void stopwatch();
