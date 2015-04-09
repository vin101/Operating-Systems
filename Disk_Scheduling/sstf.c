#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void sstf();
void sort();
void IndexOf(int a);
int len,*request,i,j,max,dir,choice,start,*done,startIndex,*diff,temp,sum=0;
int main()
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
 {

 }
