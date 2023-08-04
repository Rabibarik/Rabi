#include<stdio.h>
#include<stdlib.h>
struct student
{
    int roll;
    char name[20];
    char branch[30];
};
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
void printdata(struct student *ptr,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",(ptr+i)->roll );
        printf("%s ",(ptr+i)->name );
        printf("%s ",(ptr+i)->branch );
    }
}
int main()
{
    struct student *ptr;
    struct student s[20];
    int n;
    printf("enter how many structures: ");
    scanf("%d",&n);
    getdata(ptr,n);
    printdata(ptr,n);
}
    