/*
f)	Write a C program that to calculate:
a.	Number of Nodes in a Binary Tree

*/
#include<stdio.h>
struct node
{
    int data;
    struct node *left,*right;
}*root=NULL;
struct node* create();
int main()
{
    int n;
    root=create();
    printf("total node : ");
    n=count(root);
    printf("%d",n);
}
struct node* create()
{
    int x;
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("enter data (-1 for no node) : ");
    scanf("%d",&x);
    if(x==-1) return 0;
    new_node->data=x;
    printf("enter left child of %d \n",x);
    new_node->left=create();
    printf("enter right child of %d \n",x);
    new_node->right=create();
    return new_node;
}
int count(struct node *root)
{
   if(root == NULL){
        return 0;
    }
    else return (1 + count(root->left) + count(root->right));
}
