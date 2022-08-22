# Get the .cpp tests
file(GLOB TEST_PROGRAMS *.cpp)

# Add the executables for each of the tests
foreach(file_path ${TEST_PROGRAMS})
    get_filename_component(file_name_we ${file_path} NAME_WE)
    add_executable(${file_name_we} ${file_path})

    # Add dependant libraries
    target_link_libraries(${file_name_we} BASE_LIB RENDER_LIB)
endforeach()
