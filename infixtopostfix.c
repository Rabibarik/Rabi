#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100
typedef struct st
{
    char list[max];
    int top;
}stack;
void infix_postfix(char* ,stack* ,char* );
void stackini(stack *sptr)
{
    sptr->top=-1;
}
int isfull(stack* sptr)
{
    if(sptr->top==max-1)
    return 1;
    else
    return 0;
}
int isempty(stack *sptr)
{
    if(sptr->top==-1)
    return 1;
    else
    return 0;
}
void push(stack *sptr,char item)
{
    int x;
    if(isfull(sptr)
    printf(" stack is full \n");
    else
    {
        sptr->top++;
        sptr->list(sptr->top)=item;
    }
}
char pop(stack *sptr)
{
    int x;
    char temp;
    if(isempty(sptr))
    {
        printf("stack is underflow \n");
        return '\0'
    }
    else
    {
        temp=sptr->list(sptr->top);
        sptr->top--;
        return temp;
}
