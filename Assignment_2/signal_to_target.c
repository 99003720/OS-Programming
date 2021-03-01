#include<stdio.h>
#include<signal.h>
#include <unistd.h>

void sig_handler(int signum)
{
 printf("Signal Handler: %d\n",signum);
}

int main()
{
 pid_t pid;
 signal(SIGUSR1,sig_handler);
 pid=getpid();
 int c=kill(pid,SIGUSR1);
 printf("\nSignal sent: %d\n",c);
 return 0;
}