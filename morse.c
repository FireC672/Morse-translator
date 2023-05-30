#include "morse.h"
#include "map.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/// @brief This function will initialize the instance of 'table' (Singleton principle).
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
    push_element(table,createHead('E',"./\0"));
    push_element(table,createHead('F',"..-./\0"));
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
    push_element(table,createHead(EOF,".-.-.-/\0")); // End Transmission EOF. 
    push_element(table,createHead(3,".-.-.-/\0")); // End Transmission.   (Legacy mode)
    push_element(table,createHead(4,"---.../\0")); // Rest.               (Legacy mode)
    // Now, push the special characters.
    push_element(table,createHead(' ',"------/\0")); // Space.
    push_element(table,createHead('.',"-.----/\0")); // Full stop.
    push_element(table,createHead(',',"-..---/\0")); // Comma.
}

/// @brief This function is specifically designed for the 'Morse Table'. 
/// @brief If the the 'key' is invalid, then the function will return 'Error Code morse'.
/// @param key Is the character to lookup for.
/// @return The correct morse instruction, (If 'key' is invalid, then it will return the error code);
char* lookupFor(char key){
    // Extract the element from the map.
    map_element_t *m = findElementByKey(key,table);
    // If the element doesn't belong to any type in the map.
    // Return an error code morse.
    if(m == NULL)return findElementByKey(1,table)->value;

    // If not, return the value of 'm'.
    return m->value;
}

/// @brief This function destroyes the morse code conversion table.
void closeTable(){
    // 'closeTable()' will deallocate the table.
    deconstructMap(table);
}

/// @brief This function will convert '_string' to morse equivalence. 
/// @brief This was implemented using the second solution.
/// @param _string The input string. (Assuming it is a normal string).
/// @return A string as morse code instructions that make up the '_string'.
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


/// @brief This function will transform morse instructions into
/// @brief readable latin alphanumerical characters.
/// @param _string The input string (Assuming it is morse code).
/// @return The characters that make up the morse code.
char *reverse2(char *_string){
    int nStringLength = strlen(_string);
    // We are going to pre-calculate the output size.
    int nOutputLength = 0;
    
    // Pre-calculating the size of the output.
    for(int i = 0; i < nStringLength; i++)
       if(_string[i] == '/')
          nOutputLength++;
    
    // Now allocate 'output' with the pre-calculated length.
    char* output = malloc(nOutputLength+1);
    // Nullize or nullify the output.
    memset(output,0,nOutputLength+1);

    // 'buff' is very important for later.
    // 'buff' is the array that hold the temporary morse code.
    char buff[10]; 
    // Now, nullize / nullify this buffer.
    memset(buff,0,10);
    
    // 'j' is the index serving for 'buff'.
    int j = 0;
    // 'k' is for the output.
    int k = 0; 
    
    // Now, loop through each characters in '_string'
    for(int i = 0; i < nStringLength; i++){
        // And set the character at 'i' in '_string' to buff in location j.
        // After setting the character, increment j.
        buff[j++] = _string[i];
        // If we reach '/', then we can use our buffer to do the conversion.
        if(_string[i] == '/'){
            // Here, we set a pointer 'e' to the 
            // element in the table with the correct value.
            map_element_t *e = findElementByValue(buff,table);
            // And push e's key at k+1 position in the string output.
            output[k++] = e->key;
            // Now clear the buffer 'buff'.
            memset(buff,0,10);
            // And reset 'j'.
            j=0;
        }
    }

    return output;
}

char *convert2c(char tok){
    return lookupFor(toupper(tok));
}