%:
	cd $(shell fd -F $@.cpp -x dirname) && \
	g++ -ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror -std=c++2c -o $@.exe $@.cpp && \
	realpath.exe "$@.exe" | clip

cleanup:
	fd -g *.exe -x rm
