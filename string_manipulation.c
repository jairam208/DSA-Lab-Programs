#include<stdio.h>
#include<string.h>

int slen(char *s)
{
    int len=0;
    for(; s[len]!='\0'; len++);
    return len;
}

void replace(char *STR, char *PTR, char *REP, char *FIN)
{
    int k=0, q=0, l, z, s=slen(STR), r=slen(PTR);
    for(;k<s;)
    {
        for(l=0; l<r; l++)
            if(PTR[l]!=STR[k+l])
                break;
        if(l==r)
        {
            for(z=0; z<slen(REP); z++)
                FIN[q++]=REP[z];
            k=k+r;
        }
        else
            FIN[q++]=STR[k++];
    }
    FIN[q]='\0';
}

int main()
{
    char STR[50], PAT[50], REP[50], FIN[50];
    printf("Enter the String : ");
    scanf("%s", &STR);
    printf("Enter the Pattern String : ");
    scanf("%s", &PAT);
    printf("Enter the Replacement String : ");
    scanf("%s", &REP);
    replace(STR, PAT, REP, FIN);
    printf("The Final String is : %s\n", FIN);
}