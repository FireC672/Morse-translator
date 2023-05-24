#include "morse.h"
#include "map.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// This function will initialize the instance of 'table' (Singleton principle).
void initializeTable(){
    // If the table exists, then return from the subroutine.
    if(table != NULL)return;
    
    // If the 'table' hasn't been created yet.
    // Then allocate a head and set a pointer to it.
    table = createHead('A',".-");
    
    // And push now the alphabetical codes.
    push_element(table,createHead('B',"-...\0"));
    push_element(table,createHead('C',"-.-.\0"));
    push_element(table,createHead('D',"-..\0"));
    push_element(table,createHead('F',".\0"));
    push_element(table,createHead('G',"--.\0"));
    push_element(table,createHead('H',"....\0"));
    push_element(table,createHead('I',"..\0"));
    push_element(table,createHead('J',".---\0"));
    push_element(table,createHead('K',"-.-\0"));
    push_element(table,createHead('L',".-..\0"));
    push_element(table,createHead('M',"--\0"));
    push_element(table,createHead('N',"-.\0"));
    push_element(table,createHead('O',"---\0"));
    push_element(table,createHead('P',".--.\0"));
    push_element(table,createHead('Q',"--.-\0"));
    push_element(table,createHead('R',".-.\0"));
    push_element(table,createHead('S',"...\0"));
    push_element(table,createHead('T',"-\0"));
    push_element(table,createHead('U',"..-\0"));
    push_element(table,createHead('V',"...-\0"));
    push_element(table,createHead('W',".--\0"));
    push_element(table,createHead('X',"-..-\0"));
    push_element(table,createHead('Y',"-.--\0"));
    push_element(table,createHead('Z',"--..\0"));
    
    // Now, push the digits.
    push_element(table,createHead('0',"-----\0"));
    push_element(table,createHead('1',".----\0"));
    push_element(table,createHead('2',"..---\0"));
    push_element(table,createHead('3',"...--\0"));
    push_element(table,createHead('4',"....-\0"));
    push_element(table,createHead('5',".....\0"));
    push_element(table,createHead('6',"-....\0"));
    push_element(table,createHead('7',"--...\0"));
    push_element(table,createHead('8',"---..\0"));
    push_element(table,createHead('9',"----.\0"));
   
    // Now, push the speical codes.
    push_element(table,createHead(1,"......\0")); // Error code. 
    push_element(table,createHead(2,"-.-.-.\0")); // Begin Transmission. (Legacy mode)
    push_element(table,createHead(3,".-.-.-\0")); // End Transmission.   (Legacy mode)
    push_element(table,createHead(4,"---...\0")); // Rest.               (Legacy mode)
    // Now, push the special characters.
    push_element(table,createHead(' ',"------\0")); // Space.
    push_element(table,createHead('.',"-.----\0")); // Full stop.
    push_element(table,createHead(',',"-..---\0")); // Comma.
}

// This function is specifically designed for the 'Morse Table'. 
// If the the 'key' is invalid, then the function will return 'Error Code morse'.
char* lookupFor(char key){
    // Extract the element from the map.
    map_element_t *m = findElementByKey(key,table);
    // If the element doesn't belong to any type in the map.
    // Return an error code morse.
    if(m == NULL)return findElementByKey(1,table)->value;

    // If not, return the value of 'm'.
    return m->value;
}

// This function will destroy the table.
void closeTable(){
    // 'closeTable()' will deallocate the table.
    deconstructMap(table);
}

// This function will convert '_string' to morse equivalence. 
char* convert2(char* _string){
    // 'nIn' is set to the length of '_string'.
    int nIn = strlen(_string);
    
    // 'nOut' is set to the temporary length of 'pOut'.
    int nOut = 2;

    // 'pOut' is a pointer to the output string.
    char* pOut = (char *) malloc(2);
    memset(pOut,0,2);
    
    for(int i = 0; i < nIn; i++){
        // Store the lowered character of '_string' at position i. in 'tch' => Temporary character.
        char tch = toupper(_string[i]);
        // Store the temporary morse code string in 'tMorse'.
        char* tMorse = lookupFor(tch);
        // Store the length of 'tMorse' in 'nMorseLen'.
        int nMorseLen = strlen(tMorse);
        
        // Reallocate 'pOut' to fit in all the characters of 'tMorse'.
        pOut = realloc(pOut,nOut+nMorseLen+1);
        
        // Now, set those characters to 'pOut'.
        for(int j = 0; j < nMorseLen; j++){
            pOut[nOut+j] = tMorse[j];
        }

        // And, increment 'nOut' by 'nMorseLen', to keep track of the actual length.
        nOut += nMorseLen;
    }

    return pOut;
} 