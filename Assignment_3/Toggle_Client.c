#include <mqueue.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int ret;
	mqd_t mqid;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	mqid=mq_open("/mstr",O_WRONLY|O_CREAT,0666,&attr);
	//mqid=mq_open("/mque",O_WRONLY|O_CREAT,0666,NULL);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}
char string[20] = "ThiS iS a StRInG ClIent sEndS";
int len = strlen(string);
	ret=mq_send(mqid,string,len+1,NULL);
	if(ret<0)
	{
		perror("mq_send");
		exit(2);
	}


    mq_close(mqid);
	return 0;
}