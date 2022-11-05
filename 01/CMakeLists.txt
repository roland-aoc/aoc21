# target_include_directories(foo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
 
file(GLOB 01_SRC
     "*.h"
     "*.cpp"
)

# add_executable(aoc21 ${aoc21_SRC})  
add_library(01 ${01_SRC})