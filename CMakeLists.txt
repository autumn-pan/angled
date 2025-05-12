cmake_minimum_required(VERSION 3.10)
project(angled)

set(SOURCES
    src/Matrix.cpp
    src/Quaternion.cpp
    src/Euler.cpp
)

set(HEADERS
    include/Matrix.h
    include/Quaternion.h
    include/Euler.h
)

add_library(angled STATIC ${SOURCES} ${HEADERS})

target_include_directories(angled PUBLIC $(CMAKE_CURRENT_SOURCE_DIR)/include)
