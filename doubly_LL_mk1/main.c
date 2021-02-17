#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node * llink;
    struct node * rlink;
};
typedef struct node * nptr;
void add(int item,nptr head)
{
    nptr temp;
    temp=(nptr)malloc(sizeof(struct node));
    temp->key=item;
    temp->llink=head;
    temp->rlink=head->rlink;
    (head->rlink)->llink=temp;
    head->rlink=temp;
    head=temp;
}
void dispr(nptr head)
{
    head=head->rlink;
    if(head==NULL)
    {
        printf("\nLIST IS EMPTY\n");
        return;
    }
    while((head->rlink)->key!=-1)
    {
        printf("%d\t",head->key);
        head=head->rlink;
    }
    if(head->key!=-1)
         printf("%d\t",head->key);
    else
        printf("\nEMPTY LIST\n");
}
void dispf(nptr head)
{
    head=head->llink;
    if(head==NULL)
    {
        printf("\nLIST IS EMPTY\n");
        return;
    }
     while((head->llink)->key!=-1)
    {
        printf("%d\t",head->key);
        head=head->llink;
    }
   if(head->key!=-1)
         printf("%d\t",head->key);
    else
        printf("\nEMPTY LIST\n");


}
void del(int item,nptr head)
{
    if(head==NULL)
    {
        printf("\nTHERE IS NOTHING TO DELETE\n");
        return;
    }
    head=head->rlink;
    if(head->key==-1)
    {
        printf("\nHEADER NODE CANNOT BE DELETED\n");
        return;
    }
    while(head->key!=-1)
    {
        if(head->key==item)
        {
            printf("%d deleted from the list\n",item);
            if(head->rlink)
                (head->llink)->rlink=head->rlink;
            if(head->llink)
                (head->rlink)->llink=head->llink;
            return;
        }
        head=head->rlink;
    }printf("\n%d NOT FOUND\n",item);
}
int main()
{
    int c,ele;
    nptr first;
    first=(nptr)malloc(sizeof(struct node));
    first->key=-1;
    first->llink=first;
    first->rlink=first;
    while(1)
    {
        printf("\nEnter 1 to add,2 to delete,3 to display from front,4 to display from back:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("\nEnter the element to be added: ");
                   scanf("%d",&ele);
                   add(ele,first);
                   break;
            case 2:printf("\nEnter the element to be deleted: ");
                   scanf("%d",&ele);
                   del(ele,first);
                   break;
            case 3:printf("\nLIST FROM FRONT IS:\n");
                   dispf(first);
                   break;
            case 4:printf("\nLIST FROM BACK IS:\n");
                   dispr(first);
                   break;
            default:exit(0);
        }
    }return 0;
}
