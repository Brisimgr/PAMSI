cmake_minimum_required(VERSION 3.25.3)

project(linkedList)

set(SOURCES src/main.cpp inc/linkedList.hh inc/fileFunctions.hh)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(linkedList PRIVATE inc)


