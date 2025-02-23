#include<stdio.h>
#include<stdlib.h>

int x[10],s[10],d,n;

void sos(int p,int k,int r);

void main()
{
int i,sum=0;
printf("Enter n:");
scanf("%d",&n);
printf("\nEnter set :\n");
for(i=1;i<=n;i++)
{
scanf("%d",&s[i]);
}

printf("\nEnter max:");
scanf("%d",&d);

for(i=1;i<=n;i++)
 sum+=s[i];

if(sum<d || s[1] >d)
 printf("Subset not pos");
else
 sos(0,1,sum);
}

void sos(int p,int k,int r)
{
int i;
x[k]=1;
if((p+s[k])==d)
{
for(i=1;i<=k;i++)
 if(x[i]==1)
 printf("%d\t",s[i]);
printf("\n");
}
else
{
if((p+s[k]+s[k+1])<=d)
sos(p+s[k],k+1,r-s[k]);
if((p+r-s[k])>=d && (p+s[k+1])<=d)
{
x[k]=0;
sos(p,k+1,r-s[k]);
}
}
}
