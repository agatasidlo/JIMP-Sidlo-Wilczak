
#include <algorithm>
#include <iostream>
#include "Scheduler.h"

namespace academia {
    SchedulingItem::SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year) : course_id(
            course_id), teacher_id(teacher_id), room_id(room_id), time_slot(time_slot), year(year) {}

    SchedulingItem::SchedulingItem() {}

    int SchedulingItem::CourseId() const { return course_id; }

    int SchedulingItem::TeacherId() const { return teacher_id; }

    int SchedulingItem::RoomId() const { return room_id; }

    int SchedulingItem::TimeSlot() const { return time_slot; }

    int SchedulingItem::Year() const { return year; }

    void SchedulingItem::SetCourseId(int a) { course_id = a; };

    void SchedulingItem::SetTeacherId(int a) { teacher_id = a; };

    void SchedulingItem::SetRoomId(int a) { room_id = a; };

    void SchedulingItem::SetTimeSlot(int a) { time_slot = a; };

    void SchedulingItem::SetYear(int a) { year = a; };

    Schedule Schedule::OfTeacher(int teach) const {
        Schedule oneTeacher;
        std::copy_if(schedulingVector.begin(), schedulingVector.end(),
                     std::back_inserter(oneTeacher.schedulingVector),
                     [&teach](SchedulingItem teacher) {
                         bool k = false;
                         if (teacher.TeacherId() == teach)k = true;
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
        return schedulingVector[number];
    }

    Schedule Scheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                           const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                           const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) {

        Schedule out;
        SchedulingItem sch;
        int nextFreeRoom = 0;
        int nextFreeTimeSlot = 1;


        for (auto i = courses_of_year.begin(); i != courses_of_year.end(); i++) {
            for (auto j = i->second.begin(); j != i->second.end(); j++) {
                sch.SetCourseId(*j);
                for (auto teacherIter = teacher_courses_assignment.begin();
                     teacherIter != teacher_courses_assignment.end(); teacherIter++) {
                    auto pom = std::find(teacherIter->second.begin(), teacherIter->second.end(), *j);
                    if (pom != teacherIter->second.end()) {
                        sch.SetTeacherId(teacherIter->first);
                        break;
                    }
                }
                sch.SetRoomId(rooms[nextFreeRoom]);
                sch.SetTimeSlot(nextFreeTimeSlot);
                sch.SetYear(i->first);

                if (n_time_slots <= nextFreeTimeSlot) {
                    nextFreeTimeSlot = 1;
                    nextFreeRoom++;
                } else
                    nextFreeTimeSlot++;

                out.InsertScheduleItem(sch);
            }
        }

        int amountOfCourses = 0;
        for (auto teacher_courses : teacher_courses_assignment) {
            std::vector<int> vectorOfCourses = teacher_courses.second;
            for (auto singleCourse : vectorOfCourses) {
                if (singleCourse) {
                    amountOfCourses++;
                }
                if (amountOfCourses > n_time_slots) {
                    throw NoViableSolutionFound();
                }
            }
        }

        return out;
    }


}