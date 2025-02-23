#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>

void genrandinput(int x[],int n);
void disparray(int x[], int n);
void selsort(int a[],int n);

int main()
{
FILE *fp;
int arr[500000],num,choice,i;
struct timeval tv;
double dstart,dend;
for( ; ;)
{
printf("1.plot the graph\n2.selection sort\n3.exit");
printf("\nEnter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
 fp=fopen("selection.dat","w");
 for(i=100;i<10000; i+=100)
 {
  genrandinput(arr,i);
  gettimeofday(&tv,NULL);
  dstart=tv.tv_sec + (tv.tv_usec/10000.0);
  selsort(arr,i);
  gettimeofday(&tv,NULL);
  dend=tv.tv_sec + (tv.tv_usec/10000.0);
  fprintf(fp,"%d\t%lf\n",i,dend-dstart);
 }
 fclose(fp);
 printf("Data file generated and stored in file Selection.dat\n use a plotting utility\n");
 break;

case 2:
 printf("Enter the no. of elements to sort:");
 scanf("%d",&num);
 printf("Unsorted Array\n");
 genrandinput(arr,num);
 disparray(arr,num);
 printf("Sorted array\n");
 selsort(arr,num);
 disparray(arr,num);
 break;

case 3: exit(0);
}
}
return 0;
}

void genrandinput(int x[],int n)
{
 int i;
 srand(time(NULL));
 for(i=0;i<n;i++)
  x[i]=rand()%10000;
}

void disparray(int x[], int n)
{
 int i;
 for(i=0;i<n;i++)
  printf("%d\n",x[i]);
}

void selsort(int a[], int n)
{
 int temp,small,pos,i,j;
 for(j=0;j<n-1;j++)
 {
  small=a[j];
  pos=j;
 for(i=j+1;i<n;i++)
 {
  if(a[i]<small)
  {
   small=a[i];
   pos=i;
  }
 }
 temp=a[j];
 a[j]=small;
 a[pos]=temp;
 }
}
