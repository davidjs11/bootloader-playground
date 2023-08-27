#ifndef PORTS
#define PORTS

#include "util.h"

/// port input //////////////////////////////
u8 port_byteIn(u16 port);
u16 port_wordIn(u16 port);

/// port output /////////////////////////////
void port_byteOut(u16 port, u8 value);
void port_wordOut(u16 port, u16 value);

#endif  // PORTS
