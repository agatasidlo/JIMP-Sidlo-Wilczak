#include <string>
#include <utility>
#include <string>
#include <array>
#include <memory>
#include <map>

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H

using ::std::map;
using ::std::string;
using ::std::array;
//using TinyUrlCodec = map<string,array<char,6>>;

namespace tinyurl {
    struct TinyUrlCodec {
        string url;
        string tinyUrl;
        array<char, 6> key;
    };

    std::unique_ptr<TinyUrlCodec> Init();

    void NextHash(array<char, 6> *state);

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);

}
#endif //JIMP_EXERCISES_TINYURL_H
