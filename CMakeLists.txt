cmake_minimum_required(VERSION 3.0.0)
project(slicer VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING
            "Default build type: RelWithDebInfo" FORCE)
endif()

add_executable(slicer main.cpp reader.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
