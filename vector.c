#include "assert.h"
#include "stdlib.h"
#include "stdio.h"
#include "vector.h"

void reserve(Vector *vector,size_t newCap) {
    if (newCap > vector->capacity)
    {
        vector->capacity = (vector->capacity == 0) ? 1 : vector->capacity;
        
        while (newCap > vector->capacity)
            vector->capacity <<= 1;
        
        if (vector->data == 0)
            vector->data = (int *)malloc(vector->capacity * sizeof(int));
        else
            vector->data = (int *)realloc((void *)vector->data, vector->capacity * sizeof(int));
    }
}

void append(Vector *vector, int value) {
    reserve(vector, vector->size+1);
    
    vector->data[vector->size] = value; 

    vector->size++;
}

void insert(Vector *vector, size_t pos, int value) {
    assert(pos < vector->size);
    
    reserve(vector, vector->size+1);

    for (int i = vector->size; i > pos; i--)
        vector->data[i] = vector->data[i-1];
    
    vector->data[pos] = value; 
    
    vector->size++;
}

void erase(Vector *vector, size_t pos) {
    assert(pos < vector->size);

    for (int i = pos; i < vector->size; i++)
        vector->data[i] = vector->data[i+1];
    
    vector->size--;
}

void print(Vector *vector) {
    for (int i = 0; i < vector->size; i++)
        printf("%d ", vector->data[i]);

    printf("\n");
}

int indexOf(Vector *vector, int value) {
    for (int i = 0; i < vector->size; i++) {
        if((vector->data[i]) == value) {
            return i;
        }
    }
    return -1;
};



void squeeze(Vector *vector) {
    if (vector->data == 0)
        return;

    if (vector->size == 0)
    {
        free(vector->data);
        return;
    }
    
    vector->data = (int *)realloc((void *)vector->data, vector->size * sizeof(int));
    vector->capacity = vector->size;
}

void deleteSome(Vector *vector, int a, int b) {
  for(int i = 0; i < vector->size;i++){
	  if((vector->data[i] >= a)&&(vector->data[i] <= b)){
		  erase(vector, i);
		  i--;
		  }
	  } 	
}
