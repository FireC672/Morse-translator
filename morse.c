#include "morse.h"
#include "map.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

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

char* lookupFor(char key){
    return findElementByKey(key,table)->value;
}

void closeTable(){
    // 'closeTable()' will deallocate the table.
    deconstructMap(table);
}

// This function will convert '_string' to morse.
char* convert2(char* _string){
    // 'nStringL' holds the length of '_string'.
    int nStringL = strlen(_string);
    
    // Allocate the final output.
    char *pOutMorse = (char *) malloc(1);
    // Track 'pOutMorse' length with 'nMorseLength'.
    int nMorseLength = 1;

    for(int i = 0; i < nStringL; i++){
       // Get the temporary buffer of the 'lookupFor' output,
       // By passing the lowered character at location i in '_string'.
       char* tempbuff = lookupFor(tolower(_string[i]));
       // Hold 'tempbuff' length in 'templ'.
       int templ = strlen(tempbuff);
       // Reallocate 'pOutMorse' to fit in with 'tempbuff' characters.
       pOutMorse = realloc(pOutMorse,nMorseLength+templ);

       for(int j = 0; j < templ; j++){
           // Then from the last index 'nMorseLength-1', go through each character
           // in 'tempbuff', and copy each character to the right location in the final output.
           pOutMorse[nMorseLength-1+j] = tempbuff[j];
       }
       
       // Then increment 'nMorseLength' by 'templ'.
       // NOTE: we incremented 'nMorseLength' after copying, this is because,
       // nMorseLength-1 holds the last index in 'pOutMorse', so incrementing this
       // before copying, will render nMorseLength useless.
       nMorseLength += templ;
    }
    
    // Then set a null-terminator at the end.
    pOutMorse = realloc(pOutMorse,nMorseLength+1);
    pOutMorse[nMorseLength]='\0';
    return pOutMorse;
} 