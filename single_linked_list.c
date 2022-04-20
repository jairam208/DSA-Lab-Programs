#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    char usn[10], name[20], branch[20];
    int sem, phno;
};
typedef struct student data;

struct sll
{
    data d;
    struct sll *link;
};
typedef struct sll nd;

nd* insert_front(nd *f)
{
    nd *t;
    t=(nd*)malloc(sizeof(nd));
    printf("Enter Student USN : ");
    scanf("%s", t->d.usn);
    printf("Enter Student Name : ");
    scanf("%s", t->d.name);
    printf("Enter Branch : ");
    scanf("%s", t->d.branch);
    printf("Enter Semester : ");
    scanf("%d", &(t->d.sem));
    printf("Enter Phone Number : ");
    scanf("%d", &(t->d.phno));
    t->link=0;
    if(f==0)
        return t;
    t->link=f;
    return t;
}

nd* insert_rear(nd *f)
{
    nd *t, *last;
    t=(nd*)malloc(sizeof(nd));
    printf("Enter Student USN : ");
    scanf("%s", t->d.usn);
    printf("Enter Student Name : ");
    scanf("%s", t->d.name);
    printf("Enter Branch : ");
    scanf("%s", t->d.branch);
    printf("Enter Semester : ");
    scanf("%d", &(t->d.sem));
    printf("Enter Phone Number : ");
    scanf("%d", &(t->d.phno));
    t->link=0;
    if(f==0)
        return t;
    for(last=f; last->link!=0; last=last->link);
    last->link=t;
    return f;
}

nd* delete_front(nd *f)
{
    if(f==0)
    {
        printf("Empty List\n");
        return 0;
    }
    nd *t;
    t=f->link;
    printf("The deleted student details are : \n");
    printf("%s %s %s %d %d\n", f->d.usn, f->d.name, f->d.branch, f->d.sem, f->d.phno);
    free(f);
    return t;
}

nd* delete_rear(nd *f)
{
    if(f==0)
    {
        printf("Empty List\n");
        return 0;
    }
    if(f->link==0)
    {
        printf("The deleted student details are : \n");
        printf("%s %s %s %d %d\n", f->d.usn, f->d.name, f->d.branch, f->d.sem, f->d.phno);
        free(f);
        return 0;
    }
    nd *p, *c;
    for(c=0, p=f; p->link!=0; c=p, p=p->link);
    printf("The deleted student details are : \n");
    printf("%s %s %s %d %d\n", p->d.usn, p->d.name, p->d.branch, p->d.sem, p->d.phno);
    c->link=0;
    free(f);
    return f;
}

void display(nd *f)
{
    if(f==0)
    {
        printf("Empty List\n");
        return;
    }
    nd *t;
    printf("The contents of the list are : \n");
    for(t=f; t!=0; t=t->link)
        printf("%s %s %s %d %d\n", t->d.usn, t->d.name, t->d.branch, &(t->d.sem), &(t->d.phno));
}

int main()
{
    int n, ch;
    nd *head=0;
    while(1)
    {
        printf("1.Insert\n2.Insert Front\n3.Insert Rear\n4.Delete Front\n5.Delete Rear\n6.Display\n7.Exit\n");
        printf("Enter a choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1 : printf("Enter the number of students : ");
                     scanf("%d", &n);
                     printf("Enter the student details : \n");
                     for(int i=0; i<n; i++)
                        head = insert_front(head);
                     break;
            case 2 : head = insert_front(head); break;
            case 3 : head = insert_rear(head); break;
            case 4 : head = delete_front(head); break;
            case 5 : head = delete_rear(head); break;
            case 6 : display(head); break;
            default : exit(0);
        }
    }
}
