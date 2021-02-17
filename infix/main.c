#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef enum
{
    lparen,rparen,plus,minus,times,divide,mod,eos,operand
}precedence;
char expr[100];
int stack[100];
int top=-1;
precedence gettoken(char *symbol,int *n)
{
    *symbol=expr[(*n)++];
    switch(*symbol)
    {
        case '(':return lparen;break;
        case ')':return rparen;break;
        case '+':return plus;break;
        case '-':return minus;break;
        case '*':return times;break;
        case '/':return divide;break;
        case '%':return mod;break;
        case ' ':return eos;break;
        case '\0':return eos;break;
        default:return operand;break;

    }
}
void push(int token)
{
  stack[++top]=token;
}
int pop()
{
    return stack[top--];
}
int eval()
{
    precedence token;
    char symbol;
    int op1,op2;
    int n=0;
    token=gettoken(&symbol,&n);
    while(token!=eos)
    {
        if(token==operand)
            push(symbol - '0');
        else
        {
            op2=pop();
            op1=pop();
            switch(token)
            {
                case lparen:break;
                case rparen:break;
                case plus:push(op1+op2);break;
                case minus:push(op1-op2);break;
                case times:push(op1*op2);break;
                case divide:push(op1/op2);break;
                case mod:push(op1%op2);break;
                case eos:break;
                case operand:break;
            }
        }token=gettoken(&symbol,&n);
    }return pop();
}
int main()
{
    printf("\nEnter the postfix expression: ");
    scanf("%s",expr);
    printf("\nResult: %d",eval());
    return 0;
}
