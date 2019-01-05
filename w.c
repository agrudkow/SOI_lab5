/* w.c - polecenie w przyjmuje jako argument 1 albo 0 */
/* wlaczajac/wylaczajac algorytm worst fit w systemie Minix */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <lib.h>


PUBLIC int worst_fit( int w )
{
	/* ... _syscall(..WORST_FIT..) ... */
  int res;
  message msg;

  if (w != 0 && w != 1) {
    printf("w.c::worst_fit::Zle dane - argument powinein przyjmowac wartosc 0 lub 1");
    return 1;
  }

  msg.m1_i1 = w;

  res = _syscall(MM, WORST_FIT, &msg);

  return res;
}

int
main( int argc, char *argv[] )
{
	if( argc < 2 )
		return 1;
	worst_fit( atoi( argv[1] ) );
	return 0;
}
