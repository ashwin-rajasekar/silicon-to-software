cmake_minimum_required(VERSION 3.28)

project(silicon-to-software LANGUAGES CXX)

add_executable(trivial trivial.cpp)
add_custom_target(trivial.dump
	COMMAND arm-none-eabi-objdump -dC trivial > trivial.dump
	DEPENDS trivial
)
