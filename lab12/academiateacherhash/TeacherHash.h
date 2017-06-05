#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <string>
#include <iostream>

using ::std::string;

namespace academia {

    class TeacherId {
    public:
        TeacherId();

        TeacherId(int id);

        operator int() const;

    private:
        int id_;
    };

    class Teacher {
    public:
        Teacher();

        Teacher(const TeacherId &id, string name, string depart);

        int Id() const;

        string Name() const;

        string Department() const;

        bool operator!=(const Teacher &value) const;

        bool operator==(const Teacher &teacher) const;

    private:
        string name_;
        string department_;
        int id_;
    };


    class TeacherHash {
    public:
        std::size_t operator()(const Teacher &x) const;
    };
}
#endif //JIMP_EXERCISES_TEACHERHASH_H