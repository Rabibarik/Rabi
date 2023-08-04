#include<stdio.h>
#include<stdlib.h>
#define m 10
typedef struct stack
{
    int top;
    char a[m];
}stack;
void push(stack *s,char x)
{
    if(s->top==m-1)
    printf("\n stack overflow \n");
    else
    {
        s->top++;
        s->a[s->top]=x;
    }
}
char pop(stack *s)
{
    char d;
    if(s->top==-1)
    printf("\n stack underflow");
    else
    {
        d=s->a[s->top];
        s->top--;
        return d;
    }
}
int main()
{
    int counter = 1,i,j,l;
    stack s;
    char x,str[10],d;
    s.top=-1;
    printf("\n enter the string");
    gets(str);
    for(i=0;str[i]!='\0';i++)
    {
        push(&s,str[i]);
    }
    for(j=0;str[j]!='\0';j++)
    {
        d=pop(&s);
        printf("poped character =%c,character from string is %c",d,str[j]);
        if(d!=str[j])
        {
            counter=0;
            break;
        }
    }

    if(counter==1)
    printf("\n the string is palindrome");
    else
    printf("\n the string is not palindrome");
    return 0;
}