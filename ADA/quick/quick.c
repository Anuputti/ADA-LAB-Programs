#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>

void gri(int [], int);
void disp(int [], int);
void qs(int [],int, int);
int part(int[],int,int);
void swap(int *a, int *b)
{
 int t=*a;
 *a=*b;
 *b=t;
}

void main()
{
FILE *fp;
int A[500000],i,n,ch;
double dend,dstart;
struct timeval tv;
for(;;)
{
printf("1.plot  2.qs 3.exit\n");
printf("Enter ch:");
scanf("%d",&ch);
switch(ch)
{
case 1:
fp=fopen("quick.dat","w");
for(i=100;i<100000; i+=100)
{
gri(A,i);
gettimeofday(&tv,NULL);
dstart=tv.tv_sec + (tv.tv_usec/1000000.0);
qs(A,0,i-1);
gettimeofday(&tv,NULL);
dend=tv.tv_sec + (tv.tv_usec/1000000.0);
fprintf(fp,"%d\t%lf\n",i,dend-dstart);
}
fclose(fp);
printf("Data file generated");
break;

case 2:
printf("\nEnter n:");
scanf("%d",&n);
printf("\nUnsorted array\n");
gri(A,n);
disp(A,n);
printf("\nSorted array\n");
qs(A,0,n-1);
disp(A,n);
break;
 case 3:exit(0);
}
}
}

void gri(int x[],int n)
{
srand(time(NULL));
for(int i=0;i<n;i++)
 x[i]=rand()%10000;
}

void disp(int x[],int n)
{
 for(int i=0;i<n;i++)
 { printf("%5d\n",x[i]);
}
}

void qs(int A[],int p,int r)
{
int s;
if(p<r)
{
s=part(A,p,r);
qs(A,p,s-1);
qs(A,s+1,r);
}
}

int part(int A[], int p, int r)
{
int i,j,temp,l;
l=A[p];
i=p;
j=r+1;

do
{
do{i++;} while(A[i]<l);
do{j--;} while(A[j]>l);
swap(&A[i],&A[j]);
}while(i<j);

swap(&A[i],&A[j]);
swap(&A[p],&A[j]);
return j;
}
