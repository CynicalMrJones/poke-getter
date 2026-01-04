
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/helpers.h"
#include "../lib/cJSON.h"


int main(int argc, char **argv){
    printpoke("pokes/abomb");
    char *test = getjson("ditto");
    printf("%s\n", test);
}
