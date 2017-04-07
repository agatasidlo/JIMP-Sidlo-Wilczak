#include <memory>
#include <iostream>
#include "TinyUrl.h"

using ::std::unique_ptr;
using ::std::array;

namespace tinyurl {

    unique_ptr<TinyUrlCodec> Init() {
        unique_ptr<TinyUrlCodec> urlList = std::make_unique<TinyUrlCodec>();
        return urlList;
    }

    void NextHash(array<char, 6> *state) {
        array<char, 6> &arr = *state;
        arr = *state;
        bool carry = true;
        int i = 5;
        while (carry) {
            carry = false;
            if (arr[i] == 'z') {
                arr[i] = '0';
                carry = true;
            }
            else if (arr[i] == 'Z')
                arr[i] = 'a';
            else if (arr[i] == '9')
                arr[i] = 'A';
            else if ('0' <= arr[i] < '9' || 'A' <= arr[i] < 'Z' || 'a' <= arr[i] < 'z')
                arr[i] += 1;
            i--;
        }
    }
}
