using handler_ptr = void(*const)() noexcept;

void trap() noexcept {
		while(true){ asm volatile ("wfi"); }
}

extern char __data_dst[], __bss_dst[];
extern char const __data_src[], __data_end[], __bss_end[];
extern handler_ptr __init_array_begin[], __init_array_end[], __fini_array_begin[], __fini_array_end[];

[[gnu::naked]] void reset() noexcept {
	char const* src = __data_src;
	for(char* dst = __data_dst; dst < __data_end; *dst++ = *src++); 
	for(char* dst = __bss_dst;  dst < __bss_end;  *dst++ = 0);

	for(handler_ptr* ctor = __init_array_begin; ctor != __init_array_end; (*ctor++)());
	extern int main() noexcept;
	main();

	for(handler_ptr* dtor = __fini_array_begin; dtor != __fini_array_end; (*dtor++)());

	trap();
}

[[gnu::section(".vectors"), gnu::used]] handler_ptr vectors[] = {
	reset, trap, trap, trap, trap, trap, nullptr, nullptr,
	nullptr, nullptr, trap, nullptr, nullptr, trap
};