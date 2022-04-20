#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *llink, *rlink;
    int info;
};
typedef struct node nd;

nd*insert(nd* root, int key)
{
    nd* cur=root, *prev=0;
    nd* t=(nd*)malloc(sizeof(nd));
    t->info=key;
    t->llink=t->rlink=0;
    if(!cur)
        return t;
    while(cur)
    {
        if(t->info==cur->info)
        {
            printf("Redundancy\n");
            free(t);
            return root;
        }
        prev=cur;
        if(t->info<cur->info)
            cur=cur->llink;
        else
            cur=cur->rlink;
    }
    if(t->info<prev->info)
        prev->llink=t;
    else
        prev->rlink=t;
    return root;
}

void recursearch(nd* root, int key)
{
    if(!root)
    {
        printf("Unsuccessful Search\n");
        return;
    }
    if(key==root->info)
    {
        printf("Successful Search\n");
        return;
    }
    if(key<root->info)
        return recursearch(root->llink, key);
    return recursearch(root->rlink, key);
}

void inorder(nd* r)
{
    if(r)
    {
        inorder(r->llink);
        printf("%d\n", r->info);
        inorder(r->rlink);
    }
}

void postorder(nd* r)
{
    if(r)
    {
        postorder(r->llink);
        postorder(r->rlink);
        printf("%d\n", r->info);
    }
}

void preorder(nd* r)
{
    if(r)
    {
        printf("%d\n", r->info);
        preorder(r->llink);
        preorder(r->rlink);
    }
}

int main()
{
    nd* root=0;
    int ch, key, i, n;
    while(1)
    {
        printf("1.Insert\n2.Search\n3.Inorder\n4.Preorder\n5.Postorder\n6.Exit\n");
        printf("Enter a choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1 : printf("Enter the number of nodes : ");
                     scanf("%d", &n);
                     for(i=0; i<n; i++)
                     {
                         printf("Enter the node value : ");
                         scanf("%d", &key);
                         root=insert(root, key);
                     }
                     break;
            case 2 : printf("Enter the value to search : ");
                     scanf("%d", &key);
                     recursearch(root, key);
                     break;
            case 3 : inorder(root); break;
            case 4 : preorder(root); break;
            case 5 : postorder(root); break;
            default : exit(0);
        }
    }
}