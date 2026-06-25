#pragma once

#include <cstdint>

struct peripheral_set {
	std::uint32_t WD;
	std::uint32_t TIMER;
	std::uint32_t GPIO;
	std::uint32_t DMA;
	char const reserved0[0x14 - 0x10];
	std::uint32_t HIB;
	std::uint32_t UART;
	std::uint32_t SSI;
	std::uint32_t I2C;
	char const reserved1[0x28 - 0x24];
	std::uint32_t USB;
	char const reserved2[0x34 - 0x2C];
	std::uint32_t CAN;
	std::uint32_t ADC;
	std::uint32_t ACMP;
	std::uint32_t PWM;
	std::uint32_t QEI;
	char const reserved3[0x58 - 0x48];
	std::uint32_t EEPROM;
	std::uint32_t WTIMER;
};

struct system_control_registers {
	std::uint32_t const DID[2];
	char const reserved0[0x030 - 0x008];
	std::uint32_t PBORCTL;
	std::uint32_t const RIS;
	char const reserved1[0x050 - 0x034];
	std::uint32_t IMC;
	std::uint32_t MISC;
	std::uint32_t RESC;
	std::uint32_t RCC;
	char const reserved3[0x06C - 0x064];
	std::uint32_t GPIOHBCTL;
	std::uint32_t RCC2;
	char const reserved4[0x07C - 0x074];
	std::uint32_t MOSCCTL;
	char const reserved5[0x144 - 0x080];
	std::uint32_t DSLPCLKCFG;
	char const reserved6[0x14C - 0x148];
	std::uint32_t const SYSPROP;
	std::uint32_t PIOSCCAL;
	std::uint32_t const PIOSCSTAT;
	char const reserved7[0x160 - 0x158];
	std::uint32_t const PLLFREQ[2];
	std::uint32_t const PLLSTAT;
	char const reserved8[0x188 - 0x16C];
	std::uint32_t SLPPWRCFG;
	std::uint32_t DSLPPWRCFG;
	char const reserved9[0x1B4 - 0x190];
	std::uint32_t LDOSPCTL;
	std::uint32_t const LDOSPCAL;
	std::uint32_t LDODPCTL;
	std::uint32_t const LDODPCAL;
	char const reserved10[0x1CC - 0x1C4];
	std::uint32_t const SPDMST;
	char const reserved11[0x300 - 0x1d0];
	peripheral_set const PP;
	char const reserved12[0x500 - 0x360];
	peripheral_set SR;
	char const reserved13[0x600 - 0x560];
	peripheral_set RCGC;
	char const reserved14[0x700 - 0x660];
	peripheral_set SCGC;
	char const reserved15[0x800 - 0x760];
	peripheral_set DCGC;
	char const reserved16[0xA00 - 0x860];
	peripheral_set const PR;
};

extern volatile system_control_registers SYSCTL;
