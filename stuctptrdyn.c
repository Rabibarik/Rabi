#include<stdio.h>
#include<stdlib.h>
struct student
{
    int roll;
    char name[30];
    char branch [30];

};
void getdata(struct student *,int );
void printdata(struct student *,int );
int main()
{
    struct student *ptr;
    int n;
    printf("enter how many students: ");
    scanf("%d",&n);
    ptr=(struct student *)malloc(n*sizeof(struct student));
    getdata(ptr,n);
    printdata(ptr,n);
}
void getdata(struct student *ptr,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("enter roll: ");
        scanf("%d",&(ptr+i)->roll);
        printf("enter name: ");
        scanf("%s",(ptr+i)->name);
        printf("enter branch: ");
        scanf("%s",(ptr+i)->branch);
    }
}
void printdata(struct student *ptr, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d \n",(ptr+i)->roll);
        printf("%s \n",(ptr+i)->name);
        printf("%s \n",(ptr+i)->branch);
    }
}