#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main(int argc,char *argv)
{
    
    int fd,nbytes;
    fd=open("file1.txt",O_RDONLY);
    
    if(fd<0)
    {
        perror("open");
        exit(1);
    }
    int len = 128;
    char buf[len];
    nbytes = read(fd,argv,len);
    if(nbytes<0)
	{
		perror("read");
		exit(2);
	}
    int fd1,nbytes1;
    fd=open("file2.txt",O_WRONLY|O_CREAT,0666);
    if(fd<0)
	{
		perror("open");
		exit(3);
	}
    int length = strlen(buf);
    nbytes1 = write(fd,argv,length);
    if(nbytes<0)
	{
		perror("write");
		exit(3);
	}
    printf("written successfully,nbytes=%d\n",nbytes);
	close(fd);
	return 0;	//exit(0);
}