#include <stdio.h>
#include <stdlib.h>
#define MAX 101
typedef struct{
int row;
int col;
int val;
}term;
void input(term a[])
{
    int A[100][100],i,j,m,n,c;
    printf("Enter the number of rows and columns: ");
    scanf("%d%d",&m,&n);
    printf("\nEnter the matrix: ");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
    scanf("%d",&A[i][j]);
    c=1;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            if(A[i][j]!=0)
            {
                a[c].row=i;
                a[c].col=j;
                a[c].val=A[i][j];
                c++;

            }

        }
        a[0].row=m;
        a[0].col=n;
        a[0].val=c-1;
}
void transpose(term a[],term b[])
{
    printf("THIS IS NORMAL TRANSPOSE:\n");
    int i,j,k,n;
    n=a[0].val;
    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].val=a[0].val;
    k=1;
    if(n>0)
    {
        for(i=0;i<a[0].col;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(a[j].col==i)
                {
                    b[k].row=a[j].col;
                    b[k].col=a[j].row;
                    b[k].val=a[j].val;
                    k++;
                }
            }
        }
    }
}
void output(term k[])
{
    int i,n;
    n=k[0].val;
    for(i=0;i<=n;i++)
        printf("\n%d\t%d\t%d\n",k[i].row,k[i].col,k[i].val);
}
void fast(term a[],term b[])
{
    printf("THIS IS FAST TRANSPOSE:\n");
    int RT[MAX],SP[MAX],i,j,nc,nt;
    nc=a[0].col;
    nt=a[0].val;
    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].val=nt;
    if(nt>0)
{

    for(i=0;i<nc;i++)
        RT[i]=0;
    for(i=1;i<=nt;i++)
        RT[a[i].col]++;
    SP[0]=1;
    for(i=1;i<nc;i++)
        SP[i]=SP[i-1]+RT[i-1];
    for(i=1;i<=nt;i++)
    {
        j=SP[a[i].col]++;
        b[j].row=a[i].col;
        b[j].col=a[i].row;
        b[j].val=a[i].val;
    }
}
}
int main()
{
    term a[MAX],b[MAX];int choice;

    printf("\nEnter the matrix: \n");
    input(a);
    printf("Enter 1 for normal transpose,2 for fast transpose: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:transpose(a,b);break;
        case 2:fast(a,b);break;
        default:printf("\nInvalid choice:\n");
    }
    output(b);
    return 0;
}
