
project(constexpr_test)

cmake_minimum_required(VERSION 3.16..3.22)

add_executable( ${PROJECT_NAME}
	Source.cpp
)

# No change in 23
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
	add_compile_options(-fsanitize=address)
	add_link_options(-fsanitize=address)
	add_compile_options(-fsanitize=undefined)
	add_link_options(-fsanitize=undefined)
endif()


