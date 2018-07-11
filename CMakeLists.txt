cmake_minimum_required(VERSION 3.1)

project(cpp-project-template VERSION 1.0.2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(WITH_TESTS "Enable Unit Tests" OFF)

option(WITH_ASAN "Build with Address Sanitizer" OFF)
option(WITH_TSAN "Build with Threads Sanitizer" OFF)
option(WITH_MSAN "Build with Memory Sanitizer" OFF)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" AND USE_CLANG_LIBCPP)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()

if(WITH_TSAN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread -g -O2 -fPIC -pie")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=thread -g -O2 -fPIC -pie")
endif()

if(WITH_ASAN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fsanitize=address -fno-omit-frame-pointer -O1")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fsanitize=address -fno-omit-frame-pointer -O1")
endif()

if(WITH_MSAN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=memory -fno-omit-frame-pointer -g")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=memory -fno-omit-frame-pointer -g")
endif()


set(HDR_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/include/handler.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/swap.hpp
        )

set(SRC_MAIN_FILE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
        )

include_directories(include)

add_executable(cpp-project-template ${SRC_MAIN_FILE} ${HDR_FILES})

if(WITH_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()

# install target
install(TARGETS ${PROJECT_NAME} DESTINATION /usr/local/bin)

# uninstall target
configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Uninstall.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
        IMMEDIATE @ONLY)

add_custom_target(uninstall COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
