#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAXIMUM 16 


#define THREAD_MAX 4 


int array[MAXIMUM] = { 1, 5, 7, 10, 12, 14, 15, 18, 20, 
			22, 25, 27, 300, 64, 110, 220 }; 


int max[THREAD_MAX] = {0}; 
int thread_num = 0; 


void max_element(void* arg) 
{ 
	int i, num = thread_num++; 
	int max_sum = 0; 

	for (i = num * (MAXIMUM / 4); i < (num + 1) * (MAXIMUM/ 4); i++) { 
		if (array[i] > max_sum) 
			max_sum = array[i]; 
	} 

	max[num] = max_sum; 
} 


int main() 
{ 
	int max_sum = 0; 
	int i; 
	pthread_t threads[THREAD_MAX]; 

	for (i = 0; i < THREAD_MAX; i++) 
		pthread_create(&threads[i], NULL, 
					max_element, (void*)NULL); 

	for (i = 0; i < THREAD_MAX; i++) 
		pthread_join(threads[i], NULL); 

	for (i = 0; i < THREAD_MAX; i++) { 
		if (max[i] > max_sum) 
			max_sum = max[i]; 
	} 

	printf("Maximum Element is : %d", max_sum); 

	return 0; 
} 