#ifndef MAP_UTILITAR_INCLUDED 
#define MAP_UTILITAR_INCLUDED 

// This is for hashmaps.

typedef struct map{
  int key; 
  char* value;
  struct map* next;

} map_element_t;

typedef map_element_t map_head_t; 

map_head_t* createHead(int _key, char* _value);
int push_element(map_head_t* h, map_element_t* elem);
map_element_t* findElementByKey(int _key, map_head_t *head);
void deconstructMap(map_head_t* head);

#endif 