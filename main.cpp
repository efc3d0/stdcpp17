#include "IO.hpp"

int main(void) {
    m34::RWIo<const char *> w;

    w.writeIO("hello\n");

    m34::RWIo<int> ww;

    w.writeIO(17);
}
