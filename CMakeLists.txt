cmake_minimum_required(VERSION 3.0.0)
project(scyna VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_DEBUG_LIBS OFF)
set(Boost_USE_RELEASE_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost COMPONENTS date_time filesystem system)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_subdirectory(scyna)
    add_subdirectory(example)
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
