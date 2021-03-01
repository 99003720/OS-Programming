#include "bitmask.h"

int myreset(int x)
{
int number;
number &= ~(1 << x);
return number;
}
