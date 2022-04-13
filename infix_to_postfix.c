#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 30

int f(char s)
{
    switch(s)
    {
        case '+' :
        case '-' : return 2;
        case '*' :
        case '/' : return 4;
        case '$' :
        case '^' : return 5;
        case '(' : return 0;
        case '#' : return -1;
        default : return 8;
    }
}

int g(char s)
{
    switch(s)
    {
        case '+' :
        case '-' : return 1;
        case '*' :
        case '/' : return 3;
        case '$' :
        case '^' : return 6;
        case '(' : return 9;
        case ')' : return 0;
        default : return 7;
    }
}

int main()
{
    char c, s[MAX]={'#'};
    char inf[MAX], pf[MAX];
    int top=0, i, j=0;
    printf("Enter the Infix Expression : ");
    scanf("%s", inf);
    for(i=0; i<strlen(inf); i++)
    {
        //c=inf[i];
        while(f(s[top])>g(inf[i]))
        {
            pf[j++]=s[top--];
            //j++;
            //top--;
        }
        if(f(s[top])!=g(inf[i]))
            s[++top]=inf[i]; 
        else
            top--;
    }
    for(; top>0; top--)
        pf[j++]=s[top];
    pf[j]='\0';
    printf("The Postfix Expression is : %s\n", pf);
}