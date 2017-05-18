
#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <map>
#include <set>
#include <stdexcept>

namespace academia {
    class SchedulingItem {
    public:
        SchedulingItem();

        SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year);

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
        int course_id;
        int teacher_id;
        int room_id;
        int time_slot;
        int year;
    };

    class Schedule : public SchedulingItem {
    public:
        Schedule OfTeacher(int teacher_id) const;

        Schedule OfRoom(int room_id) const;

        Schedule OfYear(int year) const;

        std::vector<int> AvailableTimeSlots(int n_time_slots) const;

        void InsertScheduleItem(const SchedulingItem &item);

        size_t Size() const;

        SchedulingItem operator[](int number) const;

        std::vector<SchedulingItem> schedulingVector;
    };

    class Scheduler : Schedule {
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year, int n_time_slots);
    };

    class NoViableSolutionFound : public std::runtime_error {
    public:
        NoViableSolutionFound() : std::runtime_error("No viable solution found") {}
    };

    class GreedyScheduler : public Scheduler {

    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H