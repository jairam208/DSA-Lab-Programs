#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

int **a=0, n;
int* visited;

void create()
{
    int i, j;
    printf("Enter the number of vertices : ");
    scanf("%d", &n);
    visited=(int*)malloc(sizeof(int)*n);
    for(i=0; i<n; i++)
        visited[i]=0;
    a=(int**)malloc(sizeof(int*)*n);
    for(i=0; i<n; i++)
        a[i]=(int*)malloc(sizeof(int)*n);
    printf("Enter the values of adjacency matrix : \n");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d", &a[i][j]);
}

void DFS(int i)
{
    printf("%d", i);
    visited[i]=1;
    for(int j=0; j<n; j++)
        if(a[i][j]==1 && visited[j]!=1)
            DFS(j);
}

int main()
{
    int i, ch;
    while(1)
    {
        printf("1.Create\n2.DFS\n3.Exit\nEnter a choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1 : create(); break;
            case 2 : printf("Enter the starting node : ");
                     scanf("%d", &i);
                     DFS(i);
                     printf("\n");
                     for(i=0; i<n; i++)
                        visited[i]=0;
                     break;
            default : exit(0);
        }
    }
}