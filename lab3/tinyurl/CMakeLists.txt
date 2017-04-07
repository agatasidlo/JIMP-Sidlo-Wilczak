project(tinyurl)

set(HEDEAR_FILES TinyUrl.h)
set(SOURCE_FILES TinyUrl.cpp)

add_library(libtinyurl STATIC ${SOURCE_FILES})
target_include_directories(libtinyurl PUBLIC .)
