#include<stdio.h>
#define INF 999
#define MAX 50
int p[MAX],c[MAX][MAX],t[MAX][2];

void uni(int i,int j)
{
 p[j]=i;
}

int find(int v)
{
 while(p[v])
 v=p[v];
 return v;
}

void kruskal(int n)
{
 int min,k,i,j,u,v,res1,res2;
 int sum=0;
for(k=1;k<n;k++)
 {
  min=INF;
  for(i=1;i<n-1;i++)
  {
   for(j=1;j<=n;j++)
   {
    if(i==j) continue;
    if(c[i][j]<min)
    {
        u=find(i);
	v=find(j);
	if(u!=v)
	{
	 res1=i;
	 res2=j;
	 min = c[i][j];
	}
    }
   }
  }
 uni(res1,find(res2));
 t[k][1]=res1;
 t[k][2]=res2;
 sum = sum  + min;
}
printf("Cost of MST: %d",sum);
printf("\nEdeges of MST:\n");
for(i=1;i<n;i++)
 printf("%d -> %d\n",t[i][1],t[i][2]);
}


int main()
{
 int n,i,j;
 printf("Enter the n value:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 p[i]=0;
 printf("Enter the graph data:\n");
 for(i=1;i<=n;i++)
 for(j=1;j<=n;j++)
 scanf("%d",&c[i][j]);
 kruskal(n);
 return 0;
}

