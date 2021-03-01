#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void *gettime( void *arg ) {
   time_t curr_time;
   struct tm * time_info;
   time (&curr_time);
   time_info = localtime ( &curr_time );
   printf("%s", asctime (time_info));
   return NULL;
}
//gcc -Wall -o timeThread time.c -lpthread
//./timeThread
int main( int argc, char * argv[] ) {
   pthread_t thread;
   pthread_create( &thread, NULL, gettime, NULL );
   sleep(1);
   return 0;
}
