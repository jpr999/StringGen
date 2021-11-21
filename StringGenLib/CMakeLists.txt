project(StringGenLib VERSION 0.1.0)

link_directories( ${LIBFMT_LIBRARY_DIRS}  )
include_directories( ${LIBFMT_INCLUDE_DIRS} .. )

add_library( ${PROJECT_NAME} STATIC src/lib.cpp)

target_link_libraries( ${PROJECT_NAME} )

