#include<stdio.h>
#include<stdlib.h>
#define HZ 3

FILE* fp;

struct employee
{
    int empno;
    char name[20];
    int sal;
};
typedef struct employee emp;

struct hashtable
{
    int key; // empno; unique key value
    long int addr; // OFFSET address in flie
};
typedef struct hashtable ht;

int hashval(int num)
{
    int key;
    key=num%HZ; // division method, being used to calculate hash value
    return key;
}

void search(ht* h, int n)
{
    emp a;
    int hindex, countindex;
    printf("Enter Employee Number to search : ");
    scanf("%d", &(a.empno));
    hindex=hashval(a.empno);
    countindex=hindex;
    while(h[hindex].key!=a.empno)
    {
        hindex=(hindex+1)%HZ;
        if(countindex==hindex)
        {
            printf("Search Unsuccessful\n");
            return;
        }
    }
    printf("Search Successful\n");
    fseek(fp, h[hindex].addr, SEEK_SET);
    // fread(&a, sizeof(emp), 1, fp); // stores info in binary format
    fscanf(fp, "%d%s%d", &(a.empno), a.name, &(a.sal));
    printf("%d%s%d\n", a.empno, a.name, a.sal);
}

void display(ht* h, int n)
{
    emp a;
    int i;
    for(i=0; i<HZ; i++)
    {
        if(h[i].key!=-1)
        {
            printf("Hash Table : %d %d\n", h[i].key, h[i].addr);
            fseek(fp, h[i].addr, SEEK_SET);
            // fread(&a, sizeof(emp), 1, fp);
            fscanf(fp, "%d%s%d", &(a.empno), a.name, &(a.sal));
            printf("The Contents in secondary storage are : \n%d %s %d\n", a.empno, a.name, a.sal);
        }
    }
}

void insert(ht* h, int n)
{
    emp a; int flag=0;
    int i, hindex, countindex;
    for(i=0; i<n; i++, flag=0)
    {
        printf("Enter the employee number, name and salary : \n");
        scanf("%d%s%d", &(a.empno), a.name, &(a.sal));
        hindex=hashval(a.empno);
        countindex=hindex;
        while(h[hindex].key!=-1)
        // checking whether hindex position in h is empty
        {
            hindex=(hindex+1)%HZ;
            flag=1;
            if(hindex=countindex)
            {
                printf("Entry not possible\n");
                return;
            }
        }
        h[hindex].key=a.empno;
        fseek(fp, 0, SEEK_END);
        h[hindex].addr=ftell(fp);
        // fwrite(&a, sizeof(emp), 1, fp);
        fprintf(fp, "%d%s%d", a.empno, a.name, a.sal);
        printf("Entry Successful\n");
        if(flag)
            printf("Linear Probing used\n");
    }
}

int main()
{
    ht h[HZ];
    emp d;
    int n, ch;
    fp=fopen("emp.txt", "w+");
    for(n=0; n<HZ; n++)
        h[n].key=-1;
    for(;;)
    {
        printf("1.Insert\n2.Search\n3.Display\n4.Exit\n");
        printf("Enter a choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1 : printf("Enter the number of employees : ");
                     scanf("%d", &n);
                     insert(h, n);
                     break;
            case 2 : search(h, n); break;
            case 3 : display(h, n); break;
            default : exit(0);
        }
    }
}