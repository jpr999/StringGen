cmake_minimum_required(VERSION 3.10)
project(StringGenTest)

include(ExternalProject)

set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)

externalproject_add(googletest
    GIT_REPOSITORY git@github.com:google/googletest.git
    GIT_TAG main 
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)

include(CTest)
enable_testing()

include_directories(${EXTERNAL_INSTALL_LOCATION}/include ../StringGenLib)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib64)

add_executable(${PROJECT_NAME} src/StringGenTest.cpp)
add_dependencies(${PROJECT_NAME} googletest)
target_link_libraries(${PROJECT_NAME} PUBLIC gtest gtest_main pthread StringGenLib)

add_test( NAME ${PROJECT_NAME}  
          COMMAND ${PROJECT_NAME})