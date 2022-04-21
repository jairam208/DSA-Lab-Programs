#include<stdio.h>
#include<stdlib.h>

struct emp
{
    char ssn[10], name[20], dept[10], design[20], phno[10];
    float sal;
    struct emp *llink;
    struct emp *rlink;
};
typedef struct emp nd;

nd* create()
{
    nd* t=(nd*)malloc(sizeof(nd));
    t->llink=t->rlink=NULL;
    printf("Enter the employee details : \n");
    printf("SSN : ");
    scanf("%s", t->ssn);
    printf("Name : ");
    scanf("%s", t->name);
    printf("Department : ");
    scanf("%s", t->dept);
    printf("Designation : ");
    scanf("%s", t->design);
    printf("Phone Number : ");
    scanf("%s", t->phno);
    printf("Salary : ");
    scanf("%f", &(t->sal));
    return t;
}

int count(nd* h)
{
    nd* t=h;
    int cnt=0;
    while(t!=NULL)
    {
        cnt++;
        t=t->rlink;
    }
    return cnt;
}

void display(nd* h)
{
    nd* t=h;
    int cnt=0;
    printf("The Employees List is : \n");
    while(t!=NULL)
    {
        printf("%s %s %s %s %s %.2f", t->ssn, t->name, t->dept, t->design, t->phno, t->sal);
        t=t->rlink;
    }
}

nd* insert_front(nd* h)
{
    nd* t=create();
    if(h==NULL)
    {
        return t;
    }
    t->rlink=h;
    return t;
}

nd* insert_rear(nd* h)
{
    nd *t=create();
    if(h==NULL)
    {
        return t;
    }
    nd* p=h;
    while(p->rlink!=NULL)
    {
        p=p->rlink;
    }
    p->rlink=t;
    t->llink=p;
    return h;
}

nd* delete_front(nd* h)
{
    if(h==NULL)
    {
        printf("Deletion not possible\n");
        return h;
    }
    nd* p=h;
    printf("The deleted information is : \n%s %s %s %s %s %.2f", h->ssn, h->name, h->dept, h->design, h->phno, h->sal);
    h=p->rlink;
    return h;
}

nd* delete_rear(nd* h)
{
    if(h==NULL)
    {
        printf("Deletion not possible\n");
        return h;
    }
    if(h->rlink==NULL)
    {
        printf("The deleted information is : \n%s %s %s %s %s %.2f\n", h->ssn, h->name, h->dept, h->design, h->phno, h->sal);
        return NULL;
    }
    nd* p=h;
    while(p->rlink->rlink!=NULL)
    {
        p=p->rlink;
    }
    printf("The deleted information is : \n%s %s %s %s %s %.2f\n", p->rlink->ssn, p->rlink->name, p->rlink->dept, p->rlink->design, p->rlink->phno, p->rlink->sal);
    p->rlink=NULL;
    return h;
}

int main()
{
    nd* h=NULL;
    int ch;
    while(1)
    {
        printf("1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Count\n6.Display\n7.Exit\n");
        printf("Enter a choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1 : h=insert_front(h); break;
            case 2 : h=insert_rear(h); break;
            case 3 : h=delete_front(h); break;
            case 4 : h=delete_rear(h); break;
            case 5 : printf("%d\n", count(h)); break;
            case 6 : display(h); break;
            default : exit(0);
        } 
    }
}
