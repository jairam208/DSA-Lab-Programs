#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 4

void palin()
{
    char a[20];
    int start=0, top;
    printf("Enter the integer value : ");
    scanf("%s", a);
    top=strlen(a)-1;
    for(;start<top;)
        if(a[top--]!=a[start++])
        {
            printf("Not a Palindrome Number\n");
            return;
        }
        printf("Palindrome Number\n");
}

void push(int s[], int *top)
{
    int ele;
    if((*top)==MAX-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    (*top)++;
    printf("Enter the element : ");
    scanf("%d", &ele);
    s[(*top)]=ele;
}

void pop(int s[], int *top)
{
    if((*top)==-1)
        printf("Stack Underflow\n");
    else
    {
        printf("Element Popped is : %d\n", s[(*top)]);
        (*top)--;
    }
}

void display(int s[], int *top)
{
    int i;
    if((*top)==-1)
        printf("Stack Underflow\n");
    else
    {
        printf("Stack Elements are : \n");
        for(i=(*top); i>=0; i--)
            printf("%d\n", s[i]);
    }
}

int main()
{
    int ch, top=-1;
    int s[MAX];
    for(;;)
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Palindrome\n5.Exit\n");
        printf("Enter a choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1 : push(s, &top); break;
            case 2 : pop(s, &top); break;
            case 3 : display(s, &top); break;
            case 4 : palin(); break;
            default : exit(0);
        }
    }
}