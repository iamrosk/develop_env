#include <stdio.h>
#include <stdlib.h>

int main()
{
  #define SIZE 10
  
  int * asentries = (int*) malloc(sizeof(int) * SIZE*SIZE);
  int ** as = (int**) malloc(sizeof(int*) * SIZE);
  for ( size_t ix = 0, jx = 0; ix < SIZE; ++ix, jx+=SIZE )
    as[ix] = asentries + jx;
  
  for ( size_t ix = 0; ix < SIZE; ++ix )
    for ( size_t jx = 0; jx < SIZE; ++jx )
      as[ix][jx] = 0;
  
  printf("%d\n", as[0][0]);
  
  free(as);
  as = NULL; // will cause an error to be generated if the pointer is erroneous utilized after the memory has been de-allocated.
  free(asentries);
  asentries = NULL;
}