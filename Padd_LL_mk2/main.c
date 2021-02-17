#include<stdio.h>
#include<stdlib.h>
#define compare(x,y)((x>y)?1:(x<y?-1:0))
typedef struct polynode *polyptr;
typedef struct polynode {
	int coef;
	int exp;
	polyptr link;
}polynode;
void attach(int coef, int exp, polyptr *ptr) {
	polyptr temp;
	temp=(polyptr)malloc(sizeof(polyptr));
	temp->coef=coef;
	temp->exp=exp;
	temp->link=NULL;
	(*ptr)->link=temp;
	(*ptr)=temp;
}
polyptr padd(polyptr a, polyptr b) {
	polyptr c, lastc, sa;
	sa=a;
	a=a->link;
	b=b->link;
	c=(polyptr)malloc(sizeof(polyptr));
	lastc=c;
	c->exp=-1;
	int flag=0;
	do {
		switch(compare(a->exp,b->exp)) {
			case -1:{
				//printf("\nin -1");
				attach(b->coef,b->exp,&lastc);
				b=b->link;
				}
				break;
			case 1:{
				//printf("\nin 1");
				attach(a->coef,a->exp,&lastc);
				a=a->link;
				}
				break;
			case 0: {
				//printf("\nin 0");
				if(sa==a)
					flag=1;
				else {
				if(a->coef+b->coef!=0)
					attach(a->coef+b->coef,a->exp,&lastc);
				a=a->link;
				b=b->link;
				}
				}
				break;
		}
	}while(flag!=1);
	lastc->link=c;
	return c;
}
void display(polyptr m) {
	polyptr t;
	t=m->link;
	printf("\n");
	while(t->exp!=-1) {
		printf("+%dx^(%d) ",t->coef,t->exp);
		t=t->link;
	}
}
int main() {
	polyptr a, b, lasta, lastb;
	a=(polyptr)malloc(sizeof(polyptr));
	b=(polyptr)malloc(sizeof(polyptr));
	a->exp=-1;
	b->exp=-1;
	lasta=a;
	lastb=b;
	int na,nb;
	int co,e,i;
	printf("\nEnter number of terms in A");
	scanf("%d",&na);
	printf("\nEnter A poly : \n ");
	for(i=0;i<na;i++) {
		printf("\nEnter the coef and exp : ");
		scanf("%d%d",&co,&e);
		attach(co,e,&lasta);
	}
	lasta->link=a;
	printf("\nEnter number of terms in B");
	scanf("%d",&nb);
	printf("\nEnter B poly : \n ");
	for(i=0;i<nb;i++)
    {
		printf("\nEnter the coef and exp : ");
		scanf("%d%d",&co,&e);
		attach(co,e,&lastb);
	}
	lastb->link=b;
	polyptr c;
	c=padd(a, b);
	display(c);
	printf("\n");
	return 0;
}
