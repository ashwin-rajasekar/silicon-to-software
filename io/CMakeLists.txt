cmake_minimum_required(VERSION 3.28)

project(embedded-io LANGUAGES CXX)

add_executable(io init.cpp main.cpp)
target_include_directories(io PRIVATE include)
set_target_properties(io PROPERTIES LINK_DEPENDS ${CMAKE_CURRENT_LIST_DIR}/link-io.ld)
target_link_options(io PRIVATE "SHELL:-T '${CMAKE_CURRENT_LIST_DIR}'/link-io.ld")

add_custom_target(io.dump
	COMMAND
		arm-none-eabi-objdump -dC io
		-j .vectors
		-j .text
		-j .rodata
		-j .bss
		-j .data 
		> io.dump
	DEPENDS io
)
