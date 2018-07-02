#----------------------------------------------------------
# GTest
#----------------------------------------------------------
set(GOOGLETEST_ROOT external/googletest/googletest CACHE STRING "Google Test source root")

include_directories(
        ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}
        ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include)

set(GOOGLETEST_SOURCES
        ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest-all.cc
        ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest_main.cc
        )

foreach(_source ${GOOGLETEST_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()

add_library(gtest ${GOOGLETEST_SOURCES})

include_directories(
        ${GTEST_INCLUDE_DIRS}
        ${PROJECT_SOURCE_DIR}/include)

add_executable(test_swap ${CMAKE_CURRENT_SOURCE_DIR}/test_swap.cpp)

target_link_libraries(test_swap gtest pthread)

add_test(test_swap test_swap)
#----------------------------------------------------------


#----------------------------------------------------------
# Code Coverage
#----------------------------------------------------------
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
    include(CodeCoverage)
    APPEND_COVERAGE_COMPILER_FLAGS()
    setup_target_for_coverage(NAME coverage EXECUTABLE test_swap)
endif()
#----------------------------------------------------------
