cmake_minimum_required(VERSION 3.0.0)
project(aoc21 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

# set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
# set(THREADS_PREFER_PTHREAD_FLAG TRUE)
# find_package(Threads REQUIRED)

include(CTest)

file(GLOB aoc21_SRC
     "*.h"
     "*.cpp"
)
 
add_executable(aoc21 ${aoc21_SRC}) 

enable_testing()
add_subdirectory(tests)
add_subdirectory(01)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
 