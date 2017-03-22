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
        array<char, 6> arr;
        arr = *state;
        bool flag = true;
        int i = 5;
        while (flag) {
            if (arr[i] == 122)
                arr[i] = 48;
            else if (arr[i] == 90) {
                arr[i] = 97;
                flag = false;
            } else if (arr[i] == 57) {
                arr[i] = 65;
                flag = false;
            } else if (47 < arr[i] < 57 || 64 < arr[i] < 90 || 96 < arr[i] < 122) {
                arr[i] += 1;
                flag = false;
            }
            i--;
        }
        *state = arr;
    }



//    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {

//    }



//    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {

//    }
}
