#include <stdbool.h>

#define BLOCKSIZE 1000

typedef struct Element Element;
typedef struct Block Block;
typedef struct List List;

// ----------------
// Public Interface
// ----------------

List initList(); // Returns a new List structure.

bool destroyList(List *list); // Destroys a List. Returns true if successful and false if not. 

bool appendElement(List *list, Element element); // Appends the element to the list. Returns true if successful and false if not. 

Element getElement(List *list, int element_id); // Returns an Element of the Element at element_id.


// -----------------
// Private Interface
// -----------------

bool createBlock(List *list); // Add a new, empty Block structure in the heap and to the list.
bool deleteBlock(List *list, int block_number); // Deletes a block identified by block_number. Assumes block identified is last block. 
bool isBlockRequired(List *list); // Returns true if the last block is full. 

// ----------
// Structures
// ----------

struct Element{
    int value;
};

struct Block{
    struct Element elements[BLOCKSIZE];

    int block_number;
    bool is_first;
    bool is_last;
    struct Block *next_block;
    struct Block *previous_block;
};

struct List {
    int length;

    int blocks;
    
    struct Block *first_block;
    struct Block *last_block;
};
