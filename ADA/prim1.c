#include<stdio.h>
#define INF 999
int c[10][10],n,s;
int prim(int c[10][10],int,int);
void main()
{
 int i,j,res;
 printf("Enter n value:");
 scanf("%d",&n);
 printf("\nEnter graph data:\n");
 for(i=1;i<=n;i++)
 for(j=1;j<=n;j++)
  scanf("%d",&c[i][j]);
 printf("\n");
 printf("Enter the source node:");
 scanf("%d",&s);
 res=prim(c,n,s);
 printf("Cost=%d",res);
}

int prim(int c[10][10],int n, int s)
{
 int min,ver[10],v[10],d[10],i,j,sum=0,u;
 for(i=1;i<=n;i++)
 {
  ver[i]=s;
  d[i]=c[s][i];
  v[i]=0;
 }
v[s]=1;
for(i=1;i<n;i++)
{
 min=INF;
 for(j=1;j<=n;j++)
 if(v[j]==0 && d[j]<min)
 { min=d[j];
  u=j;
}
v[u]=1;
sum=sum+d[u];
printf("%d -> %d sum=%d\n",ver[u],u,sum);
for(j=1;j<=n;j++)
if(v[j]==0 && c[u][j]<d[j])
{d[j]=c[u][j];
 ver[j]=u;
}
}
return sum;
}
