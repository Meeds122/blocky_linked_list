#include <stdio.h>
#include <stdlib.h>

#include "block_list.h"

// Tests
// Each test returns true if passed. 

bool testBlockSize(){
    if(BLOCKSIZE < 6)
        return false;
    else
        return true;
}

bool testInitList(){
    List l = initList();
    if(l.blocks != 0){
        return false;
    }
    else if(l.length != 0){
        return false;
    }
    else if(l.first_block != NULL){
        return false;
    }
    else if(l.last_block != NULL){
        return false;
    }
    return true;
}

bool testIsBlockRequired(){
    List l = initList();
    // There should be no blocks, therefore block is required. 
    if(isBlockRequired(&l) != true)
        return false;
    // Let's pretend there is a block and 1/2 of the block is filled with items. 
    l.blocks = 1;
    l.length = BLOCKSIZE / 2; // Integer divsion in C always rounds down to the nearest integer. 
    // There should still be space in the block 
    if(isBlockRequired(&l) != false)
        return false;
    // Let's pretend there is a block and all of the block is filled
    l.blocks = 1;
    l.length = BLOCKSIZE;
    // There should be no more space in the block
    if(isBlockRequired(&l) != true)
        return false;
    
    // Let's pretend there is more than one block and 1/2 of the last block is filled with items. 
    l.blocks = 4;
    l.length = (BLOCKSIZE * 3) + (BLOCKSIZE / 2); // Integer divsion in C always rounds down to the nearest integer. 
    // There should still be space in the block 
    if(isBlockRequired(&l) != false)
        return false;
    // Let's pretend there is more than one block and all of the last block is filled
    l.blocks = 4;
    l.length = BLOCKSIZE * 4;
    // There should be no more space in the block
    if(isBlockRequired(&l) != true)
        return false;
    // All cases passed
    return true;
}

bool testCreateBlock(){
    Block *b = createBlock();
    if (b == NULL){
        return false;
    }
    else{
        free(b);
        return true;
    }
}

int main(){
    
    printf("[INFO] Testing Public Interfaces\n");

    if(testBlockSize())
        printf("[ OK ] BLOCKSIZE\n");
    else
        printf("[FAIL] BLOCKSIZE\n");

    if(testInitList())
        printf("[ OK ] initList()\n");
    else
        printf("[FAIL] initList()\n");
    
    
    printf("[INFO] Testing Private Interfaces\n");

    if(testIsBlockRequired())
        printf("[ OK ] isBlockRequired()\n");
    else
        printf("[FAIL] isBlockRequired()\n");    

    if(testCreateBlock())
        printf("[ OK ] createBlock()\n");
    else
        printf("[FAIL] createBlock()\n"); 
    
    printf("[EXPLORATION]\n");
    printf("Size of List: %ld\n", sizeof(List));
    printf("Size of Element: %ld\n", sizeof(Element));
    printf("Size of Block: %ld\n", sizeof(Block));

    return 0;
}