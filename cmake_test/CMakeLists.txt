cmake_minimum_required(VERSION 2.6)

# sub project
add_subdirectory(lib_1)

# print message
message("cmake test project")
message("root path =" ${CMAKE_SOURCE_DIR} )

# Project Name
set( PROJECT_NAME cmake_test )
project(${PROJECT_NAME})

# preprocessor define
set( DEFINE "-DCMAKE_TEST"
            "-DCMAKE_TEST2" )
add_definitions( ${DEFINE} )

# include path
set( INCLUDE_PATH )
include_directories( ${INCLUDE_PATH} )

# library link 
set( LIB_PATH )
link_directories( ${LIB_PATH} )

# main source path
set( SOURCE_PATH ./main/ )
# source 
set( SOURCE ${SOURCE_PATH}main.cpp )
set( SOURCE ${SOURCE} ${SOURCE_PATH}cmake.cpp )
# head
set( HEAD ${SOURCE_PATH}cmake.h )
# exec file
add_executable( ${PROJECT_NAME} ${SOURCE} ${HEAD} )
target_link_libraries( ${PROJECT_NAME} lib_1 )