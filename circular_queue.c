#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void insert(int *q, int *r, int *cnt)
{
    int ele;
    if((*cnt)==MAX)
    {
        printf("Circular Queue Qverflow\n");
        return;
    }
    (*r)=((*r)+1)%MAX;
    printf("Enter the element : ");
    scanf("%d", &ele);
    q[(*r)]=ele;
    (*cnt)++;
}

void delete(int *q, int *f, int *cnt)
{
    if((*cnt)==0)
    {
        printf("Circular Queue Empty\n");
        return;
    }
    printf("Element deleted from Circular Queue is : %d\n", q[(*f)]);
    (*f)=((*f)+1)%MAX;
    (*cnt)--;
}

void display(int *q, int f, int cnt)
{
    int i, j;
    if(cnt==0)
    {
        printf("Circular Queue is Empty\n");
        return;
    }
    printf("The contents of Circular Queue are :\n");
    for(i=f, j=0; j<cnt; j++)
    {
        printf("%d : %d\n", j+1, q[i]);
        i=(i+1)%MAX;
    }
}

int main()
{
    int q[MAX];
    int r=-1, f=0, cnt=0, ch;
    while(1)
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter a choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1 : insert(q, &r, &cnt); break;
            case 2 : delete(q, &f, &cnt); break;
            case 3 : display(q, f, cnt); break;
            default : exit(0);
        }
    }
}