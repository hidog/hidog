#cmake_minimum_required(VERSION 2.6)
#cmake_policy(VERSION 2.6)

# print message
message("math fraction")
message("current path =" ${CMAKE_CURRENT_SOURCE_DIR} )

# Project Name
set( PROJECT_NAME math_fraction )
project(${PROJECT_NAME})

# output path
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

# preprocessor define
set( DEFINE )
add_definitions( ${DEFINE} )

# include path
set( INCLUDE_PATH ${CMAKE_SOURCE_DIR}/src
				  ${CMAKE_SOURCE_DIR}/src/math )
include_directories( ${INCLUDE_PATH} )

# source 
set( SOURCE ${CMAKE_SOURCE_DIR}/src/math/fraction.cpp
            ${CMAKE_SOURCE_DIR}/src/shared.cpp )
# head
set( HEAD ${CMAKE_SOURCE_DIR}/src/math/fraction.h
          ${CMAKE_SOURCE_DIR}/src/shared.h )
		  
# lib file
add_library( ${PROJECT_NAME} STATIC ${SOURCE} ${HEAD} )

