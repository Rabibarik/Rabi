#include<stdio.h>
#include<stdlib.h>
int bin_search(int *a,int n,int item)
{
	int mid,lb=0,ub=n-1;
	while(lb<=ub)
	{
		mid=(lb+ub)/2;
		if(a[mid]==item)
			return mid;
		else if(item<a[mid])
			ub=mid-1;
		else
			lb=mid+1;
	}
	return -1;
}
void main()
{
	int *a,n,item,i,loc;
	printf("enter the size : ");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	printf("enter the elements into array\n");
	for(i=0;i<=n-1;i++)
	scanf("%d",&a[i]);
	printf("enter the item to search : ");
	scanf("%d",&item);
	loc=bin_search(a,n,item);
	if(loc==-1)
		printf("%d is not found",item);
	else
		printf("%d is found at %d",item,loc);
}

