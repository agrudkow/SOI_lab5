/* t.c - polecenie t wyswietla liczbe i rozmiary blokow wolnych */
#include <stdio.h>
#include <unistd.h>
#include <lib.h>

PUBLIC int hole_map( void *buffer, size_t nbytes)
{
	/* ... _syscall(..HOLE_MAP..) ... */
  int res;
  message msg;

  msg.m1_i1 = nbytes;
  msg.m1_p1 = buffer;

  res = _syscall(MM, HOLE_MAP, &msg);

  return res;
}

int
main( void )
{
  unsigned int b[1024];
  unsigned int *p, a, l;
  int res;

	res = hole_map( b, sizeof( b ) );
  printf( "[%d]\t", res );
  p = b;
  while( *p ){
    l = *p++;
    a = *p++; /* tu niewykorzystywane */
    printf( "%d\t", l );
  }
  printf( "\n" );
  return 0;
}
