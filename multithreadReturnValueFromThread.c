#include<stdio.h>
#include<conio.h>
#include<pthread.h>
struct item
{
	int n;
	int sum;
};
void *getsum(void *ptr)
{
	struct item *a=(struct item *)ptr;
	int n=a->n;
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		sum+=i;
	}
	a->sum=sum;
	int *p=malloc(sizeof(*p));
	*p=sum;
	pthread_exit(p);
}
int main()
{
	int nothread=6,i;
	pthread_t tid[6];
	pthread_attr_t attr[6];
	struct item item_struct[6];
	for(i=0;i<6;i++)
    {
    	item_struct[i].n=i+5;
    	item_struct[i].sum=0;
	}
	for(i=0;i<5;i++)
	{
		pthread_create(&tid[i],&attr[i],getsum,&item_struct[i]);
		int *result;
		pthread_join(tid[i],(void **)&result);
		printf("%d\n",*result);
	//	free(result);
		//printf("%d\n",item_struct[i].sum);
	}
	
}
