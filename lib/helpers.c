
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "cJSON.h"

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
    fclose(fptr);
}

char *getjson(char *name){
    //TODO: Works with regular pokemon but not mega's 
    //The json isnt filled
    char command[300];
    int size = INT_MAX / 2;
    sprintf(command, "curl -s https://pokeapi.co/api/v2/pokemon/%s", name);
    FILE *pipe = popen(command, "r");
    char *line = malloc(sizeof(char) * size);
    if (line == NULL){
        printf("[ERROR]: Could not malloc 2gb\n");
        exit(0);
    }
    //Its something here
    while (fgets(line, size, pipe) != NULL);
    pclose(pipe);
    return line;
}

int *getstats(char *parsedjson){
    cJSON *parsedfile = cJSON_Parse(parsedjson);
    cJSON *name = NULL;
    cJSON *stats = NULL;
    cJSON *stat = NULL;
    int *finalstat = malloc(sizeof(int) * 6);
    int num = 0;
    name = cJSON_GetObjectItemCaseSensitive(parsedfile, "name");
    if (cJSON_IsString(name) && (name->valuestring != NULL)){
        printf("%s\n", name->valuestring);
    }
    stats = cJSON_GetObjectItemCaseSensitive(parsedfile, "stats");
    cJSON_ArrayForEach(stat, stats){
        cJSON *base_stat = cJSON_GetObjectItemCaseSensitive(stat, "base_stat");
        finalstat[num] = base_stat->valueint;
        num += 1;
    }
    cJSON_Delete(parsedfile);
    cJSON_free(name);
    cJSON_free(stats);
    cJSON_free(stat);
    return finalstat;
}
