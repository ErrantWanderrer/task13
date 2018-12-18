#include "stdlib.h"
#include "stdio.h"
#include "vector.h"

int main() {
  Vector vector = {0,0,0};
  int N;
  printf("Enter size of array: \n");
  scanf("%d", &N);
  printf("Enter array: \n");

  for(int i = 0; i < N; i++) {
    int t;
    scanf("%d", &t);
    append(&vector, t);
  }

  printf("Interval for delete: 'A' 'B': \n");

  int a, b;
  scanf("%d %d", &a, &b);

  deleteSome(&vector, a, b);
  print(&vector);
 // free(data);
  
  return 0;
} 
