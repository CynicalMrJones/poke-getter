
main: src/main.c lib/helpers.h lib/helpers.c
	gcc -o main src/main.c lib/helpers.c -Wall -Wextra
