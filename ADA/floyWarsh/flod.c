#include<stdio.h>
#define INF 999
#define MAX 50
int a[MAX][MAX],n;

int min(int a, int b)
{
return a<b?a:b;
}

void floyd(int n, int a[MAX][MAX])
{
int i,j,k;
for(k=1;k<=n;k++)
{
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
 a[i][j]= min(a[i][j],a[i][k]+a[k][j]);
}
}
}
}


void main()
{
printf("Enter n:");
scanf("%d",&n);
printf("\nEnter graph:\n");
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
 scanf("%d",&a[i][j]);
floyd(n,a);
printf("\nShortest path graph:\n");
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
 printf("%d\t",a[i][j]);
printf("\n");
}
}
