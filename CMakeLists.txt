# assembly file

# stop if cmake version below 3.7.2
cmake_minimum_required( VERSION 3.7.2 FATAL_ERROR)

# choice of standard
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

# project variable
set ( PROJECT_NAME cpp_project_template )

# project name
project ( ${PROJECT_NAME} )

# set c++ compiler flags for GNU
if( CMAKE_CXX_COMPILER_ID MATCHES GNU )
    set( CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -Wall -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual -Wwrite-strings -Wno-unused" )
    set( CMAKE_CXX_FLAGS_DEBUG   "-O0 -g" )
    set( CMAKE_CXX_FLAGS_RELEASE "-O2" )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage" )
endif()

# project version
set( VERSION_MAJOR 1 )
set( VERSION_MINOR 0 )

# output folder for binaries
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} )

################################
# Code Coverage
################################
if( CMAKE_BUILD_TYPE MATCHES Debug )
    set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

    include(CodeCoverage)
    setup_target_for_coverage(${PROJECT_NAME}_coverage ${PROJECT_NAME} coverage)
endif()
###############################


################################
# GTest
################################
set(GOOGLETEST_ROOT external/googletest/googletest CACHE STRING "Google Test source root")

include_directories(
        ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}
        ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include
)

set(GOOGLETEST_SOURCES
        ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest-all.cc
        ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest_main.cc
        )

foreach(_source ${GOOGLETEST_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()

add_library(gtest ${GOOGLETEST_SOURCES})

include_directories(
        inc/swap
        ${GTEST_INCLUDE_DIRS}
)
add_executable( GoogleTestDemo tests/swap.cpp )
target_link_libraries( GoogleTestDemo gtest pthread )

enable_testing()
add_test( GoogleTestDemo GoogleTestDemo )
################################


# location of header files
include_directories(
        inc/swap
)

# location of source files
aux_source_directory( src SOURCES )

# build executable
add_executable( ${PROJECT_NAME} ${SOURCES} )

# link process
target_link_libraries( ${PROJECT_NAME} )

# install target
set( CMAKE_INSTALL_PREFIX /usr/local )
install( TARGETS ${PROJECT_NAME} DESTINATION bin )

# uninstall target
configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Uninstall.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
        IMMEDIATE @ONLY)

add_custom_target(uninstall COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
