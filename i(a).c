/*
i)	Write C programs for implementing the following sorting methods to arrange a list of integers in ascending order:
a.	Insertion sort
*/
#include<stdio.h>
int main()
{

    int a[]={34,45,11,89,55,19,22,8,40,100};
    int i,n=sizeof(a)/sizeof(int);
    printf("array : ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    insertion_sort(a,n);
    printf("sorted array : ");
    for(i=0;i<=n-1;i++)
        printf("%d ",a[i]);
    return 0;
}
void insertion_sort(int a[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0&&temp<a[j];j--)
            a[j+1]=a[j];
        a[j+1]=temp;
    }
}
