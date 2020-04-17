/*
e)	Write a C program that uses functions to perform the following:
a.	Create a binary search tree of characters.
b.	Traverse the above Binary search tree recursively in Postorder, inorder and Preorder
*/
#include<stdio.h>
struct node
{
    char data;
    struct node *left,*right;
}*root=NULL;
struct node* create();
int main()
{
    root=create();
    printf("inorder traversal : ");
    inorder();
    printf("\n preorder traversal : ");
    preorder();
    printf("\n postorder traversal : ");
    postorder();


}
struct node* create()
{
     char x;
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("enter data (z for no node) : ");
    scanf("%c",&x);
    if(x=='z') return 0;
    new_node->data=x;
    printf("enter left child of %c \n",x);
    new_node->left=create();
    printf("enter right child of %c \n",x);
    new_node->right=create();
    return new_node;
}
void preorder()
{
    if(root==NULL) return;
    printf("%c ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder()
{
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c ",root->data);
}
void inorder()
{
    if(root==NULL) return;
    inorder(root->left);
    printf("%c ",root->data);
    inorder(root->right);

}
