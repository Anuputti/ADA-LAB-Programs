#include<stdio.h>
#define INF 999
int c[10][10],d[10],n,s;

void dijk(int c[10][10], int n, int s)
{
 int v[10],i,j,min,sum=0,u;
 for(i=1;i<=n;i++)
{
 v[i]=0;
 d[i]=c[s][i];
}
v[s]=1;

for(i=1;i<=n;i++)
{
 min=INF;
 for(j=1;j<=n;j++)
 if(v[j]==0 && d[j]<min)
{
 min=d[j];
 u=j;
}
 v[u]=1;
 for(j=1;j<=n;j++)
 if(v[j]==0 && (d[u]+c[u][j] < d[j]))
 {
  d[j]=d[u]+c[u][j];
 }
}
}




void main()
{
 int i,j;
 printf("Enter n:");
 scanf("%d",&n);
 printf("\nEnter graph:\n");
 for(i=1;i<=n;i++)
 for(j=1;j<=n;j++)
 scanf("%d",&c[i][j]);
 printf("\n");
 printf("\nEnter source:");
 scanf("%d",&s);
 dijk(c,n,s);
 printf("\nShortest paths:\n");
 for(i=1;i<=n;i++)
  printf("%d -> %d = %d\n",s,i,d[i]);
}
