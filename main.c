#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "morse.h"
#include "map.h"

int main(int argc, char** argv){
    initializeTable();

    char* converted = convert2("ABC");
    printf("%s",converted);
    free(converted);

    closeTable();
    return 0;
}