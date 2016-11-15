/*
Matthew Johnson 
EID: mdj857 
EE 312 Assignment 6 


NOTE: My solution is incomplete. I have provided my algorithm for the malloc function,
and pseudocode for free() for review and partial credit. 
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>




//Initialize the starting point of the array
void init_heap(char heap[]){
	
	 (heap[9991]) = 2496;				// metadata for thw beginning of the heap 
	 (heap[0]) = 2496;					// metadata for the end of heap
	
}

//Allocate requested memory
char *my_malloc(char heap[], int numbytes) {
  printf("My malloc called\n");
  
  long long *findMetadata = &heap[2491];	// declare pointer to find first instance of metadata

  while (*findMetadata < 0 || (abs(*findMetadata) <= ceil((double)numbytes/4))) {
	  
	  findMetadata = findMetadata - (int)abs((*(findMetadata))) - 1;
  }
 
  // at this point, findMetadata points to first "free" block of metadata that can contain the amount of bytes (to the value of metadata itself)
  long long oldMetadata = *findMetadata;					// grab original metadata in selected block
  long long newMetadata = -ceil((double)(numbytes / 4));	// negative for used 
  *findMetadata = newMetadata;							// updates lower metadata with new storage amount
  findMetadata--;										// findmetadata now points to data block
  char *toReturn = (char*)(findMetadata ) + 1;			// this is the pointer we want to return. 
  //printf("Address returned: %p\n", toReturn);
  findMetadata =(int*)(findMetadata) + (abs(newMetadata));	// findMetadata now points to top metadata of allocated memory 
  //printf("Address of bottom metadata tag of new block: %p", findMetadata);
  *(long long*)findMetadata = newMetadata;				// update top metadata with new storage amount, convert findMetaData back to 2-word type
  //printf("Heap[12] = %d\n", heap[12]);

  // code to change metadata tags for split block 
  long long numWordsOfRest = oldMetadata - abs(newMetadata) - 4; // four for num words of metadata encapsulation
  if (numWordsOfRest > 0) {
	  findMetadata--;									    // second part of partitioned block
	  *findMetadata = numWordsOfRest;						// update bottom part of restOf block
	  //printf("Address of findMetaData after allocating second space (bottom of split block): %p. Value: %d\n", findMetadata, *findMetadata);
	  findMetadata--;									// points to data of second realloc block
	  findMetadata = (int*)(findMetadata) -  numWordsOfRest - 1;		// move pointer up to "top" of restOf block 
	  *findMetadata = numWordsOfRest;						// store new metadata in top of restOf block
	  //printf("Address of findMetaData at top of new block: %p Value: %d\n", findMetadata, *findMetadata);
  }
  
  if (toReturn == NULL) {
	  printf("Sorry nothing is available!\n");
  }
  return toReturn;
}

//Deallocate requested memory
void my_free(char slab[], char *p) {

  /*****************************
	Pseudocode: 
	Check metadata of data pointed to by p. 
		-if < 0, return error
		-else: 
		p = p--; // bottom block, make top metadata positive 
		bottom = p;		// temp
		p = p+*p // make top metadata tag positive 
		top = q;	// TEMP


	check if blocks can be collapsed. 
	move top and bottom pointers up and down until one reaches either out-of-bounds or metadata tags. 
		-if metadata tags found, change original metadata 
				-collapse(top, bottom); 
		-continue (while loop) until p reaches end of heap in either direction. 

		return. 
  *****************************/

}
