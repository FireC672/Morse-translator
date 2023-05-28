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
    table = createHead('A',".-/\0");
    
    // And push now the alphabetical codes.
    push_element(table,createHead('B',"-.../\0"));
    push_element(table,createHead('C',"-.-./\0"));
    push_element(table,createHead('D',"-../\0"));
    push_element(table,createHead('F',"./\0"));
    push_element(table,createHead('G',"--./\0"));
    push_element(table,createHead('H',"..../\0"));
    push_element(table,createHead('I',"../\0"));
    push_element(table,createHead('J',".---/\0"));
    push_element(table,createHead('K',"-.-/\0"));
    push_element(table,createHead('L',".-../\0"));
    push_element(table,createHead('M',"--/\0"));
    push_element(table,createHead('N',"-./\0"));
    push_element(table,createHead('O',"---/\0"));
    push_element(table,createHead('P',".--./\0"));
    push_element(table,createHead('Q',"--.-/\0"));
    push_element(table,createHead('R',".-./\0"));
    push_element(table,createHead('S',".../\0"));
    push_element(table,createHead('T',"-/\0"));
    push_element(table,createHead('U',"..-/\0"));
    push_element(table,createHead('V',"...-/\0"));
    push_element(table,createHead('W',".--/\0"));
    push_element(table,createHead('X',"-..-/\0"));
    push_element(table,createHead('Y',"-.--/\0"));
    push_element(table,createHead('Z',"--../\0"));
    
    // Now, push the digits.
    push_element(table,createHead('0',"-----/\0"));
    push_element(table,createHead('1',".----/\0"));
    push_element(table,createHead('2',"..---/\0"));
    push_element(table,createHead('3',"...--/\0"));
    push_element(table,createHead('4',"....-/\0"));
    push_element(table,createHead('5',"...../\0"));
    push_element(table,createHead('6',"-..../\0"));
    push_element(table,createHead('7',"--.../\0"));
    push_element(table,createHead('8',"---../\0"));
    push_element(table,createHead('9',"----./\0"));
   
    // Now, push the speical codes.
    push_element(table,createHead(1,"....../\0")); // Error code. 
    push_element(table,createHead(2,"-.-.-./\0")); // Begin Transmission. (Legacy mode)
    push_element(table,createHead(3,".-.-.-/\0")); // End Transmission.   (Legacy mode)
    push_element(table,createHead(4,"---.../\0")); // Rest.               (Legacy mode)
    // Now, push the special characters.
    push_element(table,createHead(' ',"------/\0")); // Space.
    push_element(table,createHead('.',"-.----/\0")); // Full stop.
    push_element(table,createHead(',',"-..---/\0")); // Comma.
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
// This was implemented using the second solution.
char* convert2(char* _string){
    // 'predictedLength' is the maximum length needed to fit in all the morse characters.
    int predictedLength = 0; 
    // 'nStringLen' is the length of the input '_string'.
    int nStringLen = strlen(_string);
    
    // Now, we are calculating the required size for each character.
    for(int i = 0; i < nStringLen;i++){
       if(_string[i]=='\0')break;
       char *morseC = lookupFor(toupper(_string[i]));
       predictedLength += strlen(morseC);
    }
    
    // Now, that we have the predicted length, we can allocate the required amount safely.
    char *outMorse = malloc(predictedLength+1);
    // Setting all the memory from the initial address until the end to zero.
    memset(outMorse,0,predictedLength+1);
    
    // Now pushing onto 'outMorse' the morse characters.
    for(int i = 0; i < predictedLength+1; i++){
        if(_string[i]=='\0')break;
        // By storing the address of each key-value pair in the pointer 'morseC'.
        char* morseC = lookupFor(toupper(_string[i]));
        // And storing the size of 'morseC'.
        int nMorseC = strlen(morseC);
        
        // To push on the characters correctly.
        for(int j = 0; j < nMorseC; j++){
            outMorse[i+j]=morseC[j];
        }
    }
    
    // Now return the output.
    // Note that even we put invalid characters, we can safely return
    // the correct output.
    return outMorse;
} 

// This function will transform morse instructions into
// readable latin alphanumerical characters.
char *reverse2(char *_string){
    int nStringLength = strlen(_string);
    
    // 'buff' is very important for later.
    char buff[10]; 
    memset(buff,0,10);
    int j = 0;

    for(int i = 0; i < nStringLength; i++){
        buff[j++] = _string[i];
        if(_string[i] == '/'){
            
        }
    }
}