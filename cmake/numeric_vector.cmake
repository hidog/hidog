#cmake_minimum_required(VERSION 2.6)
#cmake_policy(VERSION 2.6)

# print message
message("numeric vector")
message("current path =" ${CMAKE_CURRENT_SOURCE_DIR} )

# Project Name
set( PROJECT_NAME numeric_vector )
project(${PROJECT_NAME})

# output path
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

# preprocessor define
set( DEFINE )
add_definitions( ${DEFINE} )

# include path
set( INCLUDE_PATH ${CMAKE_SOURCE_DIR}/src
				  ${CMAKE_SOURCE_DIR}/src/numeric )
include_directories( ${INCLUDE_PATH} )

# source 
set( SOURCE ${CMAKE_SOURCE_DIR}/src/numeric/vector.cpp
            ${CMAKE_SOURCE_DIR}/src/shared.cpp )
# head
set( HEAD ${CMAKE_SOURCE_DIR}/src/numeric/vector.h
          ${CMAKE_SOURCE_DIR}/src/shared.h )
		  
# lib file
add_library( ${PROJECT_NAME} STATIC ${SOURCE} ${HEAD} )

