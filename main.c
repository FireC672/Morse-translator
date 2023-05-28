#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "morse.h"
#include "map.h"

/*
  TODOs:
    *---> Implement argument parsing.
    *---> Implement the decoding process.
    *---> Probably implement a '--help' function.
    That is all.
*/

int main(int argc, char** argv){
    initializeTable();

    char* reversion = reverse2("-.../\0");
    printf("%s\n",reversion);
    free(reversion);

    closeTable();
    return 0;
}