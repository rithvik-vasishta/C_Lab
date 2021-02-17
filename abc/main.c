#include <stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    char info;
    struct stack *next;
}Stack;
char a[][50]={"<name>","</name>","<class>","</class>","<roll>","</roll>","<grade>","</grade>","<note>","</note>","<message>","</message>","<to>","</to>","<from>","</from>","<heading>","</heading>","<marks>","</marks>","<salary>","</salary>","<empid>","</empid>","<basic>","</basic>","<da>","</da>","<age>","</age>","<address>","</address>","<html>","</html>","</p>","<p>","<print>","</print>","<height>","</height>","<body>","</body>","<weight>","</weight>","<letter>","</letter>","<book>","</book>","<pages>","</pages>"};
Stack *start;
Stack *tag;
Stack *content;
Stack *push(Stack *,char);
Stack *pop(Stack*);
char peep(Stack*);
char peep(Stack*rec)
{
    if(rec==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    return rec->info;
}
Stack *push(Stack* rec,char c)
{
    Stack *new_rec;
    new_rec=(Stack*)malloc(sizeof(Stack));
    new_rec->info=c;
    new_rec->next=rec;
    rec=new_rec;
    return rec;
}
Stack *pop(Stack*rec)
{
    Stack *temp;
    if(rec==NULL)
    printf("Stack is empty\n");
    else
    {
        temp=rec->next;
        free(rec);
        rec=temp;
    }
    return rec;
}
int main()
{
    int i=0;
    char c;
    char *p;int c1=1;
    char string[200];
   label:  printf("ENTER THE XML COMMAND\n");
    scanf(" %[^\n]s",string);


        for(int j=0;j<50;j++)
        {
            p=strstr(string,a[j]);

            if(p!=NULL)
              { c1=1; break; }
            else
               c1=0;}
           if(c1==1)
           printf("VALID");
           else
           { printf("INVALID");
           printf("\nEnter again\n");
           goto label;
           }

    for (i=0;string[i]!='\0';i++)
    {
        if (string[i+1]!='/')
        {
            start=push(start,string[i]);
        }
        else
        {
            do
            {
                c=peep(start);
                content=push(content,c);
                start=pop(start);
            }
            while(c!='>');
            content=pop(content);
            tag=push(tag,'>');
            do
            {
                c=peep(start);
                tag=push(tag,c);
                start=pop(start);

            }while(c!='<');
            printf("\n Tag is :\n");
            while(tag!=NULL)
            {
                c=peep(tag);
                tag=pop(tag);
                printf("%c",c);
            }
            printf("\nContents is:\n");
            while(content!=NULL)
            {
                c=peep(content);
                content=pop(content);
                printf("%c",c);
            }
        } }
}
