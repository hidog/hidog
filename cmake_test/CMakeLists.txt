cmake_minimum_required(VERSION 2.6)

# Project Name
set( PROJECT_NAME cmake_test )
project(${PROJECT_NAME})

# main source path
set( SOURCE_PATH ./main/ )

# source 
set( SOURCE ${SOURCE_PATH}main.cpp )

# head
set( HEAD )

# exec file
add_executable( ${PROJECT_NAME} ${SOURCE} ${HEAD} )