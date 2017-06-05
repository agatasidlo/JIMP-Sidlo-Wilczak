#include "TeacherHash.h"

namespace academia {

    TeacherId::TeacherId() {}

    TeacherId::TeacherId(int id) : id_(id) {}

    TeacherId::operator int() const {
        return id_;
    }


    Teacher::Teacher() {}

    Teacher::Teacher(const TeacherId &id, string name, string depart) : id_(id), name_(name), department_(depart) {}

    int Teacher::Id() const { return id_; }

    string Teacher::Name() const { return name_; }

    string Teacher::Department() const { return department_; }

    bool Teacher::operator==(const Teacher &value) const {
        if ((id_ == value.id_ && name_ == value.name_ && department_ == value.department_))
            return true;
        else
            return false;
    }

    bool Teacher::operator!=(const Teacher &value) const {
        if ((id_ != value.id_ || name_ != value.name_ || department_ != value.department_))
            return true;
        else
            return false;
    }


    std::size_t TeacherHash::operator()(const Teacher &x) const {
        return std::hash<int>()(x.Id()) ^ std::hash<std::string>()(x.Department()) ^ std::hash<std::string>()(x.Name());
    }
}