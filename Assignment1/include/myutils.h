#include<stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(num);
int isPrime();

typedef enum error_o{
    NEGATIVE_NUMBER = -1,
    ZERO,
    SUCCESS
}error_o;

error_o find_factorial(int num, long* result);
