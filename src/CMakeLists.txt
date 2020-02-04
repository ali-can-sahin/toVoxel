cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(toVoxel)

set(Boost_INCLUDE_DIR "/usr/local/include")
set(BOOST_LIBRARY_DIR "/usr/local/lib")

find_package(PCL 1.9.1 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})

link_directories(${PCL_LIBRARY_DIRS})

add_definitions(${PCL_DEFINITIONS})

add_executable (toVoxel main.cpp)

target_link_libraries (toVoxel ${PCL_LIBRARIES} )
