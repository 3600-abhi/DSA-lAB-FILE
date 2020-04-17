/*
b)	Write a C program that uses functions to perform the following:
a.	Create a doubly linked list of integers.
b.	Delete a given integer from the above doubly linked list.
c.	Display the contents of the above list after deletion
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev,*next;
}*head=NULL;
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
    for(;t!=NULL;t=t->next)
        length++;
    for(;s->data!=d;s=s->next)
        pos++;
    if(pos==1)
    {
        struct node *release=head;
        head=head->next;
        head->prev=NULL;
        free(release);
    }
    else if(pos==length)
    {
        struct node *a=head,*b;
        for(;a->next->next!=NULL;a=a->next);
        b=a->next;
        a->next=NULL;
        free(b);
    }
   else
   {
       struct node *p=head,*q;
       for(int i=1;i<pos-1;i++)
        p=p->next;
        p->next->next->prev=p;
       q=p->next;
       p->next=p->next->next;
       free(q);

   }

}
void enter_data()
{
    struct node *t=head;
    printf("enter data : ");
    for(;t!=NULL;t=t->next)
        scanf("%d",&t->data);
}
void traverse()
{
    struct node *t=head;
    for(;t!=NULL;t=t->next)
        printf("%d ",t->data);
}

void create(int n)
{
    if(n==0) head=NULL;
    else if(n<0) printf("Not Possible !");
    else if(n>=1)
    {
        head=(struct node*)malloc(sizeof(struct node));
        head->prev=NULL;
        head->next=NULL;
        if(n>1)
        {
            struct node *temp =head;
            for(int i=2;i<=n;i++)
            {
                struct node *new_node=(struct node *)malloc(sizeof(struct node));
                new_node->prev=temp;
                new_node->next=NULL;
                temp->next=new_node;
                temp=new_node;
            }
        }
    }
}
