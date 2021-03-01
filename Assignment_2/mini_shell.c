#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc,char *argv)
{
char cmd[100] = "";

printf("Enter your command");
scanf("%s",cmd);


int ret=0,status;
	ret=fork();
 argv[0] = cmd;
	if(ret<0)
	{
		perror("fork");
		exit(1);
	}
    if(ret==0)
    {
        int execute;
        execute = execlp(cmd,argv,NULL);
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
}
