#include<stdio.h>

void main()
{
int M1[4][4],M2[4][4],i,j,x,y,c1=0,c2=0,k,p,q;

printf("\n Enter the values for first 4 x 4 matrix: ");
for(i=0;i<4;i++)
for(j=0;j<4;j++)
{
scanf("%d",&M1[i][j]);
if(M1[i][j]!=0)
c1++;
}

printf("\n Enter the values for second 4 x 4 matrix: ");
for(x=0;x<4;x++)
for(y=0;y<4;y++)
{
scanf("%d",&M2[x][y]);
if(M2[x][y]!=0)
c2++;
}

int T1[20][3];

T1[0][0]=4;
T1[0][1]=4;
T1[0][2]=c1;
k=1;
for(i=0;i<4;i++)
for(j=0;j<4;j++)
{
if(M1[i][j]!=0)
{
T1[k][0]=i;
T1[k][1]=j;
T1[k][2]=M1[i][j];
k++;
}
}

int T2[20][3];

T2[0][0]=4;
T2[0][1]=4;
T2[0][2]=c2;
k=1;
for(x=0;x<4;x++)
for(y=0;y<4;y++)
{
if(M2[x][y]!=0)
{
T2[k][0]=x;
T2[k][1]=y;
T2[k][2]=M2[x][y];
k++;
}
}

printf("\n Matrix 1 : \n");
for(i=0;i<4;i++)
{
for(j=0;j<4;j++)
{
printf(" %d ",M1[i][j]);
}
printf("\n");
}

printf("\n Matrix 2 : \n");
for(x=0;x<4;x++)
{
for(y=0;y<4;y++)
{
printf(" %d ",M2[x][y]);
}
printf("\n");
}

printf("\nTriplet Matrix 1: \n");
for(i=0;i<c1+1;i++)
{
for(j=0;j<3;j++)
{
printf(" %d ",T1[i][j]);
}
printf("\n");
}

printf("\nTriplet Matrix 2: \n");
for(x=0;x<c2+1;x++)
{
for(y=0;y<3;y++)
{
printf(" %d ",T2[x][y]);
}
printf("\n");
}

int sum[p][q];

for (p = 0; p < 20; p++)
for (q = 0; q < 3; q++) 
 {
  sum[p][q] = T1[p][q] + T2[p][q];
 }

 
for(int i = 0 ; i < 2 ; i++){

    for(int j = 0 ; j < 3 ; j++){

        printf(" %d ",sum[i][j]);
    }
    printf("\n");
}

}