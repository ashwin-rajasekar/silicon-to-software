#include <cstdint>
#include <utility>

// these headers would normally come from the SDK of the platform,
// but you can write your own based on the datasheet
#include "gpio.hpp"
#include "system_control.hpp"
#include "sys_tick.hpp"

enum color : std::uint32_t {
	off    = 0,
	red    = 2,
	blue   = 4,
	purple = 6,
	green  = 8,
	yellow = 10,
	cyan   = 12,
	white  = 14
};

std::uint32_t volatile& led_color = GPIOF.DATA[0b0'111'0];

std::pair<bool, bool> get_switches(){
	auto const data = GPIOF.DATA[0b1'000'1];
	return {!(data & 0b1'000'0), !(data & 0b0'000'1)};
}

void portf_init() noexcept {
	SYSCTL.RCGC.GPIO |= 0x20;
	while(!(SYSCTL.PR.GPIO & 0x20));
	static constexpr auto mask = 0b1'111'1;
	GPIOF.LOCK = 0x4C4F434B;
	GPIOF.CR |= mask;
	GPIOF.AFSEL &= ~mask;
	GPIOF.PUR |= 0b1'000'1;
	GPIOF.DIR = (GPIOF.DIR & ~mask) | 0b0'111'0;
	GPIOF.PCTL &= ~0xF'FFF'F;
	GPIOF.DEN |= mask;
}

void systick_init() noexcept {
	SYSTICK.RELOAD = 16'000'000; // 1s @ 16MHz
	SYSTICK.CTRL = 7;
}

void systick_handler() noexcept {
	// Check the state of the buttons once per second and cycle through colors
	auto const switches = get_switches();

	if(switches.first){
		led_color += 2;
	} else if(switches.second){
		led_color -= 2;
	}
}

int main() noexcept {
	portf_init();
	systick_init();
	led_color = color::red;

	// main returns, but that's ok because we trap in reset()
}
