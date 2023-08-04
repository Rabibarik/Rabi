#include<stdio.h>
#include<stdlib.h>
#define max 5 
typedef struct queue
{
    int front,rear;
    int arr[max];
}queue;
void init(queue *q)
{
    q->rear=-1;
    q->front=0;
}
int isfull(queue *q)
{
    if(q->rear==max-1)
    return 1;
    else
    return 0;
}
int isempty(queue *q)
{
    if(q->front>q->rear)
    return 1;
    else
    return 0;
}
void insert(queue *q,int ele)
{
    if(isfull(q))
    {
        printf("queue s full \n");
        exit(0);
    }
    else
    {
        q->rear++;
        q->arr[q->rear]=ele;
        printf("inserted element %d",ele);
    } 
}
int delete(queue *q,int ele)
{
    if(isempty(q))
    {
        printf("queue s empty \n");
        return 1;
    }
    else
    {
        ele=q->arr[q->front];
        q->front++;
        return ele;
    } 
}
void display(queue *q)
{
    int i;
    if(isempty(q))
    printf("sack is empty \n");
    else
    {
        for(i=q->front;i<=q->rear;i++)
        printf("%d \n",q->arr[i]);
    }
}
int count(queue *q)
{
    int i,count=0;
    if(isempty(q))
    {
    printf("sack is empty \n");
    }
    else
    {
        for(i=q->front;i<=q->rear;i++)
        count++;
    }
    return count;
}
int main()
{
    queue q;
    int ch,num=0,ele;
    init(&q);
    do
    {
        printf("1.enque \n2.deque \n3.display \n4.exit \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("insetr the element \n");
            scanf(" %d ",&ele);
            insert(&q,ele);
            break;
            case 2:
            ele=delete(&q,ele);
            printf("element deleted %d \n",ele);
            break;
            case 3:
            display(&q);
            break;
            case 4:
            num=count(&q);
            printf("no of element %d \n",num);
            break;
            case 5:
            exit(0);
            default:
            printf("incorect choice \n");
            break;
        }
    }while(ch!=5);
    return 0;
}