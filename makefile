
main: src/main.c lib/helpers.h lib/helpers.c
	gcc -o poke-get src/main.c lib/helpers.c lib/cJSON.c -Wall -Wextra -static

install:
	gcc -o poke-get src/main.c lib/helpers.c lib/cJSON.c -Wall -Wextra -static
	sudo mv poke-get /usr/bin/

remove:
	sudo rm /usr/bin/poke-get
