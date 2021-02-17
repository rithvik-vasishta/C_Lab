#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int key;
}element;
struct q
{
    element data;
    struct q * link;
};
typedef struct q * qptr;
qptr f[10],r[10];
void add(int i,element item)
{
    qptr temp;
    temp=(qptr)malloc(sizeof(struct q));
    temp->data=item;
    temp->link=NULL;
    if(f[i])
        r[i]->link=temp;
    else
        f[i]=temp;
    r[i]=temp;
}
element del(int i)
{
    qptr temp;
    element item;
    temp=f[i];
    if(!temp)
    {
        temp->data.key==-1;
        printf("\n%d QUEUE IS EMPTY \n",i);
    }
    else
    {
        item=temp->data;
        f[i]=temp->link;
        free(temp);
    }
    return item;
}
void display(int i)
{
    qptr p;
    printf("\nQUEUE %d IS ",i);
    for(p=f[i];p;p=p->link)
        printf("%d     ",p->data.key);
}
int main()
{
    element item;
    int c;int i;
    bak:
        printf("\nEnter 1 to push,2 to pop,3 to display and 4 to exit:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("\nEnter the stack number(1-10):");
                   scanf("%d",&i);
                   printf("\nEnter the element:");
                   scanf("%d",&item.key);
                   add(i,item);
                   goto bak;
            case 2:printf("\nEnter the stack number(1-10):");
                   scanf("%d",&i);
                   item=del(i);
                   if(item.key==-1){}
                   printf("\nThe element deleted is :%d",item.key);
                   goto bak;
            case 3:printf("\nEnter the stack number(1-10):");
                   scanf("%d",&i);
                   display(i);
                   goto bak;
            default:exit(0);
        }
        return 0;
}
