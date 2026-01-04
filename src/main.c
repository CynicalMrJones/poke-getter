
#include <stdio.h>
#include <stdlib.h>
#include "../lib/helpers.h"


int main(int argc, char **argv){
    //TODO: Add types to presentation
    //TODO: Add weaknesses
    if (argc < 2){
        printf("Please give a pokemon\n");
        exit(0);
    }
    char command[15];
    sprintf(command, "pokes/%s", argv[1]);
    printpoke(command);
    char *json = getjson(argv[1]);
    int *stats = getstats(json);
    char stat_names[6][15] = {"hp", "attack", "defense", "spec-att", "spec-def", "speed"};
    for (int i = 0; i < 6; i++){
        printf("%s: %d\n", stat_names[i], stats[i]);
    }
    free(json);
    free(stats);
}
