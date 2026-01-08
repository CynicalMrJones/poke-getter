
#ifndef HELPERS_H_
#define HELPERS_H_

typedef struct{
    int stats[6];
    char type[2][15];
} Stats;

void printpoke(char *poke);
char *getjson(char *name);
Stats *getstats(char *parsedjson);


#endif
