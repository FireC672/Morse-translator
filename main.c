#include <stdio.h> 
#include <stdlib.h> 
#include "morse.h"
#include "map.h"

int main(int argc, char** argv){
    initializeTable();

    char* outm = convert2("3D");

    printf("%s",outm);

    free(outm);

    closeTable();
    return 0;
}