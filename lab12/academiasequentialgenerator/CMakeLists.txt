project(sequentialgenerator)

set(HEADER_FILES SequentialGenerator.h)
set(SOURCE_FILES SequentialGenerator.cpp)

add_library(libsequentialgenerator STATIC ${SOURCE_FILES})
target_include_directories(libsequentialgenerator PUBLIC .)
