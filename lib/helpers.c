
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "cJSON.h"
#include "helpers.h"

void printpoke(char *poke){
    FILE *fptr = fopen(poke, "r");
    if (fptr == NULL){
        printf("Cannot find image named %s\n", poke);
    }
    else {
        char buff[1000];
        while(fgets(buff, sizeof(buff), fptr) != NULL){
            printf("%s", buff);
        }
        fclose(fptr);
    }
}

char *getjson(char *name){
    char command[300];
    int size = INT_MAX / 2;
    sprintf(command, "curl -s https://pokeapi.co/api/v2/pokemon/%s", name);
    FILE *pipe = popen(command, "r");
    char *line = malloc(sizeof(char) * size);
    if (line == NULL){
        printf("[ERROR]: Could not malloc 1gb\n");
        exit(0);
    }
    while (fgets(line, size, pipe) != NULL);
    pclose(pipe);
    if (strcmp(line, "Not Found") == 0){
        printf("There is no pokemon named: %s\n", name);
        exit(0);
    }
    return line;
}

Stats *getstats(char *parsedjson){
    cJSON *parsedfile = cJSON_Parse(parsedjson);
    cJSON *name = NULL;
    cJSON *stats = NULL;
    cJSON *stat = NULL;
    cJSON *types = NULL;
    cJSON *type = NULL;
    Stats *finalstat = malloc(sizeof(Stats) * 1);
    int num = 0;
    name = cJSON_GetObjectItemCaseSensitive(parsedfile, "name");
    if (cJSON_IsString(name) && (name->valuestring != NULL)){
        printf("%s\n", name->valuestring);
    }
    stats = cJSON_GetObjectItemCaseSensitive(parsedfile, "stats");
    cJSON_ArrayForEach(stat, stats){
        cJSON *base_stat = cJSON_GetObjectItemCaseSensitive(stat, "base_stat");
        finalstat->stats[num] = base_stat->valueint;
        num += 1;
    }
    num = 0;
    types = cJSON_GetObjectItemCaseSensitive(parsedfile, "types");
    // There is definitly a simpler way to do this but this works
    cJSON_ArrayForEach(type, types){
        cJSON *typearr= cJSON_GetObjectItemCaseSensitive(type, "type");
        cJSON *type_name = cJSON_GetObjectItemCaseSensitive(typearr, "name");
        strcpy(finalstat->type[num], type_name->valuestring);
        num += 1;
    }
    cJSON_Delete(parsedfile);
    cJSON_free(name);
    cJSON_free(stats);
    cJSON_free(stat);
    cJSON_free(types);
    cJSON_free(type);
    return finalstat;
}
