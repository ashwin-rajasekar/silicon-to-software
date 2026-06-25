cmake_minimum_required(VERSION 3.28)

project(embedded-cpp-runtime LANGUAGES CXX)

add_executable(cpp-runtime init.cpp main.cpp)
set_target_properties(cpp-runtime PROPERTIES LINK_DEPENDS ${CMAKE_CURRENT_LIST_DIR}/full_cpp.ld)
target_link_options(cpp-runtime PRIVATE "SHELL:-T '${CMAKE_CURRENT_LIST_DIR}'/full_cpp.ld")

add_custom_target(cpp-runtime.dump
	COMMAND
		arm-none-eabi-objdump -dC cpp-runtime
		-j .vectors
		-j .text
		-j .rodata
		-j .init_array
		-j .fini_array
		-j .bss
		-j .data 
		> cpp-runtime.dump
	DEPENDS cpp-runtime
)
