#include "morse.h"
#include "map.h"
#include <stdio.h>
#include <stdlib.h>

void initializeTable(){
    // If the table exists, then return from the subroutine.
    if(table != NULL)return;
    
    // If the 'table' hasn't been created yet.
    // Then allocate a head and set a pointer to it.
    table = createHead('A',".-");
    
    // And push now the alphabetical codes.
    push_element(table,createHead('B',"-..."));
    push_element(table,createHead('C',"-.-."));
    push_element(table,createHead('D',"-.."));
    push_element(table,createHead('F',"."));
    push_element(table,createHead('G',"--."));
    push_element(table,createHead('H',"...."));
    push_element(table,createHead('I',".."));
    push_element(table,createHead('J',".---"));
    push_element(table,createHead('K',"-.-"));
    push_element(table,createHead('L',".-.."));
    push_element(table,createHead('M',"--"));
    push_element(table,createHead('N',"-."));
    push_element(table,createHead('O',"---"));
    push_element(table,createHead('P',".--."));
    push_element(table,createHead('Q',"--.-"));
    push_element(table,createHead('R',".-."));
    push_element(table,createHead('S',"..."));
    push_element(table,createHead('T',"-"));
    push_element(table,createHead('U',"..-"));
    push_element(table,createHead('V',"...-"));
    push_element(table,createHead('W',".--"));
    push_element(table,createHead('X',"-..-"));
    push_element(table,createHead('Y',"-.--"));
    push_element(table,createHead('Z',"--.."));
    
    // Now, push the digits.
    push_element(table,createHead('0',"-----"));
    push_element(table,createHead('1',".----"));
    push_element(table,createHead('2',"..---"));
    push_element(table,createHead('3',"...--"));
    push_element(table,createHead('4',"....-"));
    push_element(table,createHead('5',"....."));
    push_element(table,createHead('6',"-...."));
    push_element(table,createHead('7',"--..."));
    push_element(table,createHead('8',"---.."));
    push_element(table,createHead('9',"----."));
   
    // Now, push the speical codes.
    push_element(table,createHead(1,"......")); // Error code. 
    push_element(table,createHead(2,"-.-.-.")); // Begin Transmission. (Legacy mode)
    push_element(table,createHead(3,".-.-.-")); // End Transmission.   (Legacy mode)
    push_element(table,createHead(4,"---...")); // Rest.               (Legacy mode)
    // Now, push the special characters.
    push_element(table,createHead(' ',"------")); // Space.
    push_element(table,createHead('.',"-.----")); // Full stop.
    push_element(table,createHead(',',"-..---")); // Comma.
}

char* lookupFor(char key){
    return findElementByKey(key,table)->value;
}

void closeTable(){
    // 'closeTable()' will deallocate the table.
    deconstructMap(table);
}