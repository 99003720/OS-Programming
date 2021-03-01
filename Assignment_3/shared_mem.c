
#include<unistd.h>
#include<semaphore.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/mman.h>
#include<stdlib.h>

#define Size 100

int *stack_ptr;
int stack[Size];
int first_in = -1;
void Producer();
void Consumer();
  

int main()
{
	int ret,i,max=10,status;
	sem_t *ps,*qs;
    void *ptr;
	ps=sem_open("/s1",O_CREAT, 0666, 1);
	qs=sem_open("/s2",O_CREAT, 0666, 0);
	ptr=mmap(0,4096, PROT_WRITE|PROT_READ, MAP_SHARED|MAP_ANONYMOUS,-1,0);
	
	if(stack_ptr==MAP_FAILED)
	{
		printf("\nmap failed");
		return -1;
	}
	ret=fork();
	if(ret==0)
	{
		sem_wait(ps);
		for(i=1;i<=max;i++)
		{
			producer();
		}
		sem_post(ps);
		sem_post(qs);
		exit(0);
	}
	else	//ret>0
	{
        sem_wait(qs);
	    sem_wait(ps);	

for(i=1;i<=max;i++)
{
    Consumer();
}
sem_post(ps);
		waitpid(-1,&status,0);
		sem_unlink("s1");
		sem_unlink("s2");
    }


    return 0;
}

void Producer()
{
    first_in++;
    int val=0;
    int data[] = {2,5,6,3,4,7,4,7,3,2,5,3};
    stack_ptr = data[val];

    printf("Element by producer: %d",*stack_ptr);
    val++;
    }

    void consumer()
    {
        printf("Element by consumer: %d", (*stack_ptr));
        first_in--;
    }
  
