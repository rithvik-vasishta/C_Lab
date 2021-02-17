#include <stdio.h>
#include <stdlib.h>
typedef enum
{
    lparen,rparen,plus,minus,times,divide,mod,eos,operand
}precedence;
char expr[100];
int stack[100];
int top=-1;
precedence get(char *symbol,int *n)
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
        default:return operand;
    }
}
void push(int x)
{
    stack[++top]=x;
}
int pop()
{
    return stack[top--];
}
int eval()
{
    char symbol;
    int n=0;
    int op1,op2;
    precedence token;
    token=get(&symbol,&n);
    while(token!=eos)
    {
        if(token==operand)
            push(symbol-'0');
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
        }token=get(&symbol,&n);
    }return pop();
}
int main()
{
    printf("\nEnter the expression: ");
    scanf("%s",expr);
    printf("\nResult: %d",eval());
    return 0;
}
