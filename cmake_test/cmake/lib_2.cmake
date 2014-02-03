cmake_minimum_required(VERSION 2.6)

# print message
message("lib_2 project")
message("current path =" ${CMAKE_CURRENT_SOURCE_DIR} )

# Project Name
set( PROJECT_NAME lib_2 )
project(${PROJECT_NAME})

# output path
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

# preprocessor define
set( DEFINE )
add_definitions( ${DEFINE} )

# include path
set( INCLUDE_PATH )
include_directories( ${INCLUDE_PATH} )

# library link 
set( LIB_PATH )
link_directories( ${LIB_PATH} )

# main source path
set( SOURCE_PATH ./lib/ )
# source 
set( SOURCE ${SOURCE_PATH}lib_2.cpp )
# head
set( HEAD ${SOURCE_PATH}lib_2.h )
# exec file
add_library( ${PROJECT_NAME} ${SOURCE} ${HEAD} )

