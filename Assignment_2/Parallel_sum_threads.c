#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXIMUM 25
#define THREAD 5

int sum[1000] = {0}; 
int val = 0; 
int array[25] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};

  
void* parallel_sum(void* arg) 
{

    int thread_val = val++; 

  
    for (int i = thread_val * (MAXIMUM / 4); i < (thread_val + 1) * (MAXIMUM / 4); i++) 
        sum[thread_val] += array[i]; 
} 
  

int main() 
{ 
    pthread_t threads[THREAD]; 

    for (int i = 0; i < THREAD; i++) 
        pthread_create(&threads[i], NULL, parallel_sum,NULL); 
  

    for (int i = 0; i < THREAD; i++) 
        pthread_join(threads[i], NULL); 
  

    int total_sum = 0; 
    for (int i = 0; i < THREAD; i++) 
        total_sum += sum[i]; 
  
   printf("Sum: %d",total_sum); 
  
    return 0; 
} 