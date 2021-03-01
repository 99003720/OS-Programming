#include"myutils.h"

int vsum(int a, ...)
{
 va_list valist;
 int sum;
 int i;

 va_start(valist,a);
 for(i=0;i<a;i++)
    {
 sum+=va_arg(valist,int);
    }

 va_end(valist);
 return sum;
}

int main()
{
 printf("SUM: %d\n", vsum(4, 2,3,4,5));
}