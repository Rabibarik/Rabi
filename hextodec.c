#include<stdio.h>
#define max 20
typedef struct stack
{
    char item[max];
    int top;
}stack;
void init(stack *);
void push(stack *,int );
int pop(stack *);
int main()
{
    int no,rem;
    char ch;
    stack st;
    init(&st);
    printf("\n enter the decimal no: ");
    scanf("%d",&no);
    while(no>0)
    {
        rem=no%16;
        if(rem<=9)
        push(&st,(rem+48));
        else
        {
        push(&st,((rem-10)+65));
        }
        no=no/16;
    }
    while((ch=pop(&st)!=-1))
    {
        printf("%c",ch);
    }
    return 0;
}
void init(stack *st)
{
    st->top=-1;
}
void push(stack *st, int data)
{
    if(st->top==(max-1))
    {
        printf("\n stack overflow(stack is full)");
        return;
    }
    else
    {
        st->top++;
        st->item[st->top]=data;
    }
}
int pop(stack *st)
{
    int temp;
    if(st->top==-1)
    {
        printf("\n stack is empty");
        return -1;
    }
    else
    {
        temp=st->item[st->top];
        st->top--;
    }
    return temp;
}