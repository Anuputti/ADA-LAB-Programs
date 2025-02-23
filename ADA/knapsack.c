#include<stdio.h>
int p[10],w[10];
int n,m,i;

int max(int a,int b)
{
return a>b?a:b;
}


int knap(int i,int m)
{
if(i==n) return w[i]>m?0:p[i];
if(w[i]>m) return knap(i+1,m);
return max(knap(i+1,m), knap(i+1,m-w[i])+p[i]);
}


int main()
{

printf("Enter n:");
scanf("%d",&n);
printf("\nEnter m:");
scanf("%d",&m);
printf("\nEnter profit followed by weight:\n");
for(i=1;i<=n;i++)
scanf("%d %d",&p[i],&w[i]);
int maxprofit=knap(1,m);
printf("\n mp:%d",maxprofit);
return 0;
}
