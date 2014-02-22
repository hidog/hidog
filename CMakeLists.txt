cmake_minimum_required(VERSION 2.6)

# sub project
include(${CMAKE_SOURCE_DIR}/cmake/numeric_vector.cmake)

# print message
message("cmake test project")
message("root path =" ${CMAKE_SOURCE_DIR} )

# Project Name
set( PROJECT_NAME hidog )
project(${PROJECT_NAME})

# output path
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )

# preprocessor define
set( DEFINE -DHIDOG_DEFINE )
if( MSVC )
	message("define MSVC")
	set( DEFINE ${DEFINE} -DMSVC 
	                      -DWIN32 )
elseif( XCODE )
	message("define xcode")
	set( DEFINE ${DEFINE} -DMACOS )
elseif( UNIX )
        message("define unix")
        set( DEFINE ${DEFINE} -DUNIX )
endif( MSVC )
add_definitions( ${DEFINE} )

# include path
set( INCLUDE_PATH ${CMAKE_SOURCE_DIR}/src
                  ${CMAKE_SOURCE_DIR}/src/numeric )
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

# source 
set( SOURCE main.cpp )

# exec file
add_executable( ${PROJECT_NAME} ${SOURCE} )
target_link_libraries( ${PROJECT_NAME} numeric_vector )   # 未來改成用迴圈方式
