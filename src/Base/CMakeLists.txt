file(GLOB SRCS *.cpp)

add_library(BASE_LIB ${SRCS})
target_include_directories(BASE_LIB PUBLIC .)