file(GLOB SRCS *.cpp)

add_library(MATH_LIB ${SRCS})
target_include_directories(MATH_LIB PUBLIC .)