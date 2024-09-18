debug_args := -ggdb

ifeq ($(OS),Windows_NT)     # is Windows_NT on XP, 2000, 7, Vista, 10...
	detected_OS := Windows
	suffix := .exe
	clean_CMD := fd -g *$(suffix) -X rm
	debug_TOOL := drmemory -brief -batch --
	debug_args = $(debug_args) -m32 -fno-inline -fno-omit-frame-pointer -static-libgcc -static-libstdc++
else
	detected_OS := $(shell uname)  # same as "uname -s"
	clean_CMD := find . -name .git -prune , \( -type f -executable -o -name .gdb_history \) -exec rm {} \;
	debug_TOOL := valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes --
endif

disable_extension := -pedantic-errors
warn_level := -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion
warn_shadow := -Wshadow
warn_conversion := -Wconversion
warn_as_error := -Werror
std_26 := -std=c++2c
std_23 := -std=c++2b

CXX = g++
CXXFLAGS = $(debug_args) $(disable_extension) $(warn_level) $(warn_shadow) \
	$(warn_conversion) $(warn_as_error) $(std_23)

default_compile := $(CXX) $(CXXFLAGS)

.PHONY: cur clean

cur:
	file=$$(emacsclient -e "(file-relative-name (buffer-local-value 'buffer-file-name (window-buffer (selected-window))))") && \
	nosuffix=$${file:1:-6} && \
	outfile=$${nosuffix}$(suffix) && \
	$(default_compile) -o $${outfile} $${nosuffix}*.cpp && \
	emacsclient -e "(kill-new (concat \"$(debug_TOOL) \" (expand-file-name \"$${outfile}\")))"

clean:
	$(clean_CMD)
