#include <stdlib.h>
#include <stdbool.h>

#include "block_list.h"

// [!] If you are here, you are in the wrong place. Check the headers for the public interface functions and USE THEM. 

// ---------------------
// Public Interface Code
// ---------------------

List initList(){
    List l;
    l.blocks = 0;
    l.length = 0;
    l.first_block = NULL;
    l.last_block = NULL;

    return l;
} // Returns a List structure.

bool destroyList(List *list){

} // Destroys a List. Returns true if successful and false if not. 

bool appendElement(List *list, Element element){

} // Appends the element to the list. Returns true if successful and false if not. 

Element getElement(List *list, int element_id){

} // Returns an Element of the Element at element_id.

// ----------------------
// Private interface code
// ----------------------

Block *createBlock(){

} // Add a new, empty Block structure in the heap and returns the pointer to it. 

bool deleteBlock(Block *block){
    
} // Frees the memory pointed to by block. Returns true if succesful or false if error. 

bool isBlockRequired(List *list){
    int free_elements = (list->blocks * BLOCKSIZE) - list->length; // free_elements = total_elements - consumed_consumed elements
    if(free_elements > 0){
        return false;
    }
    else if (free_elements == 0){
        return true;
    }
    else {
        // Here be undefined behaviour, beware!
        return true;
    }
} // returns true if last block is full. 
