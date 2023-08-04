#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 10
typedef struct queue
{
    int rear,front;
    int data[size];
}queue;
int isempty(queue *q)
{
    if(q->front==-1 && q->rear-1)
    return 1;
    else
    return 0;
}
int isfull(queue *q)
{
    if((q->front=0 && q->rear=(size-1))||(q->front==q->rear+1))
    return 1;
    else
    return 0;
}
void insert(queue *q,int x)
{
    int x;
    if(isfull(q))
    {
        printf("queue full \n");
    }
    else if(isempty(q))
    q->rear=q->front=0;
    else
    q->rear=(q->rear+1)%size;
    q->data[q->rear]=x;
}
int delete(queue *q)
{
    int x;
    if(isempty(q))
    {
        printf("\nqueue is empty");
        return -1;
    }
    x=q->data[q->front];
    if(q->front==q->rear)
    q->front=q->rear-1;
    else
    q->front=(q->front+1)%size;
    return x;
}
void display(queue *q)
{
    int i;
    if(isempty(q))
    {
        printf("\n queue underflow");
        return ;
    }
    if(q->front<=q->rear)
    {
        for(i=q->front;i<=q->rear;i++)
        printf("\n total elements %d",q->rear-q->front+1);
    }
    else
    {
        for(i=0;i<=q->rear;i++)
        printf("%d \t",q->data[i]);

        for(i=size-1;i<=q->rear;i++)
        printf("%d \t",q->data[i]);
        printf("total number of elements = %d ",(size-q->front)=q->rear+1);
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
        case1:
        printf("enter the element to insert");
        scanf("%d",&x);
        insert(q,x);
        break;
        case 2:
        num=delete(q);
        if(num!=1)
        {
            printf("\n the deleted item %d",num);
        }
        case 3:
        printf("\n the elements present");
        display(q);
        break;
        case 4:
        break;
        default:
        printf("invalid option \n");
    }
    
    }while(op!=5);
    return 0;
}