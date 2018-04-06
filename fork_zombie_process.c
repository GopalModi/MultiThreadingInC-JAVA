#include<stdio.h>
#include<conio.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
void dostuff(char *s)
{
	int i=0;
	for(i=0;i<10;i++)
	{
		printf("I am %s == %d\n",s,i);
	}
}
int main()
{
	printf("I am Parent\n");
	pid_t pid=fork();
	printf("Fork returned id %d",pid);
	if(pid<0)
	{
		printf("Process did not get created\n");
		//exit(0);
	}
	if(pid==0)
	{
		//this control belongs child process
		dostuff("child");
		exit(42);
	}
	dostuff("parent");
}
