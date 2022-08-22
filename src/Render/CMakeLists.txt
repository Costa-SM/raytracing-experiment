file(GLOB SRCS *.cpp)

add_library(RENDER_LIB ${SRCS})
target_link_libraries(RENDER_LIB BASE_LIB)
target_include_directories(RENDER_LIB PUBLIC .)