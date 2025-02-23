#include<stdio.h>
#include<sys/time.h>
#include<stdlib.h>
#include<time.h>

void merge(int [],int,int,int );
void mergesort(int [], int,int);
void genrandinput(int [],int);
void disp(int [], int);

int main()
{
FILE *fp;
int Ar[50000],i,choice,n;
double dend,dstart;
struct timeval tv;

for( ; ; )
{
printf("1.Plot 2. Mergesort  3. exit\n");
printf("Enter choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
 fp=fopen("merge.dat","w");
 for(i=100; i<10000; i+=100)
{
 genrandinput(Ar,i);
 gettimeofday(&tv,NULL);
 dstart=tv.tv_sec + (tv.tv_usec/1000000.0);
 mergesort(Ar,0,i-1);
 gettimeofday(&tv,NULL);
 dend=tv.tv_sec+ (tv.tv_usec/1000000.0);
 fprintf(fp, "%d\t%lf\n",i,dend-dstart);
}
fclose(fp);
printf("Data file generated and stored in merge.dat file\n");
break;

case 2:
printf("Enter no. of elements to sort:");
scanf("%d",&n);
printf("\nUnsorted array\n");
genrandinput(Ar,n);
disp(Ar,n);
printf("\nSorted array:\n");
mergesort(Ar,0,n-1);
disp(Ar,n);
break;

case 3: exit(0);
}
}
}

void genrandinput(int x[],int n)
{
 int i;
 srand(time(NULL));
 for(i=0;i<n;i++)
 x[i]=rand()%10000;
}

void disp(int x[], int n)
{
for(int i=0;i<n;i++)
printf("%5d\n",x[i]);
}

void mergesort(int a[],int low, int high)
{
int mid;
if(low<high)
{
 mid=(low+high)/2;
 mergesort(a,low,mid);
 mergesort(a,mid+1,high);
 merge(a,low,mid,high);
}
}

void merge(int a[], int low, int mid, int high)
{
int i,j,k, b[50000];
i=k=low;
j=mid+1;

while(i<=mid && j<=high)
{
 if(a[i]<a[j])
	b[k++]=a[i++];
 else
	b[k++]=a[j++];
}
while(i<=mid)
{
b[k++]=a[i++];
}
 while(j<=high)
  b[k++]=a[j++];

for(i=low; i<k;i++)
 a[i]=b[i];
}
