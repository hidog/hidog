cmake_minimum_required(VERSION 2.6)

# print message
message("lib_1 project")
message("current path =" ${CMAKE_CURRENT_SOURCE_DIR} )

# Project Name
set( PROJECT_NAME lib_1 )
project(${PROJECT_NAME})

# output path
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

# preprocessor define
set( DEFINE "-DLIB_1" )
add_definitions( ${DEFINE} )

# include path
set( INCLUDE_PATH )
include_directories( ${INCLUDE_PATH} )

# library link 
set( LIB_PATH )
link_directories( ${LIB_PATH} )

# main source path
set( SOURCE_PATH ./ )
# source 
set( SOURCE ${SOURCE_PATH}lib_1.cpp )
# head
set( HEAD ${SOURCE_PATH}lib_1.h )
# lib file
add_library( ${PROJECT_NAME} STATIC ${SOURCE} ${HEAD} )