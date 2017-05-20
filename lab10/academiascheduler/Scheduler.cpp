#include <algorithm>
#include <string>
#include <iostream>
#include"Scheduler.h"


namespace academia {

    int SchedulingItem::CourseId() const {
        return course_id_;
    }

    int SchedulingItem::TeacherId() const {
        return teacher_id_;
    }

    int SchedulingItem::RoomId() const {
        return room_id_;
    }

    int SchedulingItem::TimeSlot() const {
        return time_slot_;
    }

    int SchedulingItem::Year() const {
        return year_;
    }

    void SchedulingItem::SetCourseId(int a) { course_id_ = a; };

    void SchedulingItem::SetTeacherId(int a) { teacher_id_ = a; };

    void SchedulingItem::SetRoomId(int a) { room_id_ = a; };

    void SchedulingItem::SetTimeSlot(int a) { time_slot_ = a; };

    void SchedulingItem::SetYear(int a) { year_ = a; };

    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule oneTeacher;
        std::copy_if(schedulingVector.begin(), schedulingVector.end(), std::back_inserter(oneTeacher.schedulingVector),
                     [&teacher_id](SchedulingItem teacher) {
                         bool k = false;
                         if (teacher.TeacherId() == teacher_id)k = true;
                         return k;
                     });
        return oneTeacher;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule oneRoom;
        std::copy_if(schedulingVector.begin(), schedulingVector.end(), std::back_inserter(oneRoom.schedulingVector),
                     [&room_id](SchedulingItem room) {
                         bool k = false;
                         if (room.RoomId() == room_id)k = true;
                         return k;
                     });
        return oneRoom;

    }

    Schedule Schedule::OfYear(int year) const {
        Schedule oneYear;
        std::copy_if(schedulingVector.begin(), schedulingVector.end(), std::back_inserter(oneYear.schedulingVector),
                     [&year](SchedulingItem years) {
                         bool k = false;
                         if (years.Year() == year)k = true;
                         return k;
                     });
        return oneYear;
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        bool IsEmpty[n_time_slots + 1];
        for (int i = 1; i <= n_time_slots; i++) IsEmpty[i] = true;
        for (int i = 0; i < Size(); i++) {
            IsEmpty[schedulingVector[i].TimeSlot()] = false;
        }
        std::vector<int> vect;
        for (int i = 1; i <= n_time_slots; i++) {
            if (IsEmpty[i])
                vect.push_back(i);
        }
        return vect;

    }

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
        schedulingVector.push_back(item);
    }

    size_t Schedule::Size() const {
        size_t n = 0;
        for (auto i:schedulingVector) n++;
        return n;
    }

    SchedulingItem Schedule::operator[](int number) const {
        return this->schedulingVector[number];
    }

    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {

        Schedule out;
        SchedulingItem sch;
        int nextFreeRoom = 0;
        int nextFreeTimeSlot = 1;
        bool isTeacherForCourse = false;

        int amountOfCoursesForOneYear = 0;
        for (auto year_courses : courses_of_year) {
            for (auto certainCourse : year_courses.second) {
                for (auto teacher_courses : teacher_courses_assignment) {
                    std::vector<int> vectorOfCoursesForOneYear = teacher_courses.second;
                    for (auto singleCourse : vectorOfCoursesForOneYear) {
                        if (certainCourse == singleCourse) {
                            amountOfCoursesForOneYear++;
                        }
                    }
                }
            }
            if (amountOfCoursesForOneYear > n_time_slots) {
                throw NoViableSolutionFound();
            }
            amountOfCoursesForOneYear = 0;
        }
        for (auto teacher_courses : teacher_courses_assignment) {
            for (auto singleTeachersCourse : teacher_courses.second) {
                for (auto courses_year : courses_of_year) {
                    for (auto singleCourse : courses_year.second) {
                        sch.SetCourseId(singleCourse);
                        if (singleCourse == singleTeachersCourse) {
                            isTeacherForCourse = true;
                            sch.SetTeacherId(teacher_courses.first);
                            sch.SetRoomId(rooms[nextFreeRoom]);
                            sch.SetTimeSlot(nextFreeTimeSlot);
                            sch.SetYear(courses_year.first);

                            if (n_time_slots <= nextFreeTimeSlot) {
                                nextFreeTimeSlot = 1;
                                nextFreeRoom++;
                            } else
                                nextFreeTimeSlot++;

                            out.InsertScheduleItem(sch);
                        }

                    }
                    if (isTeacherForCourse == false) {
                        throw NoViableSolutionFound();
                    }
                }

            }
        }
        return out;
    }
}