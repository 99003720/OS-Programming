#include"myutils.h"

int isPrime(int input)
{
 int i,input,output=0;
 for(int i=2;i<=input/2;i++)
    {
 if((input%i)==0)
        {
 output=1;
 return 0;
 break;
        }
    }
 if(output==0)
    {
 return 0;
     }
}