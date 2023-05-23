#ifndef MORSE_UTILITAR_INCLUDED
#define MORSE_UTILITAR_INCLUDED

#include "map.h"

// This is where morse translation will happen.

static map_head_t *table;

void initializeTable();
char* lookupFor(char key);
void closeTable();

char* convert2(char* _string);

#endif