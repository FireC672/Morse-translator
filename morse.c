#include "morse.h"
#include "map.h"
#include <stdio.h>
#include <stdlib.h>

map_head_t* initializeTable(){
    map_head_t* tableHead = createHead('A',".-");
    push_element(tableHead,createHead('B',"-..."));
    return tableHead;
}

void deinitializeTable();