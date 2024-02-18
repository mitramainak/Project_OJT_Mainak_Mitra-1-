#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void* fun1()
{
	printf("Hello you are in thread1");
	sleep(5);
}
void* fun2()
{
	printf("Hello you are in thread2");
	sleep(5);
}
int main()
{
	pthread_t t_id,t_id1;
	int ret,ret1;
	printf("tid : %d",t_id);
	printf("tid1 : %d",t_id1);
	printf("The process ID is : %d\n",getpid());
	ret=pthread_create(&t_id,NULL,fun1,NULL);
	ret1=pthread_create(&t_id1,NULL,fun2,NULL);

	if(ret==0)
		printf("Thread1 created successfully\n");
	else
		printf("Thread not created\n");

	if(ret1==0)
		printf("Thread2 created successfully\n");
	else
		printf("Thread not created\n");

	pthread_join(t_id,NULL);
	pthread_join(t_id1,NULL);
	printf("Thread terminated");
}


