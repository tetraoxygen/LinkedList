cmake_minimum_required(VERSION 3.16)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(LinkedListDemo)

add_executable(LinkedListDemo src/LinkedListDemo.cpp)

set_property(TARGET LinkedListDemo PROPERTY CXX_STANDARD 14)

install(TARGETS LinkedListDemo)

IF (WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	target_link_libraries(LinkedListDemo -static)
ENDIF()