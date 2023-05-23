#include <stdio.h> 
#include <stdlib.h> 
#include "morse.h"
#include "map.h"

int main(int argc, char** argv){
    map_head_t* head = initializeTable();
    push_element(head, createHead('B',"Hello"));
    map_element_t* p = findElementByKey('A',head);

    printf("%s",p->value);

    deconstructMap(head);
    return 0;
}