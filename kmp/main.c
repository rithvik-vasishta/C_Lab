#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int failure[100];
void fail(char *pat)
{
    int i,j,n=strlen(pat);
    failure[0]=-1;
    for(j=1;j<n;j++)
    {
        i=failure[j-1];
        while((pat[j]!=pat[i+1])&&(i>=0))
            i=failure[i];
        if(pat[j]==pat[i+1])
            failure[j]=i+1;
        else
            failure[j]=-1;


    }
}
int pmatch(char *str,char *pat)
{
    int i=0,j=0;
    int lens=strlen(str);
    int lenp=strlen(pat);
    fail(pat);
    while(i<lens&&j<lenp)
    {

        if(str[i]==pat[j])
        {
            i++;
            j++;
        }
        else if(j==0)
            i++;
        else
            j=failure[j-1]+1;
    }
    return ((j==lenp)?(i-lenp):-1);
}
int main()
{
    char str[100],pat[100];
    int pos;
    printf("Enter the string: ");
    scanf("%s",str);
    printf("\nEnter the pattern: ");
    scanf("%s",pat);

    pos=pmatch(str,pat);
    if(pos!=-1)
        printf("match found at : %d",pos+1);
    else
        printf("Match not found");
    return 0;
}
