#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    struct node * llink;
    struct node * rlink;

};
typedef struct node * treeptr;
void insert(treeptr *root,int d)
{
    if((*root)==NULL)
    {
        (*root)=(treeptr)malloc(sizeof(struct node));
        (*root)->key=d;
        (*root)->llink=NULL;
        (*root)->rlink=NULL;
    }
    else if(d>((*root)->key))
            insert(&((*root)->rlink),d);
            else if(d<((*root)->key))

            insert(&((*root)->llink),d);
}
void inorder(treeptr root)
{
    if(root!=NULL)
    {
        inorder(root->llink);
        printf("%d\t",root->key);
        inorder(root->rlink);
    }
}
int search(treeptr root,int d)
{
    if(root==NULL)
        return 0;
    else if(root->key==d)
        return 1;
    else if(d>root->key)
        return search(root->rlink,d);
    else if(d<root->key)
        return search(root->llink,d);
}
int main()
{
    int c,data;
    treeptr root=NULL;
    while(1)
    {
        printf("\nEnter 1 to insert,2 to search,3 to display in inorder:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("\nEnter the element:");
                           scanf("%d",&data);
                           insert(&root,data);
                           break;
            case 2:printf("\nEnter the element to be searched:");
                         scanf("%d",&data);
                         if(search(root,data))
                            printf("\nDATA FOUND\n");
                         else
                            printf("\nDATA NOT FOUND\n");
                         break;
            case 3:inorder(root);
                        break;
            default:exit(0);
        }
    }return 0;
}
