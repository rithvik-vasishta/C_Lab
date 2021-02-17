#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int key;
}element;
element *q=NULL;
int f=0;
int r=0;
int k=0;
int max=1;
void copy(int a,int b,element *nq)
{
    int i;
    for(i=a;i<b;i++)
        nq[k++].key=q[i].key;
}
void qfull()
{
    k=0;
    int start;
    element *nq;
    nq=(element *)malloc(2*max*sizeof(element));
    start=(f+1)%max;
    if(start<2)
        copy(start,start+max-1,nq);
    else
    {
        copy(start,max,nq);
        copy(0,0+r+1,nq);
    }
    f=2*max-1;
    r=max-1;
    max*=2;
    free(q);
    q=nq;
}
void addq(element x)
{
    r=(r+1)%max;
    if(r==f)
        qfull();
    q[r]=x;
}
element deleteq()
{
    if(f==r)
    {
        element k;
        k.key=-1;
        printf("\nQUEUE IS EMPTY\n");
        return k;
    }
    else
    {
        f=(f+1)%max;
        return q[f];
    }
}
void display()
{
    if(f==r)
        printf("\nQUEUE IS EMPTY\n");
    else if(r==0)
        printf("\n%d\n",q[r].key);
    else
    {
        int i;
        for(i=(f+1)%max;i<(r+1)%max;i=(i+1)%max)
            printf("\n%d\n",q[i].key);
    }
}
int main()
{
    element x;
    int choice;
    q=(element *)malloc(sizeof(element));
    bak:
        printf("\nEnter 1 for adding,2 for deleting,3 for display: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("\nEnter the element: ");
                scanf("%d",&x.key);
                addq(x);
                goto bak;
                break;
            case 2:x=deleteq();
            if(x.key==-1)
            {
            }
            else
            {


                   printf("\nThe deleted element is: %d",x.key);}
                   goto bak;
                   break;
            case 3:display();
                        goto bak;
                        break;
            default:printf("\nINVALID CHOICE:");
                     exit(0);
        }
        return 0;
}
