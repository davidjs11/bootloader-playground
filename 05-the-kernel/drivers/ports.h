/// ports.h /////////////////////////////////

#ifndef PORTS_H
#define PORTS_H

#include "util.h"
#include "types.h"


/// functions ///////////////////////////////

// port input
u8 port_byteIn(u16 port);
u16 port_wordIn(u16 port);

// port output
void port_byteOut(u16 port, u8 value);
void port_wordOut(u16 port, u16 value);


#endif  // PORTS_H
