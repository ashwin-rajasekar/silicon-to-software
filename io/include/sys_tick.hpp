#pragma once

#include <cstdint>

struct systick_registers {
	std::uint32_t CTRL;
	std::uint32_t RELOAD;
	std::uint32_t CURRENT;
	std::uint32_t const CALIB;
};

extern volatile systick_registers SYSTICK;
