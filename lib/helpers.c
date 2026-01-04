
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printpoke(char *poke){
    FILE *fptr = fopen(poke, "r");
    if (fptr == NULL){
        printf("There is no poke named %s\n", poke);
        exit(0);
    }
    char buff[1000];
    while(fgets(buff, sizeof(buff), fptr) != NULL){
        printf("%s", buff);
    }
}

char *getjson(char *name){
    char command[100];
    int size = INT_MAX;
    sprintf(command, "curl -s https://pokeapi.co/api/v2/pokemon/%s", name);
    FILE *pipe = popen(command, "r");
    char *line = malloc(sizeof(char) * size);
    while (fgets(line, size, pipe) != NULL);
    return line;
}
