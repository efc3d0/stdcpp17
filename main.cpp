#include "IO.hpp"

int
main (void)
{
  m34::RWIo<char*> t;

  char * buffer = new char [5];

  t.readIO(buffer);

  t.writeIO(buffer);
}
