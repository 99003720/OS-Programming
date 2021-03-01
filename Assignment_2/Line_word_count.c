#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int fd,nbytes;
	fd=open("file1.txt",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
	int maxlen=128;
	char buf[maxlen];
	nbytes=read(fd,buf,maxlen);
	if(nbytes<0)
	{
		perror("read");
		exit(2);
	}
   
    //write(1,buf,nbytes);
    int count=0,count_word = 0;
 int length = strlen(buf);
    for (int c =0;c<=length;c++) 
    {
        if (buf[c] != '\0')
        {
            if(buf[c] == '\n')
         // Increment count if this character is newline 
        count = count + 1; 
    }
    else
    {
    count = count+1;
    }
    }
   
     for (int c =0;c<=length;c++) 
    {
        if (buf[c] != '\0')
        {
           if(buf[c] == ' ' || buf[c] == '\n')
        {
            count_word += 1;
        }
    }
    else
    {
    count_word = count_word+1;
    }
    }
    printf("%d %d %d",count,count_word,length);
   
	close(fd);


	return 0;	//exit(0);
}