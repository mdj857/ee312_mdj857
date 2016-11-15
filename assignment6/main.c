#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define MEM_SIZE 10000				// memsize/4 = # words

void init_heap(char slab[]);
char *my_malloc(char slab[], int numbytes);
void my_free(char slab[], char *p);


int main() {
	
  char slab[MEM_SIZE]= {0}; // Memory that's being used
  init_heap(&slab);
  
}
