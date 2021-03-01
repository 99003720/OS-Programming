#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum error_t{
    FAILURE=1,
    PASS
}error_t;

int mystrlen(char *str_input);
error_t mystrcmp(char* str_input1, char* str_input2);
int mystrcat(char *s1,char *s2);
