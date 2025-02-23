#include<stdio.h>
int temp[10],k=0;

void sort(int a[20][20],int id[10], int n);

void main()
{
int a[20][20],n,i,j;
int id[10];
printf("Enter n:");
scanf("%d",&n);
for(i=1;i<=n;i++)
id[i]=0;
printf("\nEnter graph:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
 scanf("%d",&a[i][j]);
 if(a[i][j]==1)
 id[j]++;
}
sort(a,id,n);
if(k!=n)
 printf("Topo not pos");
else
{
 printf("\nOrder is :\n");
for(i=1;i<=n;i++)
printf("%d\t",temp[i]);
}
}

void sort(int a[20][20],int id[10], int n)
{
int i,j;
for(i=1;i<=n;i++)
{
 if(id[i]==0)
 {
  id[i]=-1;
  temp[++k]=i;
  for(j=1;j<=n;j++)
  {
   if(a[i][j]==1 && id[j]!=-1)
   id[j]--;
  }
  i=0;
}
}
}
