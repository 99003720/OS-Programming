#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>

const int max = 10;
int stack[50];
int first_in = -1;
int info = 1;
sem_t s1;
sem_t s2;

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
void* tentry_fun1(void* pv)	//consumer
{
	int i;
	printf("A--welcome\n");
	sem_wait(&s2);
	sem_wait(&s1);
	pop_stack();
	sem_post(&s1);
	//pthread_exit(NULL);
}
void* tentry_fun2(void* pv)	//producer
{
	int i;
	printf("B--welcome\n");
	sem_wait(&s1);
	
    for(i=1;i<=max;i++)
	{
		push_stack();
	}
    
	sem_post(&s1);
	sem_post(&s2);
	//pthread_exit(NULL);
}
int main()
{
	pthread_t pt1,pt2;	//thread handle
	sem_init(&s1,0,1);
	sem_init(&s2,0,0);
	pthread_create(&pt1,NULL,tentry_fun1,NULL);
	pthread_create(&pt2,NULL,tentry_fun2,NULL);
	pthread_join(pt1,NULL);
	pthread_join(pt2,NULL);
	sem_destroy(&s1);
	sem_destroy(&s2);
	printf("main--thank you\n");
	return 0;	//exit(0);
}