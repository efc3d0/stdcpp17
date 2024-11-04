#ifndef __IO_H
#define __IO_H

#include <unistd.h>
#include <sys/types.h>

namespace m34 {
  template <class T>
  class InterfaceIO {
  protected:
    virtual ssize_t readIO(T buffer) = 0;
    virtual ssize_t writeIO(T buffer) = 0;
  };

  template<class T>
  class RWIo : protected InterfaceIO<T> {
  public:
    ssize_t readIO(T buffer) override {
      return read (0, buffer, sizeof(buffer));
    }
    ssize_t writeIO(T buffer) override {
      return write (1, buffer, sizeof(buffer));
    }
  };
}
#endif
