#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>

#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>

const int max = 10;
int stack[50];
int first_in = -1;
int info = 1;
pthread_mutex_t m1=PTHREAD_MUTEX_INITIALIZER;
sem_t s1;


void push_stack()
{
    first_in++;
    printf("Stack: %d\n",info);
    stack[first_in] = info;
    info++;
}
void pop_stack()
{
    if(first_in > -1)
    {
        printf("Popped: %d", stack[first_in]);
        first_in--;
    }
    else
    {
        printf("Stack is empty");
    }
}

void* efun1(void* pv)		//producer
{
	int i;
	
	printf("A--welcome\n");
	pthread_mutex_lock(&m1);
	for(i=1;i<=max;i++)
	{
    	push_stack();
	}
	pthread_mutex_unlock(&m1);
	sem_post(&s1);
	//pthread_exit(NULL);
}
void* efun2(void* pv)		//consumer
{
	int i;
	printf("B--welcome,waiting for semaphore\n");
	sem_wait(&s1);			//changing sequence lead to deadlock
	pthread_mutex_lock(&m1);
	pop_stack();
	pthread_mutex_unlock(&m1);
	//pthread_exit(NULL);
}





int main()
{
	printf("main--Welcome\n");
	pthread_t pt1,pt2;	//thread handles
	sem_init(&s1,0,0);
	pthread_create(&pt1,NULL,efun1,NULL);
	pthread_create(&pt2,NULL,efun2,NULL);
	pthread_join(pt1,NULL);
	pthread_join(pt2,NULL);
	sem_destroy(&s1);
	pthread_mutex_destroy(&m1);
	printf("\nmain--Thank you\n");
	return 0;
}