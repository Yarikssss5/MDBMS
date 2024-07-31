cmake_minimum_required(VERSION 3.28.0)

project(mdbms LANGUAGES C)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} src/main.c)
