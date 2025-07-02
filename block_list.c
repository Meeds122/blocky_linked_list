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

bool createBlock(List *list){

} // Add a new, empty Block structure in the heap and to the list.

bool deleteBlock(List *list, int block_number){
    
} // Deletes a block identified by block_number. Assumes block identified is last block. 

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
