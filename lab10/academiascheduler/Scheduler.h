#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <cstdlib>
#include <stdexcept>
#include <set>
#include <map>

namespace academia {

    class SchedulingItem;

    class Schedule {
    public:
        Schedule OfTeacher(int teacher_id) const;

        Schedule OfRoom(int room_id) const;

        Schedule OfYear(int year) const;

        std::vector<int> AvailableTimeSlots(int n_time_slots) const;

        void InsertScheduleItem(const SchedulingItem &item);

        size_t Size() const;

        SchedulingItem operator[](int number) const;

    private:
        std::vector<SchedulingItem> schedulingVector;

    };

    class SchedulingItem {
    public:
        SchedulingItem() {};

        SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year) : course_id_{course_id},
                                                                                              teacher_id_{teacher_id},
                                                                                              room_id_{room_id},
                                                                                              time_slot_{time_slot},
                                                                                              year_{year} {}
        int CourseId() const;
        int TeacherId() const;

        int RoomId() const;

        int TimeSlot() const;

        int Year() const;
        void SetCourseId(int a);
        void SetTeacherId(int a);
        void SetRoomId(int a);
        void SetTimeSlot(int a);
        void SetYear(int a);
    private:
        int course_id_;
        int teacher_id_;
        int room_id_;
        int time_slot_;
        int year_;

    };

    class NoViableSolutionFound : public std::runtime_error {
    public:
        NoViableSolutionFound() : std::runtime_error("NoViableSolutionFound") {}
    };

    class Scheduler {
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                            const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                            const std::map<int, std::set<int>> &courses_of_year, int n_time_slots)=0;
    };

    class GreedyScheduler : public Scheduler {
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year, int n_time_slots);

    private:

    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H