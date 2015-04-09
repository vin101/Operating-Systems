
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void sstf();
void sort(int[],int);
void csan();
void IndexOf(int a);
int len,*request,i,j,max,dir,choice,start,*done,startIndex,*diff,temp,sum=0,x,q,end,left,index,min;
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

int main()
{

 printf("Choose Disk Scheduling algorithm \n 1.SSTF \n 2.C-SCAN \n");
 scanf("%d",&choice);

 switch(choice)
 {
  case 1:
     sstf();
     break;
  case 2:
     cscan();
     break;
 }
return(0);
}

void sstf()
 {
     printf("Enter the number of cylinder heads in the request queue \n");
 scanf("%d",&len);
 //len++;
 request= (int *) malloc(sizeof(int) *len);
 done=(int *) malloc(sizeof(int) *len);
 diff=(int *) malloc(sizeof(int) *len);
 printf("Enter the maximum Cylinders \n");
 scanf("%d",&max);
 printf("Enter the request heads \n");
 for(i=0;i<len;i++)
  {
    scanf("%d",&request[i]);
     done[i]=-1;
    if(request[i]>max)
       {
       printf("Entered request is greater than max \n");
       return(1);
       }
  }
 //printf("Enter the maximum Cylinders \n");
 //scanf("%d",&max);
 printf("Enter the Starting head \n");
 scanf("%d",&start);
// request[i]=start;
// done[i]=-1;
 printf("Enter the Direction if it is towards the end enter 1 otherwise enter 0 \n");
 scanf("%d",&dir);

     for(i=0;i<len;i++)
     {
         diff[i]=abs(start-request[i]);

     }
     for(i=0;i<len-1;i++)
     {
         for(j=0;j<len-1-i;j++)
         {
             if(diff[j]>diff[j+1])
             {
                 temp=diff[j];
                 diff[j]=diff[j+1];
                 diff[j+1]=temp;

                 temp=request[j];
                 request[j]=request[j+1];
                 request[j+1]=temp;
            }
         }
     }
     sum=abs(start-request[0]);
     for(j=0;j<len;j++)
    {
        if(j!=len-1)
        {

         printf("Next Header is %d \n",request[j]);
         printf("Distance Moved is %d \n ",abs(request[j]-request[j+1]));
         sum+=abs(request[j]-request[j+1]);
        }
     }
     printf("Total Cylinder Movement is %d \n",sum);

 }
 cscan()
 {printf("enter the length of the request:");
	scanf("%d",&len);
	printf("enter the head node:\n");
	scanf("%d",&start);
	printf("previous head:\n");
	scanf("%d",&q);
	if(q>start)
		left=1;
	else
		left=0;
	switch(left)
	{
		case 1:request=(int *)malloc(sizeof(int)*(len+2));
		        printf("enter the data:\n");
       		        for(i=1;i<len+1;i++)
        		{
                		scanf("%d",&request[i]); //input request
        		}
        		printf("enter max cylinder:");
        		scanf("%d",&max);
        		printf("enter min cylinder:");
        		scanf("%d",&min);
			request[0]=min;
			request[len+1]=max-1;
			sort(request,len);
			for(i=0;i<len+2;i++)
			{
				if(request[i]>max)
				{
					printf("error.limited exceded");
					return;
				}
			}
			for(i=0;i<len+2;i++)
			{
				if(start>request[i] && start<request[i+1])
				{	index=i;
					break;
				}
			}
			while(i>=0)
			{
				if(i==index)
					x=abs(start-request[i]);
				else
					x=abs(request[i]-request[i+1]);
				printf("distance travelled:%d\n",x);
				printf("head moved to %d\n",request[i]);
				sum=sum+x;
				start=i;
				i--;
			}
			i=len+1;
			//x=abs(request[start]-request[i]);
			//printf("distance travelled:%d\n",x);
			//sum=sum+x;
			//printf("head moved to %d\n",request[i]);
			while(i>index)
			{
				if(i==len+1)
				{}
				else
				{
				x=abs(request[i]-request[i+1]);
				printf("distance travelled:%d\n",x);
				sum=sum+x;
				}
				printf("head moved to %d\n",request[i]);
				i--;
			}
			printf("total dist is %d\n",sum);
			break;
		case 0:	request=(int *)malloc(sizeof(int)*(len+2));
		        printf("enter the data:\n");
       		        for(i=1;i<len+1;i++)
        		{
                		scanf("%d",&request[i]);
        		}
        		printf("enter max cylinder:");
        		scanf("%d",&max);
        		printf("enter min cylinder:");
        		scanf("%d",&min);
			request[len+1]=max-1;
			request[0]=min;
			for(i=0;i<len+2;i++)
			{
				if(request[i]>max)
				{
					printf("error;limit crossed");
					return;
				}
			}
			sort(request,len+2);
			for(i=0;i<len+2;i++)
			{
				if(start>request[i] && start<request[i+1])
				{	index=i;
					i++;
					break;
				}
			}
			while(i<=(len+1))
			{
				if(i==(index+1))
					x=abs(start-request[i]);
				else
					x=abs(request[i]-request[i-1]);
				printf("distance travelled:%d\n",x);
				sum=sum+x;
				printf("head moved to %d\n",request[i]);
				end=i;
				i++;
			}
			i=0;
			//x=abs(request[end]-request[i]);
			//printf("distance travelled:%d\n",x);
			//sum=sum+x;
			//printf("head moved to %d\n",request[i]);
			while(i<=index)
			{
				if(i==0)
				{}
				else
				{
				x=abs(request[i]-request[i-1]);
				printf("distance travelled:%d\n",x);
				sum=sum+x;
				}
				printf("head moved to %d\n",request[i]);
				i++;
			}
			printf("total dist is %d\n",sum);
			break;
	}
}






