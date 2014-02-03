cmake_policy(VERSION 2.6)


# print message
message("dll test project")
message("cmake source path =" ${CMAKE_SOURCE_DIR} )

# Project Name
set( PROJECT_NAME dlltest )
project(${PROJECT_NAME})

# output path
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

# preprocessor define
set( DEFINE )
if(MSVC)
	set( DEFINE ${DEFINE} -DWIN32 
	                      -DUSE_DLL )
endif(MSVC)
add_definitions( ${DEFINE} )

# include path
set( INCLUDE_PATH ${CMAKE_SOURCE_DIR}/main/src/ )
include_directories( ${INCLUDE_PATH} )

# library link 
set( LIB_PATH )
link_directories( ${LIB_PATH} )

# main source path
set( SOURCE_PATH ${CMAKE_SOURCE_DIR}/dlltest )
# source 
set( SOURCE ${SOURCE_PATH}/dlltest.cpp )
# head
set( HEAD ${SOURCE_PATH}/dlltest.h 
          ${CMAKE_SOURCE_DIR}/main/src/shared.h )
# exec file
add_library( ${PROJECT_NAME} SHARED ${SOURCE} ${HEAD} )
 