#include <stdio.h>
#include <stdlib.h>
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define compare(x,y) ((x)>(y))?(1):((x)==(y))?(0):(-1)
void sort(int a[],int);
int binsearch(int a[],int,int,int);
void main()
{
    int a[100],n,i,k,pos;
    printf("Enter the size: ");
    scanf("%d",&n);
    printf("Enter the array elements: ");
     for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,n);
    printf("Enter the key element: ");
    scanf("%d",&k);
    pos=binsearch(a,k,0,n-1);
    if(pos!=-1)
        printf("%d found at : %d",k,pos+1);
    else
        printf("%d not found",k);


}
void sort(int a[100],int n)
{
    int min,i,j,t;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
            if(a[j]<a[min])
            swap(a[min],a[j],t);
    }
    printf("Sorted elements are: ");
    for(i=0;i<n;i++)
        printf("%4d",a[i]);

}
int binsearch(int a[100],int k,int l,int h)
{
    int mid;
    if(l<=h)
    {
        mid=(l+h)/2;
        switch(compare(k,a[mid]))
        {
            case 0:return mid;
            case 1:return binsearch(a,k,mid+1,h);
            case -1:return binsearch(a,k,l,mid-1);
        }
    }return -1;
}
