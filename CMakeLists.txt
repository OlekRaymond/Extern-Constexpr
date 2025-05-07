
project(constexpr_test)

cmake_minimum_required(VERSION 3.22)

add_executable( ${PROJECT_NAME}
	Source.cpp
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 23)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})



