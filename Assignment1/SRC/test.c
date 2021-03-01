
#include "bitmask.h"
#include "mystring.h"
#include "myutils.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

 char str_input1[50]="HELLO";
 char str_input2[50];
 int length,set_val,reset_val,setans,resetans;
 char answer[10];
  set_val = 0;
  reset_val = 1;


  length = mystrlen(str_input1);
  printf("Length: %d", length);
  printf("Result: %s", mystrcmp(str_input1,str_input2));



int fact=0;
int fact_val = 4;
long result = 1;
fact = find_factorial(fact_val,&result);




 char s1[20]="Hello";
 char s2[20]="World";
printf("%s",mystrcat(s1,s2));




set_val = 0;
setans = myset(set_val);
printf("%d",setans);




reset_val = 1;
resetans = myreset(set_val);
printf("%d",resetans);





int num = 121,ret=0;
 ret = isPalindrome(num);
 if(ret == 0)
 {
   printf("Not a palindrome");
 }
 else
 {
   printf("Is a palindrome");
 }


 int prime_num;
 prime_num = isPrime(num);
  if(prime_num == 0)
 {
   printf("Not a prime number");
 }
 else
 {
   printf("A prime number");
 }



  return 0;

}