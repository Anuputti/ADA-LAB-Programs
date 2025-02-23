#include<stdio.h>
#define MAX 50
int p[MAX],w[MAX],x[MAX];
int j,n,m,i;
double maxprofit;
void knapsack(int,int [], int [], int);

void main()
{
printf("Enter the n value:");
scanf("%d",&n);
printf("\nenter profit:\n");
for(i=1;i<=n;i++)
scanf("%d",&p[i]);

printf("\nEnter weight:\n");
for(i=1;i<=n;i++)
scanf("%d",&w[i]);

printf("\nEnter capacity:");
scanf("%d",&m);

knapsack(n,p,w,m);
}

void knapsack(int n, int p[], int w[], int m)
{
double ratio[MAX];

for(i=1;i<=n;i++)
ratio[i]=(double)p[i]/w[i];

for(i=1;i<n;i++)
{
for(j=i+1;j<=n;j++)
{
if(ratio[i]<ratio[j])
{
 double temp = ratio[i];
 ratio[i]=ratio[j];
 ratio[j]=temp;

 int temp2 = w[i];
 w[i]=w[j];
 w[j]=temp;

 temp2=p[i];
 p[i]=p[j];
 p[j]=temp;
}
}
}

int currentWeight=0;
maxprofit=0.0;

for(i=1;i<=n;i++)
{

if(currentWeight+w[i] <= m)
{
 x[i]=1;
 currentWeight+=w[i];
 maxprofit+=p[i];
}
else
{
x[i]=(m-currentWeight)/w[i];
maxprofit += x[i]*p[i];
break;
}
}

printf("Max profit:%.1f",maxprofit);
printf("Seleceted vetors:\n");
for(i=1;i<=n;i++)
 printf("%d",x[i]);
}
