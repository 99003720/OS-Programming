#include "myutils.h"

char* myset(int x)
{
  int number;
number |= 1 << x;
return number;
}



