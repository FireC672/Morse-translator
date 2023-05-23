#include "morse.h"
#include "map.h"
#include <stdio.h>
#include <stdlib.h>

map_head_t* initializeTable(){
    map_head_t* element1 = createHead('A',".-");
    return element1;
}

void deinitializeTable();