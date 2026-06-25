#pragma once

#include <cstdint>

struct gpio_registers {
	std::uint32_t DATA[0x400 >> 2];
	std::uint32_t DIR;
	std::uint32_t IS;
	std::uint32_t IBE;
	std::uint32_t IEV;
	std::uint32_t IM;
	std::uint32_t RIS;
	std::uint32_t MIS;
	std::uint32_t CS;
	std::uint32_t AFSEL;
	char const reserved0[0x500 - 0x424];
	std::uint32_t DR2R;
	std::uint32_t DR4R;
	std::uint32_t DR8R;
	std::uint32_t ODR;
	std::uint32_t PUR;
	std::uint32_t PDR;
	std::uint32_t SLR;
	std::uint32_t DEN;
	std::uint32_t LOCK;
	std::uint32_t CR;
	std::uint32_t AMSEL;
	std::uint32_t PCTL;
	std::uint32_t ADCCTL;
	std::uint32_t DMACTL;
};

extern volatile gpio_registers GPIOF;
