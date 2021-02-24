cmake_minimum_required(VERSION 3.15.0)
project(StringGen VERSION 0.1.0)

find_package(fmt)
include_directories( ${LIBFMT_INCLUDE_DIRS} ../StringGenLib)
add_executable( ${PROJECT_NAME} src/main.cpp)

link_directories( ${LIBFMT_LIBRARY_DIRS}  ${LIBRARY_OUTPUT_DIRECTORY})
target_link_libraries(${PROJECT_NAME}  fmt::fmt StringGenLib)
