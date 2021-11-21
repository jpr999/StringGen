project(StringGenTest)

include(FetchContent)
FetchContent_Declare(google_test
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG HEAD
)
FetchContent_MakeAvailable(google_test)

include(GoogleTest)

include_directories(${EXTERNAL_INSTALL_LOCATION}/include ../StringGenLib)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib64)

add_executable(${PROJECT_NAME} src/StringGenTest.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC gtest gtest_main pthread StringGenLib)
gtest_discover_tests(${PROJECT_NAME})
