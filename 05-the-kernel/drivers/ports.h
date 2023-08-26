#ifndef PORTS
#define PORTS

/// type definition /////////////////////////
typedef unsigned char byte;
typedef unsigned short word;

/// port input //////////////////////////////
byte port_byteIn(word port);
word port_wordIn(word port);

/// port output /////////////////////////////
void port_byteOut(word port, byte value);
void port_wordOut(word port, word value);

#endif  // PORTS
