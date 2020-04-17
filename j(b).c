/*
j)	Write C programs for implementing the following sorting methods to arrange a  List of integers in ascending order:
a.	..............
b.	Selection sort
*/
#include<stdio.h>
int main()
{
    int a[]={33,11,66,88,99,77,44,55,22,1};
    int temp,k,loc,n=sizeof(a)/sizeof(int);
    printf("array : ");
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n");
    for(k=0;k<=n-2;k++)
    {
        loc=min(a,k,n);
        temp=a[k];
        a[k]=a[loc];
        a[loc]=temp;
    }
    printf("sorted array : ");
    for(k=0;k<=n-1;k++)
        printf("%d ",a[k]);
    return 0;
}
int min(int a[],int k,int n)
{
    int j,loc,min;
    min=a[k];
    loc=k;
    for(j=k+1;j<=n-1;j++)
        if(min>a[j])
    {
        min=a[j];
        loc=j;
    }
    return loc;
}
