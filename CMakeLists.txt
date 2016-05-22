cmake_minimum_required(VERSION 3.5)
project(ray0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(FREEIMAGE_FIND_REQUIRED, TRUE)
find_package(freeimage)
include_directories(SYSTEM ${FREEIMAGE_INCLUDE_DIRS})

find_package(GLM REQUIRED)

set(SOURCE_FILES main.cpp)
add_executable(ray0 ${SOURCE_FILES})
target_link_libraries(ray0 ${FREEIMAGE_LIBRARIES})
