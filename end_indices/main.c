#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int nfind(char *str,char *pat)
{
    int i,j,start=0;
    int lasts=strlen(str)-1;
    int lastp=strlen(pat)-1;
    int endmatch=lastp;
    for(i=0;endmatch<=lasts;endmatch++,start++)
    {
        if(str[endmatch]==pat[lastp])
            for(j=0,i=start;j<lastp&&str[i]==pat[j];i++,j++);
        if(j==lastp)
            return start;
    }return -1;

}
int main()
{
    char str[100],pat[100];
    int pos;
    printf("Enter the string: ");
    scanf("%s",str);
    printf("\nEnter the pattern: ");
    scanf("%s",pat);
    pos=nfind(str,pat);
    if(pos!=-1)
        printf("match found at : %d",pos+1);
    else
        printf("Match not found");
    return 0;
}
