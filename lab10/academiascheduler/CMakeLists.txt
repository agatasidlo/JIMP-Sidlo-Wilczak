project(academiascheduler)

set(HEDEAR_FILES Scheduler.h)
set(SOURCE_FILES Scheduler.cpp)

add_library(libscheduler STATIC ${SOURCE_FILES})
target_include_directories(libscheduler PUBLIC .)

