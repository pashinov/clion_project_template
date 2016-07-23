cmake_minimum_required(VERSION 3.5)

set ( PROJECT template )

set ( CMAKE_CXX_STANDARD 14 )

set ( CMAKE_CXX_STANDARD_REQUIRED on )

set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14" )

set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lstdc++" )

#for debug
set ( CMAKE_DEBUG_POSTFIX "_d" CACHE STRING "postfix applied to debug build of libraries" )

#set ( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g" )

#for release
#set ( CMAKE_RELEASE_POSTFIX "" CACHE STRING "postfix applied to release build of libraries" )

#путь к исполнеямому файлу
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set ( SOURCES ../src/main.cpp
              ../src/hello.cpp)

project ( ${PROJECT} )

include_directories ( ../inc )

source_group  ( "Header Files" FILES ${HEADERS}  )

source_group  ( "Source Files" FILES ${SOURCES}  )

add_executable( ${PROJECT} ${HEADRES} ${SOURCES} )
