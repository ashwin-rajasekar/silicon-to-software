set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
string(JOIN " " CMAKE_CXX_FLAGS
	-nostartfiles
	-nostdlib
	-mcpu=cortex-m4
	-mthumb
	-fno-use-cxa-atexit
)
