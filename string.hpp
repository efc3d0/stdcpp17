#ifndef __STRING_H
#define __STRING_H
#include "IO.hpp"

namespace m34 {
template <ssize_t Size> class String {
  private:
    char *buffer;

  public:
    String() { buffer = new char[Size]; }
    String(char *buffer) {
        this->buffer = new char[Size];
        this->buffer = buffer;
    }

    void operator=(String &other) { this = other; }

    char operator[](int i) { return buffer[i]; }

    ssize_t getSize(String string) { return Size; }

    char *c_str() { return buffer; }

    ~String() { delete buffer; }
};
} // namespace m34

#endif
