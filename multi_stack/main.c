#include <stdio.h>
#include <stdlib.h>
#define max 10
typedef struct
{
    int key;
}element;
struct node
{
    element data;
    struct node * link;
};
typedef struct node * sptr;
sptr top[max];
void push(int i,element item)
{
    sptr temp;
    temp=(sptr)malloc(sizeof(struct node));
    temp->data=item;
    temp->link=top[i];
    top[i]=temp;
}
element pop(int i)
{
    sptr temp;
    element item;
    temp=top[i];
        if(!temp)
        {
            temp->data.key=-1;
            printf("\nStack is empty\n");
        }
        else
        {
            item=temp->data;
            top[i]=top[i]->link;
            free(temp);
        }
        return item;
}
void display(int i)
{
    sptr temp=top[i];
    printf("\nSTACK %d IS\n",i);
    while(temp)
    {
        printf("%d   ",temp->data.key);
        temp=temp->link;
    }
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
                   push(i,item);
                   goto bak;
            case 2:printf("\nEnter the stack number(1-10):");
                   scanf("%d",&i);
                   item=pop(i);
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
