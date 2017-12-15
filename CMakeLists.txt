# assembly file

# stop if cmake version below 3.7.2
cmake_minimum_required( VERSION 3.7.2 FATAL_ERROR)

# choice of standard
set_target_properties( ${TARGET} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
        )

# project variable
set ( PROJECT_NAME cpp_project_template )

# project name
project ( ${PROJECT_NAME} )

# project version
set( VERSION_MAJOR 1 )
set( VERSION_MINOR 0 )

# output folder for binaries
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} )

# location of header files
include_directories( "inc" )

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
