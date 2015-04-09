#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int *queue,n,i,x,j,q,m,max,min,left,start,sum=0,index,end,func;
void sort(int*,int);
void look();
void clook();
void sort(int p[],int q)
{
      int temp,i,j;
      for(i=0; i<q; i++)
      {
           for(j=0; j<q-i-1; j++)
                if(p[j] > p[j+1])
                {
                     temp = p[j];
                     p[j] = p[j+1];
                     p[j+1] = temp;
                }
      }
}
int  main()
{
    printf("Choose Disk Scheduling Algorithm \n 1.LOOK \n2.CLOOK \n");
    scanf("%d",&func);

	printf("enter the length of the queue:");
	scanf("%d",&n);
	printf("enter the head node:\n");
	scanf("%d",&m);
	printf("previous head:\n");
	scanf("%d",&q);
	if(q>m)
		left=1;
	else
		left=0;
    switch(func)
    {
    case 1:
        look();
        break;
    case 2:
        clook();
        break;
    }
}

void look()
{
    	switch(left)
	{
		case 1:	queue=(int *)malloc(sizeof(int)*(n));
		        printf("enter the data:\n");
       		        for(i=0;i<n;i++)
        		{
                		scanf("%d",&queue[i]);
        		}
        		printf("enter max cylinder:");
        		scanf("%d",&max);
        		printf("enter min cylinder:");
        		scanf("%d",&min);
			sort(queue,n);
			for(i=0;i<n;i++)
			{
				if(queue[i]>max)
				{
					printf("error.limit exceded");
					return;
				}
			}
			for(i=0;i<n;i++)
			{
				if(m>queue[i] && m<queue[i+1])
				{	index=i;
					break;
				}
			}
			while(i>=0)
			{
				if(i==index)
					x=abs(m-queue[i]);
				else
					x=abs(queue[i]-queue[i+1]);
				printf("distance travelled:%d\n",x);
				printf("head moved to %d\n",queue[i]);
				sum=sum+x;
				start=i;
				i--;
			}
			i=index+1;

			while(i<n)
			{	if(i==(index+1))
					x=abs(queue[start]-queue[i]);
				else
					x=abs(queue[i]-queue[i-1]);
				printf("distance travelled:%d\n",x);
				sum=sum+x;
				printf("head moved to %d\n",queue[i]);
				i++;
			}
			printf("total dist is %d\n",sum);
			break;
		case 0:	queue=(int *)malloc(sizeof(int)*(n));
		        printf("enter the data:\n");
       		        for(i=0;i<n;i++)
        		{
                		scanf("%d",&queue[i]);
        		}
        		printf("enter max cylinder:");
        		scanf("%d",&max);
        		printf("enter min cylinder:");
        		scanf("%d",&min);
			for(i=0;i<n;i++)
			{
				if(queue[i]>max)
				{
					printf("error;limit crossed");
					return;
				}
			}
			sort(queue,n);
			for(i=0;i<n;i++)
			{
				if(m>queue[i] && m<queue[i+1])
				{	index=i;
					i++;
					break;
				}
			}
			while(i<(n))
			{
				if(i==(index+1))
					x=abs(m-queue[i]);
				else
					x=abs(queue[i]-queue[i-1]);
				printf("distance travelled:%d\n",x);
				sum=sum+x;
				printf("head moved to %d\n",queue[i]);
				end=i;
				i++;
			}
			i=index;
			while(i>=0)
			{	if(i==index)
					x=abs(queue[i]-queue[end]);
				else
					x=abs(queue[i]-queue[i+1]);
				printf("distance travelled:%d\n",x);
				sum=sum+x;
				printf("head moved to %d\n",queue[i]);
				i--;
			}
			printf("total dist is %d\n",sum);
			break;
	}
}
void clook()
{
    switch(left)
	{
		case 1:	queue=(int *)malloc(sizeof(int)*(n));
		        printf("enter the data:\n");
       		        for(i=0;i<n;i++)
        		{
                		scanf("%d",&queue[i]);
        		}
        		printf("enter max cylinder:");
        		scanf("%d",&max);
        		printf("enter min cylinder:");
        		scanf("%d",&min);
			sort(queue,n);
			for(i=0;i<n;i++)
			{
				if(queue[i]>max)
				{
					printf("error.limited exceded");
					return;
				}
			}
			for(i=0;i<n;i++)
			{
				if(m>queue[i] && m<queue[i+1])
				{	index=i;
					break;
				}
			}
			while(i>=0)
			{
				if(i==index)
					x=abs(m-queue[i]);
				else
					x=abs(queue[i]-queue[i+1]);
				printf("distance travelled:%d\n",x);
				printf("head moved to %d\n",queue[i]);
				sum=sum+x;
				start=i;
				i--;
			}
			i=n-1;
			//x=abs(queue[start]-queue[i]);
			//printf("distance travelled:%d\n",x);
			//sum=sum+x;
			//printf("head moved to %d\n",queue[i]);
			while(i>index)
			{
				if(i==n-1)
				{}
				else
				{
				x=abs(queue[i]-queue[i+1]);
				printf("distance travelled:%d\n",x);
				sum=sum+x;
				}
				printf("head moved to %d\n",queue[i]);
				i--;
			}
			printf("total dist is %d\n",sum);
			break;
		case 0:	queue=(int *)malloc(sizeof(int)*(n));
		        printf("enter the data:\n");
       		        for(i=0;i<n;i++)
        		{
                		scanf("%d",&queue[i]);
        		}
        		printf("enter max cylinder:");
        		scanf("%d",&max);
        		printf("enter min cylinder:");
        		scanf("%d",&min);
			for(i=0;i<n;i++)
			{
				if(queue[i]>max)
				{
					printf("error;limit crossed");
					return;
				}
			}
			sort(queue,n);
			for(i=0;i<n;i++)
			{
				if(m>queue[i] && m<queue[i+1])
				{	index=i;
					i++;
					break;
				}
			}
			while(i<(n))
			{
				if(i==(index+1))
					x=abs(m-queue[i]);
				else
					x=abs(queue[i]-queue[i-1]);
				printf("distance travelled:%d\n",x);
				sum=sum+x;
				printf("head moved to %d\n",queue[i]);
				end=i;
				i++;
			}
			i=0;
			while(i<=index)
			{
				if(i==0)
				{}
				else
				{
				x=abs(queue[i]-queue[i-1]);
				printf("distance travelled:%d\n",x);
				sum=sum+x;
				}
				printf("head moved to %d\n",queue[i]);
				i++;
			}
			printf("total dist is %d\n",sum);
			break;
	}
}










