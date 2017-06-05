#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <iostream>
#include <chrono>
#include <utility>

namespace profiling {

    template<class T>
    auto TimeRecorder(T obj) {
        static std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
        auto NewObj = (obj)();
        std::chrono::duration<double, std::milli> elapsed = std::chrono::high_resolution_clock::now() - start;
        return std::make_pair(NewObj, elapsed.count());
    }
}

#endif //JIMP_EXERCISES_TIMERECORDER_H