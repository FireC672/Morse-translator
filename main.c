#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "morse.h"
#include "map.h"

int main(int argc, char** argv){
    initializeTable();

    for(int i = 0; i < 26; i++){
        int spaceLefts = 7;
        char* lookedUp = lookupFor('A'+i);
        spaceLefts -= strlen(lookedUp);

        printf("%s ", lookedUp);
        for(int j = 0; j < spaceLefts; j++){
            if(j > spaceLefts-2){
                printf("=> ");
                break;
            }
            putchar(' ');
        }
        printf("%c\n",'A'+i);
    }

    closeTable();
    return 0;
}