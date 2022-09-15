# Get the .cpp tests
file(GLOB TEST_PROGRAMS *.cpp)

message("Current Source Directory: " ${CMAKE_SOURCE_DIR})

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    message("Found OpenMP.")
endif()

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Add the executables for each of the tests
foreach(file_path ${TEST_PROGRAMS})
    get_filename_component(file_name_we ${file_path} NAME_WE)
    add_executable(${file_name_we} ${file_path})

    # Add dependant libraries
    target_link_libraries(${file_name_we} BASE_LIB RENDER_LIB ${SDL2_LIBRARIES})

    if(OpenMP_CXX_FOUND)
        target_link_libraries(${file_name_we} OpenMP::OpenMP_CXX)
    endif()
endforeach()
