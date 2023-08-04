#include<stdio.h>
#include<stdlib.h>
typedef struct BST
{
    int info;
    BST *left,*right;
}BST;
BST insert(BST *root,int ele)
{
    bst *nw,*p=root;
    nw=(BST *)malloc(sizeof(bst));
    nw->left=nw->right=NULL;
    if(p==NULL)
    root=nw;
    else
    {
        while(p!=NULL)
        {
            if(ele>p->info && p->right!=NULL)
            p=p->right;
            else if(ele<p->info && p->left!=NULL)
            p=p->left;
            else
            break;
        }
        if(ele>p->info)
        p->right=nw;
        if(ele<p->info)
        p->left=nw;
        else
        printf("CUPLICATE CANNOT BE INSERTED \n");
    }
    return root;
}
void inorder(BST *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d"root->info);
        inorder(root->right);
    }
}
void preorder(BST *root)
{
    if(root!=NULL)
    {
        printf("%d"root->info);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(BST *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
         postorder(root->right);
        printf("%d"root->info);
  
    }
}
bst *findmin(bst *root)
{
    BST *P=root;
    if(p!=NULL)
    {
        while(p!=NULL)
        p=p->left;
    }
    return p;
}
bst *findmax(bst *root)
{
    BST *P=root;
    if(p!=NULL)
    {
        while(p!=NULL)
        p=p->right;
    }
    return p;
}
int height(BST *ROOT)
{
    int h;
    if(root==NULL)
    return 0;
    else
    {
        h=max(height(root->right),height(root->left))
        return(h+1);
    }
}