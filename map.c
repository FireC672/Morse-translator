#include "map.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>


map_head_t* createHead(int _key, char* _value){
    // Allocate a 'head' in the heap, and set a pointer to it.
    map_head_t *head = (map_head_t *) malloc(sizeof(map_head_t));
    // Get the length of '_value'.
    int valueLen = strlen(_value);
    
    // Set 'head key' to '_key'.
    head->key = _key;
    
    // Then allocate head's value, and set a pointer to it.
    head->value = (char *) malloc(valueLen+1);
    // Copy '_value''s content to head's value.
    memcpy(head->value,_value,valueLen);
    // And set the last byte to zero.
    head->value[valueLen] = '\0';

    return head;
}

int push_element(map_head_t* h, map_element_t* elem){
    // If the 'head' is a null-object or the element is a null-object, then don't bother.
    if(h == NULL || elem == NULL)return 1; 
    
    // If there are no next element.
    if(h->next == NULL){
        // Then set 'next' to 'elem'.
        h->next = elem;
        return 0;
    }

    // If not, then loop until the front of the map, and push.
    map_element_t* cursor = h; 
    while(cursor->next != NULL)cursor = cursor->next; 
    cursor->next = elem;
    // The reason we return an integer type, is to know if we did something wrong.
    return 0;
}


map_element_t* findElementByKey(int _key, map_head_t *head){
    // If there are not 'head', then return NULL (0).
    if(head == NULL)return NULL;
    // If there are no next elements, then return the head.
    if(head->next == NULL)return head;
    
    // Set a pointer 'cursor' to head.
    map_element_t* cursor = head;
    while(cursor->next != NULL){
        // Loop through each key, and compare.
        // If the comparaison is true, then raise the cursor, and return it.
        if(cursor->key == _key)return cursor; 
        // If not, continue until the end.
        cursor = cursor->next;
    }
    // If we didn't found any elements, then return NULL.
    return NULL;
}

void deconstructMap(map_head_t* head){
    
    // If the 'head' doesn't have a element next to it, then don't bother doing the loop.
    if(head->next == NULL){
        free(head);
        if(head->value != NULL)
            free(head->value);
        return; 
    }

    // We set a pointer 'cursor' to the head.
    map_element_t* cursor = head; 
    // And a pointer that points to the last cursor position.
    map_element_t* previous = head; 
    

    // While we don't reach the end of the map.
    while (cursor->next != NULL)
    {
       // We set 'previous' to 'cursor' address.
       previous = cursor; 
       // And move cursor to the next element.
       cursor = cursor->next;
       
       // And freeup the memory allocated by the previous element.
       free(previous);
       free(previous->value);
    }

    // Then free the last element.
    free(cursor);
    free(cursor->value);
}
