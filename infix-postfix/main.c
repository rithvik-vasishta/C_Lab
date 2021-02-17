#include <stdio.h>
#include <stdlib.h>
typedef enum precedence
{
    lparen,rparen,plus,minus,multiply,divide,mod,eos,operand
}precedence;
int isp[]={0,19,12,12,13,13,13,0};
int icp[]={20,19,12,12,13,13,13,0};
char expr[200];
int stack[200];
int top=-1;
precedence get(char *sym,int *n)
{
    *sym=expr[(*n)++];
    switch((*sym))
    {
        case '(':return lparen;
        case ')':return rparen;
        case '+':return plus;
        case '-':return minus;
        case '*':return multiply;
        case '/':return divide;
        case '%':return mod;
        case ' ':return eos;
        case '\0':return eos;
        default:return operand;
    }
}
void print(precedence token)
{
    switch(token)
    {
       case lparen:printf(" ( ");break;
        case rparen: printf(" ) ");break;
        case plus:printf(" + ");break;
        case minus:printf(" - ");break;
        case multiply:printf(" * ");break;
        case divide:printf(" / ");break;
        case mod:printf(" %% ");break;
        case eos:printf("   ");break;
        case 8:break;
    }
}
void push(int item)
{
    stack[++top]=item;
}
int pop()
{
    return stack[top--];
}
void post(void)
{
    char sym;
    precedence token;
    int n=0;
    top=0;
    stack[0]=eos;
    for(token=get(&sym,&n);token!=eos;token=get(&sym,&n))
    {
        if(token==operand)
            printf(" %c ",sym);
        else if(token==rparen)
          {
            while(stack[top]!=lparen)
            print(pop());
            pop();
          }
          else
          {
              while(isp[stack[top]]>=icp[token])
                print(pop());
              push(token);
          }
    }
    while((token=pop())!=eos)
        print(token);
    printf("\n");
}
int main()
{
    printf("\nEnter the expression:");
    scanf("%s",expr);
    post();
    return 0;
}
