project(timerecorder)

set(HEDEAR_FILES TimeRecorder.h)
set(SOURCE_FILES TimeRecorder.cpp)

add_library(libtimerecorder STATIC ${SOURCE_FILES})
target_include_directories(libtimerecorder PUBLIC .)
