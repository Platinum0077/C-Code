#include<stdio.h>

void main()
{
int OM[5][5],i,j,count=0,k;

printf("\n Enter the values 5*5 matrix");
for(i=0;i<5;i++)
for(j=0;j<5;j++)
{
scanf("%d",&OM[i][j]);
if(OM[i][j]!=0)
count++;
}
int TM[20][3];

TM[0][0]=5;
TM[0][1]=5;
TM[0][2]=count;
k=1;
for(i=0;i<5;i++)
for(j=0;j<5;j++)
{
if(OM[i][j]!=0)
{
TM[k][0]=i;
TM[k][1]=j;
TM[k][2]=OM[i][j];
k++;
}
}

printf("\n Origional Matrix=\n");
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
printf(" %d ",OM[i][j]);
}
printf("\n");
}

printf("\n printing Triplet Matrix=\n");
for(i=0;i<count+1;i++)
{
for(j=0;j<3;j++)
{
printf(" %d ",TM[i][j]);
}
printf("\n");
}



}