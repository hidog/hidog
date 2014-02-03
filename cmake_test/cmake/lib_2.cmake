#cmake_minimum_required(VERSION 2.6)
#cmake_policy(VERSION 2.6)

# sub project
include(${CMAKE_SOURCE_DIR}/cmake/lib_3.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/lib_4.cmake)

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
set( INCLUDE_PATH ${CMAKE_SOURCE_DIR}/lib/src )
include_directories( ${INCLUDE_PATH} )

# library link 
if( _DEBUG )
	set( LIB_PATH ${CMAKE_BINARY_DIR}/lib/Debug )
elseif( _NDEBUG )
	set( LIB_PATH ${CMAKE_BINARY_DIR}/lib/Release )
else()
	set( LIB_PATH ${CMAKE_BINARY_DIR}/lib )
endif( _DEBUG )
link_directories( ${LIB_PATH} )

# main source path
set( SOURCE_PATH ${CMAKE_SOURCE_DIR}/lib )
# source 
set( SOURCE ${SOURCE_PATH}/lib_2.cpp )
# head
set( HEAD ${SOURCE_PATH}/lib_2.h )
# exec file
add_library( ${PROJECT_NAME} ${SOURCE} ${HEAD} )
target_link_libraries( ${PROJECT_NAME} lib_3 lib_4 )   # 未來改成用迴圈方式
