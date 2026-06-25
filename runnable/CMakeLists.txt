cmake_minimum_required(VERSION 3.28)

project(embedded-runnable LANGUAGES CXX)

add_executable(runnable runnable.cpp)
set_target_properties(runnable PROPERTIES LINK_DEPENDS ${CMAKE_CURRENT_LIST_DIR}/link-basic.ld)
target_link_options(runnable PRIVATE "SHELL:-T ${CMAKE_CURRENT_LIST_DIR}/link-basic.ld")

add_custom_target(runnable.dump
	COMMAND
		arm-none-eabi-objdump -dC runnable
		-j .vectors
		-j .text
		-j .rodata
		-j .bss
		-j .data
		> runnable.dump
	DEPENDS runnable
)
