/*
g)	Write a C program that to calculate:
a.	Number of Leaf and non Leaf in a Binary Tree
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
    int l,nl;
    root=create();
    printf("leaf node : ");
    l=leaf();
    printf("%d",l);
    printf(" \n non-leaf : " );
    nl=non_leaf();
    printf("%d",nl);

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
int leaf()
{
     if(root == NULL) return 0;

    else if(root->left == NULL && root->right == NULL)  return 1;

    else  return (leaf(root->left)+ leaf(root->right));
}
int non_leaf()
{
    if (root == NULL || (root->left == NULL &&  root->right == NULL)) return 0;
    return (1 + non_leaf(root->left) +  non_leaf(root->right));

}
