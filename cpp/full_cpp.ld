/** Memory Layout **/
MEMORY {
	flash	(rx) : org = 0x00000000, len = 256K
	ram		(w)  : org = 0x20000000, len = 32K
}

SECTIONS {
	.vectors (READONLY) : {
		LONG(ADDR(.stack) + SIZEOF(.stack));
		KEEP(*(.vectors));
		. = 0x26C;
	} > flash

	.init_array (READONLY) : {
		HIDDEN(__init_array_begin = .);
		KEEP(*(.init_array*));
		HIDDEN(__init_array_end = .);
	} > flash

	.fini_array (READONLY) : {
		HIDDEN(__fini_array_begin = .);
		KEEP(*(.fini_array*));
		HIDDEN(__fini_array_end = .);
	} > flash

	.text   : { *(.text*)   } > flash
	.rodata : { *(.rodata*) } > flash

	.stack  : { . += 4K;    } > ram
	.bss    : { *(.bss*)    } > ram
	.data   : { *(.data*)   } > ram AT > flash

	/DISCARD/ : {
		*(.ARM*)
		*(.comment)
		*(.debug*)
	}
}

HIDDEN(__data_src = LOADADDR(.data));

HIDDEN(__data_dst = ADDR(.data));
HIDDEN(__bss_dst  = ADDR(.bss));

HIDDEN(__data_end = __data_dst + SIZEOF(.data));
HIDDEN(__bss_end  = __bss_dst  + SIZEOF(.bss));
