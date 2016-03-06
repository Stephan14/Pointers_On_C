#include<stdlib.h>
#include<stdio.h>

#define NUL '\0'

void *calloc( size_t num_elements, size_t element_size )
{
  char *new_memory;
  num_elements *= element_size;
  new_memory = malloc( num_elements );

  if( new_memory != NULL )
  {
    char *ptr = new_memory;
    while( --num_elements >= 0 )
      *ptr++ = NUL;
  }

  return new_memory;
}
