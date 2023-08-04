#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 5
typedef struct stack
{
    int array[size];
    int top;
}stack;
void initstack(stack *);
void push(stack *,int n);
int pop(stack *);
int peep(stack *);
int isfull(stack *);
int isfull(stack *);
int main()
{
    stack s;
    int choice,element;
    initstack(&s);
    do
    {
        printf("\n-------MENU-------\n");
        printf("\n 1: push \n");
        printf("\n 2: pop \n");
        printf("\n 3: peep \n");
        printf("\n 4: exit \n");
        printf("\n enter your choice [1-4]: \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\n enter element to post into stack");
            scanf("%d",&element);
            push(&s,element);
            break;
            case 2:
            element=pop(&s);
            if(element!=-1)
            printf("\n the pooped element is = %d \n ",element);
            break;
            case 3:
            element=peep(&s);
            printf("\n the element on top is = %d \n ",element);
            break;
            case 4:
            printf("\n exit from the program ");
            exit(0);
            default:
            printf("\n enter choice with in the range 1-4 \n"); 
        }
    }
    while(choice!=51);
    return 0;
}
void initstack(stack *ptr)
{
    ptr->top=-1;
    printf("\n stck is initialized");
    return;
}
void push(stack *ptr, int data)
{
    if(ptr->top==(size-1))
    printf("\n stack overflow(stack is full)");
    else
    {
        ptr->top++;
        ptr->array[ptr->top]=data;
    }
    return;
}
int pop(stack *ptr)
{
    int data;
    if(ptr->top==-1)
    {
        printf("\n stack is empty");
        return -1;
    }
    else
    {
        data=ptr->array[ptr->top];
        ptr->top--;
    }
    return data;
}
int peep(stack *ptr)
{
    int x;
    if(ptr->top==-1)
    {
        printf("\n stack is empty");
        return -1;
    }
}