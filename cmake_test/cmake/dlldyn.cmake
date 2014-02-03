
# print message
message("dll dyn project")
message("current path = " ${CMAKE_CURRENT_SOURCE_DIR} )

# project name
set( PROJECT_NAME dlldyn )
project(${PROJECT_NAME})

# output path
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )

# preprocessor define
set( DEFINE -DUSE_DLL )
if(MSVC)
	set( DEFINE ${DEFINE} -DWIN32 )
endif(MSVC)
add_definitions( ${DEFINE} )

# include path
set( INCLUDE_PATH ${CMAKE_SOURCE_DIR}/dlldyn
                  ${CMAKE_SOURCE_DIR}/main/src )				  
include_directories( ${INCLUDE_PATH} )

# library link
if( _DEBUG )
	set( LIB_PATH ${CMAKE_BINARY_DIR}/lib/Debug )
elseif( _NDEBUG )
	set( LIB_PATH ${CMAKE_BINARY_DIR}/lib/Release )
else()
	set( LIB_PATH ${CMAKE_BINARY_DIR}/lib )
endif(_DEBUG)
link_directories( ${LIB_PATH} )

# main source path
set( SOURCE_PATH ${CMAKE_SOURCE_DIR}/dlldyn )
# source
set( SOURCE ${SOURCE_PATH}/dlldyn.cpp )
# head
set( HEAD ${SOURCE_PATH}/dlldyn.h
          ${CMAKE_SOURCE_DIR}/main/src/shared.h )
# dll file
add_library( ${PROJECT_NAME} MODULE ${SOURCE} ${HEAD} )

