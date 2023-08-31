/// timer.h /////////////////////////////////

#ifndef TIMER_H
#define TIMER_H

#include "util.h"

#define PIT_FREQUENCY   1193180


/// functions ///////////////////////////////

// initialize timer
void timer_init(u32 frequency);

// get the current tick count
u32 timer_getTicks();

// reset the timer
void timer_reset();

// wait 'n' ticks
void timer_wait(u32 n);


#endif  // TIMER_H
