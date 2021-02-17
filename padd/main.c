#include <stdio.h>
#include <stdlib.h>
#define compare(x,y) ((x)>(y))?(1):((x)==(y))?(0):(-1)
typedef struct
{
    int coef;
    int expo;

}terms;
terms term[100];
int avail;int f;
void attach(int,int);
void padd(int sa,int fa,int sb,int fb,int *sd,int *fd)
{
    *sd=avail;
    while((sa<=fa)&&(sb<=fb))
    {
        switch(compare(term[sa].expo,term[sb].expo))
        {
            case 1:attach(term[sa].coef,term[sa].expo);
                   sa++;break;
            case -1:attach(term[sb].coef,term[sb].expo);
                   sb++;break;
            case 0:f=term[sa].coef+term[sb].coef;
                    if(f)
                            attach(f,term[sa].expo);
                            sa++;
                            sb++;


        }
    }
    for(;sa<=fa;sa++)
        attach(term[sa].coef,term[sa].expo);
    for(;sb<=fb;sb++)
        attach(term[sb].coef,term[sb].expo);
        *fd=avail-1;
}
void attach(int x,int y)
{
    term[avail].coef=x;
    term[avail].expo=y;
    avail++;
}
void main()
{
    int sa,fa,sb,fb,sd,fd,i;
    sa=0;
    printf("How many terms in A polynomial?: ");
    scanf("%d",&fa);
    fa--;
    sb=fa+1;
    printf("How many terms in B polynomial?: ");
    scanf("%d",&fb);
    fb=fa+fb;
    printf("Enter the polynomial A: \n");
     for(i=sa;i<=fa;i++)
       {
           scanf("%d",&term[i].coef);
           scanf("%d",&term[i].expo);
       }
     printf("Enter the polynomial B: \n");
     for(i=sb;i<=fb;i++)
       {
           scanf("%d",&term[i].coef);
           scanf("%d",&term[i].expo);
       }
    avail=fb+1;
    padd(sa,fa,sb,fb,&sd,&fd);
    for(i=sd;i<fd;i++)
        printf("( %d x ^ %d  ) +",term[i].coef,term[i].expo);
    printf(" ( %d x ^ %d  ) ",term[i].coef,term[i].expo);
}
