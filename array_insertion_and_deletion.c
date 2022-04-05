#include<stdio.h>
#include<stdlib.h>

void accept(int *p, int *n)
{
    int i;
    printf("Enter the array size : ");
    scanf("%d", n);
    printf("Enter the elements of array : \n");
    for(i=0; i<*n; i++)
        scanf("%d", &p[i]);
}

void display(int *p, int n)
{
    int i;
    printf("Contents of array are : \n");
    for(i=0; i<n; i++)
        printf("%d\n", p[i]);
}

void insert_at_pos(int *p, int *n)
{
    int ele, pos, i;
    printf("Enter the value of POS : ");
    scanf("%d", &pos);
    if(pos<=0 || pos>=((*n)+1))
    {
        printf("Invalid position\n");
        return;
    }
    printf("Enter the value of ele : ");
    scanf("%d", &ele);
    for(i=(*n)-1; i>=(pos-1); i--)
        p[i+1]=p[i];
    p[pos-1]=ele;
    (*n)++;
}

void delete_at_pos(int *p, int *n)
{
    int pos, i;
    printf("Enter the value of POS : ");
    scanf("%d", &pos);
    if(pos<=0 || pos>(*n))
    {
        printf("Invalid position\n");
        return;
    }
    for(i=pos-1; i<((*n)-1); i++)
        p[i]=p[i+1];
    (*n)--;
}

int main()
{
    int a[20], n=0, ch;
    for(;;)
    {
        printf("1.Enter the value for array\n2.Display\n3.Insert at POS\n4.Delete at POS\n5.Exit\n");
        printf("Enter the choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1 : accept(a, &n); break;
            case 2 : display(a, n); break;
            case 3 : insert_at_pos(a, &n); break;
            case 4 : delete_at_pos(a, &n); break;
            default : exit(0);
        }
    }
}