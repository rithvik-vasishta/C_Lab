#include <stdio.h>
#include <stdlib.h>
#define max 20
struct node
{
    int key;
};
typedef struct node element;
element heap[max];
void insert(element item,int *n)
{
    int i;
    if((*n)==max-1)
    {
        printf("\nHEAP FULL\n");
        return;
    }
    i=++(*n);
    while(i!=1&&(item.key>heap[i/2].key))
    {
        heap[i]=heap[i/2];
        i/=2;
    }
    heap[i]=item;
}
element del(int *n)
{
    element item,temp;
    int parent,child;
    if((*n)==0)
    {
        printf("\nHEAP EMPTY\n");
        item.key=-1;
        return item;
    }
    item=heap[1];
    temp=heap[(*n)--];
    parent=1;
    child=2;
    while(child<=*n)
    {
        if(child<*n&&heap[child].key<heap[child+1].key)
            child++;
        if(temp.key>=heap[child].key)
            break;
        heap[parent]=heap[child];
        parent=child;
        child*=2;
    }
    heap[parent]=temp;
    return item;

}
void display(int n)
{
int i;
    for(i=1;i<=n;i++)
    {
        printf("%d\n",heap[i].key);
    }
}
int main()
{
    int c;
    int n=0;
    element item;
    while(1)
    {
        printf("\nEnter 1 to insert,2 to delete and 3 to display: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("\nEnter th element: ");
                   scanf("%d",&item.key);
                   insert(item,&n);
                   break;
            case 2:item=del(&n);
                   if(item.key!=-1)
                    printf("\nThe deleted item is:%d",item.key);
                   break;
            case 3:printf("\nTHE LIST IS:\n");
                   display(n);
                   break;
            default:exit(0);
        }
    }
}
