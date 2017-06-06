project(treeiterators)

set(HEADER_FILES TreeIterators.h Tree.h)
set(SOURCE_FILES TreeIterators.cpp)

add_library(libtreeiterators STATIC ${SOURCE_FILES})
target_include_directories(libtreeiterators PUBLIC .)
