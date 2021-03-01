#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
	int ret=0,status;
	ret=fork();
	if(ret<0)
	{
		perror("fork");
		exit(1);
	}
    if(ret==0)
    {
        int execute;
        execute = execlp("./file.out",NULL);
        if(execute<0)
	{
		perror("execlp");
		exit(2);
	}
    }
    else
    {
        waitpid(-1,&status,0);
    }
    return 0;
}
