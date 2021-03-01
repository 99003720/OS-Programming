#include "myutils.h"


error_o find_factorial(int num, long* result)
{
   // long temp_result = 1;
    if(1 == num)
    {
        return num;
    }
    else if (0 > num)
    {
        return -1;
    }
    else if (0 == num)
    {
        return 0;
    }
    else
    {
        while (1 <= num)
        {
            *result *= num--;
        }
        return result;
    }
    
}