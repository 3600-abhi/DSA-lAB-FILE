/*
a)	Write a C program that uses functions to perform the following:
a.	Create a singly linked list of integers.
b.	Delete a given integer from the above linked list.
c.	Display the contents of the above list after deletion.
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*head=NULL;
void create(int);
void traverse();
int main()
{
    int n;
    printf("enter no. of node : ");
    scanf("%d",&n);
    create(n);
    enter_data();
    printf("without deletion : ");
    traverse();
    printf("\n");
    delete_integar();
    printf("after deletion : ");
    traverse();
    return 0;
}
void delete_integar()
{
    int d,length=0,pos=1;
    struct node *t=head,*s=head;
    printf("enter integar to be deleted : ");
    scanf("%d",&d);
    for(;t!=NULL;t=t->link)
        length++;
    for(;s->data!=d;s=s->link)
        pos++;
    if(pos==1)
    {
        struct node *release=head;
        head=head->link;
        free(release);
    }
    else if(pos==length)
    {
        struct node *a=head,*b;
        for(;a->link->link!=NULL;a=a->link);
        b=a->link;
        a->link=NULL;
        free(b);
    }
   else
   {
       struct node *p=head,*q;
       for(int i=1;i<pos-1;i++)
        p=p->link;

       q=p->link;
       p->link=p->link->link;
       free(q);

   }


}

void enter_data()
{
    struct node *t=head;
    printf("enter data : ");
    for(;t!=NULL;t=t->link)
        scanf("%d",&t->data);
}
void create(int n)
{
    if(n==0) head=NULL;
    else if(n<0) printf("Not Possible !");
    else if(n>=1)
    {
        head=(struct node*)malloc(sizeof(struct node));
         head->link=NULL;


         if(n>1)
        {
            struct node *temp;
            temp=head;
            for(int i=2;i<=n;i++)
            {
                struct node *new_node=(struct node*)malloc(sizeof(struct node));
                new_node->link=NULL;
                temp->link=new_node;
                temp=new_node;

            }
        }
    }
}
void traverse()
{
    struct node *t=head;
    for(;t!=NULL;t=t->link)
        printf("%d ",t->data);
}

























