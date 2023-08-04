#include<stdio.h>
#include<stdlib.h>
int lsearch(int *a,int n,int item)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==item)
			return i;//return the index of the key element
	}
	return -1;//return -1, if the item is not found
}
void main()
{
	int *a,n,item,i,loc;
	printf("enter the size : ");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	printf("enter the elements into array\n");//array elements
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("enter the item to search : ");//key element
	scanf("%d",&item);
	loc=lsearch(a,n,item);
	if(loc==-1)//if the item is not found
		printf("%d is not found",item);
	else//if the item is found
		printf("%d is found at %d",item,loc);
}

