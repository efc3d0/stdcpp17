#ifndef __IO_H
#define __IO_H

#include <sys/types.h>
#include <unistd.h>

namespace m34 {
int strlen(const char *buffer) noexcept {
    int i = 0;
    while (*buffer) {
        buffer++;
        i++;
    }
    return i;
}

template <class T> class RWIo {

    int writefd;
    int readfd;

  public:
    RWIo(int rfd, int wrd) : writefd(wrd), readfd(rfd) {}

    RWIo() : writefd(1), readfd(0) {}

    ssize_t readIO(T buffer) noexcept {
        return read(readfd, reinterpret_cast<void *>(buffer), sizeof(buffer));
    }
    template <class U = T> ssize_t writeIO(U value) noexcept {
        char buffer[255];
        int length = convertIntToString(value, buffer);
        return write(writefd, buffer, length);
    }

    ssize_t writeIO(const char *buffer) noexcept {
        return write(writefd, buffer, strlen(buffer));
    }

    ssize_t writeIO(char value) noexcept { return write(writefd, &value, 1); }

  private:
    int convertIntToString(int num, char *buffer) {
        if (num == 0) {
            buffer[0] = '0';
            return 1;
        }

        int index = 0;
        int temp = num;

        while (temp > 0) {
            temp /= 10;
            index++;
        }

        for (int i = index - 1; i >= 0; --i) {
            buffer[i] = '0' + (num % 10);
            num /= 10;
        }

        return index;
    }
};
}

#endif
