cmake_minimum_required(VERSION 3.10)

project(lab1)

add_executable(main main.cpp)

set_target_properties(main PROPERTIES
	CXX_STANDART 14
	CXX_STANDART_REQUIRED ON
	COMPLINE_OPTION "-Wpedantic; -Wall; -Wextra"
	)
