#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "morse.h"
#include "map.h"

unsigned char decodeMode = 0;

int main(int argc, char** argv){
  if(argc < 2){
    printf("\033[31m\033[1merror: \033[0m provide source file.\n");
    return 1;
  }
  FILE *source = fopen(argv[1],"r");
  if(source == NULL){
    printf("\033[31m\033[1merror:\033[0m source file \'%s\' is invalid.\n",argv[1]);
    return 1;
  }

  for(int i = 1; i < argc; i++){
    if(!strcmp(argv[i],"-d") || !strcmp(argv[i],"--decode")){
      decodeMode = 1;
      continue;
    }
    if(!strcmp(argv[i],"-e") || !strcmp(argv[i],"--encode")){
      decodeMode = 0;
      continue;
    }
    
    printf("\033[33m\033[1mwarning: \033[0mbad option \'%s\'.\n",argv[i]);
    return 1;
  }
  
  fseek(source, 0, SEEK_END);
  size_t fileSize = ftell(source);
  rewind(source);

  char *content = (char *)malloc(fileSize);

  {
    char t;
    int i = 0;
    while((t = fgetc(source)) != EOF){
      content[i++] = t;
    }
  }

  initializeTable();
  
  if(decodeMode == 0){
    for(int i = 0; i < fileSize; i++)printf("%s",convert2c(content[i]));
  }else {
    char *out = reverse2(content);
    printf("%s",out);
    free(out);
  }

  putchar('\n');
  
  free(content);
  fclose(source);
  closeTable();
  return 0;
}
