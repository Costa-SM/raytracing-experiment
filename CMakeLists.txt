cmake_minimum_required(VERSION 3.15)
project(SimpleRaytracer)

file(GLOB SRC_H *.h)
file(GLOB SRC_CPP *.cpp)

add_executable(simple_raytracer ${SRC_H} ${SRC_CPP})