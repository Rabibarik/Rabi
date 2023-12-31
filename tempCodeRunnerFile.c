#include<stdio.h>
#include<stdlib.h>
#define size 4
typedef struct queue
{
	int data[size];
	int front,rear;
}queue;
int isempty(queue *q)
{
	if(q->front==-1 && q->rear==-1)//when there is no element in the queue
		return 1;
	else
		return 0;
}
int isfull(queue *q)
{
	if((q->front==0 && q->rear==size-1 )||(q->front==q->rear+1))//if any of these 2 condition satisfy then queue is full
		return 1;
	else
		return 0;
}
void insert(queue *q,int x)
{
	if(isfull(q))//when queue is full
	{
		printf("\nqueue overflow");
		return;
	}
	else if(isempty(q))//when the queue is empty, will will insert first element
		q->rear=q->front=0;//both front and rear will increase by 1 i.e set to 0
	else//there are some elements already present in queue
		q->rear=(q->rear+1)%size;//only rear will increase by 1, after reaching to size-1, the rear will be again 0
	q->data[q->rear]=x;
}
int delet(queue *q)
{
	int x;
	if(isempty(q))//when queue is empty
	{
		printf("\nqueue underflow");
		return -1;
	}
	x=q->data[q->front];//element from the front end is to be deleted
	if(q->front==q->rear)//when only one element present in the queue
		q->front=q->rear=-1;//then both front & rear will decrease by 1, i.e set to -1
	else//when more than one elemet present in queue
		q->front=(q->front+1)%size;//then only front will increase by 1, after reaching to size-1, the front will be again 0
	return x;//return deleted element
}
void disp(queue *q)
{
	int i;
	if(isempty(q))//when queue is empty
	{
		printf("\nqueue underflow");
		return;
	}
	if(q->front<=q->rear)//then display like linear queue
	{
		for(i=q->front;i<=q->rear;i++)
		printf("%d\t",q->data[i]);
		printf("\ntotal elements = %d ",q->rear-q->front+1);	
	}
	
	else//when front is greater than rear
	{
		for(i=0;i<=q->rear;i++)
		printf("%d\t",q->data[i]);
	
		for(i=q->front;i<=size-1;i++)
		printf("%d\t",q->data[i]);
		printf("\ntotal elements = %d ",(size-q->front)+q->rear+1);	
	}
	printf("\nFront = %d",q->front);
	printf("\nRear = %d",q->rear);
}
int main()
{
 queue *q;
 int num,op,item;
 q=(queue*)malloc(sizeof(queue));
 q->front=-1;
 q->rear=-1;
 do
 {
 	printf("\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
 	printf("enter option : ");
 	scanf("%d",&op);
 	switch(op)
 	{
 		case 1:
 			printf("enter item to insert : ");
 			scanf("%d",&item);
 			insert(q,item);
 			break;
 		case 2:
 			num=delet(q);
 			if(num!=-1)
 			{
 				printf("\ndeleted item = %d",num);
 			}
 			break;
 		case 3:
 			printf("\nthe queue elsements\n");
 			disp(q);
 			break;
 		case 4:break;
 		default:printf("invalid option\n");
 	}
 }while(op!=4);
 return 0;
}

