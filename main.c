#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "morse.h"
#include "map.h"


int main(int argc, char** argv){
  if(argc < 1){
    printf("\033[31m\033[1merror: \033[0m provide source file.\n");
    return 1;
  }
  FILE *source = fopen(argv[1],"r");
  if(source == NULL){
    printf("\033[31m\033[1merror:\033[0m source file \'%s\' is invalid.\n",argv[1]);
    return 1;
  }
  
  initializeTable();

  fseek(source,0,SEEK_END);
  size_t nFileSize = ftell(source);
  rewind(source);

  char t = 0;
  while(t = fgetc(source)){
    char *morseInstruction = convert2(t);
    printf("%s",morseInstruction);
  }

  fclose(source);
  closeTable();
  return 0;
}
