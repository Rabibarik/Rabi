#include<stdio.h>
#include<stdlib.h>
#define max 10
int main()
{
    int mat[max][max],spm[max][3];
    int i,j,row,col,k;
    printf("Enter the dimensions of matrix: \n");
    scanf("%d %d",&row,&col);
    printf("enter the elements of matrix \n:");
    for(i=0;i<row;i++)
    for(j=0;j<col;j++)
    scanf("%d",&mat[i][j]);
    printf("enter the elements of matrix \n:");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        printf("%d",mat[i][j]);
        printf("\n");
    } 
    k=1;
    for(i=0;i<row;i++)
    for(j=0;j<col;j++)
    if(mat[i][j]!=0)
    {
        spm[k][0]=i;
        spm[k][1]=j;
        spm[k][2]=mat[i][j];
        k++;
    }
    spm[0][0]=row;
    spm[0][1]=col;
    spm[0][2]=k-1;
    printf("The elements of sparse matrix\n");
     for(i=0;i<=spm[0][2];i++)
    {
        for(j=0;j<3;j++)
        printf("%d",spm[i][j]);
        printf("\n");
    }
    return 0;
}