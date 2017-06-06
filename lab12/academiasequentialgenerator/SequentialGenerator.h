#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

template<class Id, class Counter>
class SequentialIdGenerator {
public:
    SequentialIdGenerator() : counter_{0} {}

    SequentialIdGenerator(const Counter &value) : counter_{value} {}

    Id NextValue();

private:
    Counter counter_;
};

template<class Id, class Counter>
Id SequentialIdGenerator<Id, Counter>::NextValue() {
    Id new_count = (Id) counter_;
    ++counter_;
    return new_count;
}


#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H