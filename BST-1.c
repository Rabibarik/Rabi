#include<stdio.h>
#include<stdlib.h>
//#define max(a,b) (a>b) ? a:b
typedef struct bst{
	int info;
	struct bst *left,*right;
}bst;

bst *root=NULL;
bst *insert(bst *p,int item)
{
	bst *nw;
	nw=(bst*)malloc(sizeof(bst));
	nw->info=item;
	nw->left=nw->right=NULL;
	if(p==NULL)
		p=nw;
	else if(item<p->info)
		p->left=insert(p->left,item);
	else
		p->right=insert(p->right,item);
	return p;
}
void insert_nr(int item)
{
	bst *nw,*p1,*p2;
	nw=(bst*)malloc(sizeof(bst));
	nw->info=item;
	nw->left=nw->right=NULL;
	if(root==NULL)//when there is no node in the BST
		root=nw;
	else//when the BST  has some nodes
	{
		for(p2=root;p2;)//this loop move the p1 to parent of new node 
		{
			if(item<p2->info)
			{
				p1=p2;
				p2=p2->left;
			}
			else
			{
				p1=p2;
				p2=p2->right;
			}
		}
		if(item<p1->info)//if the node is left child of its parent
			p1->left=nw;
		else//if the node is right child of its parent
			p1->right=nw;
	}
}
int search(bst *p,int item)
{
	int l=0;
	while(p)
	{
		if(item==p->info)
			return l;
		else if(item<p->info)
			p=p->left;
		else
			p=p->right;
		l++;
	}
	return -1;
}

void delet(int item)
{
	bst *p1,*p2,*p3;
	//search the item is to be deleted
	for(p2=root;p2 && item!=p2->info;)//after end of this loop p2 points to the node is to be deleted, & p1 points to its parent
	{
		if(item<p2->info)
		{
			p1=p2;
			p2=p2->left;
		}
		else
		{
			p1=p2;
			p2=p2->right;
		}
	}
	if(p2==NULL)//if item not found
	{
		printf("%d not found",item);
	}
	else if(p2->left==NULL && p2->right==NULL)//if it is a leaf node
	{
		if(p2->info<p1->info)//if the node p2, is left child of its parent p1
			p1->left=NULL;
		else//if the node p2, is right child of its parent p1
			p1->right=NULL;
	}
	else if(p2->left && p2->right==NULL)//node has only left child
	{
		if(p2->info<p1->info)//if the node p2, is left child of its parent p1
			p1->left=p2->left;
		else//if the node p2, is right child of its parent p1
			p1->right=p2->left;
	}
	else if(p2->left==NULL && p2->right)//node has only right child
	{
		if(p2->info<p1->info)//if the node p2, is left child of its parent p1
			p1->left=p2->right;
		else//if the node p2, is right child of its parent p1
			p1->right=p2->right;
	}
	else//if it has two children
	{
		if(p2==root)//this is only for root node
		{
			for(p3=p2->right;p3->left;p3=p3->left);//p3 move to the smallest value node in right sub tree of p2
			p3->left=p2->left;
			root=p2->right;
		}
		else//it is for non-root node
		{
			for(p3=p2->right;p3->left;p3=p3->left);//p3 move to the smallest value node in right sub tree of p2
			p3->left=p2->left;
			if(p2->info<p1->info)//if the node p2, is left child of its parent p1
				p1->left=p2->right;
			else//if the node is right child of its parent
				p1->right=p2->right;
		}
	}
	free(p2);//deallocate the memory of p2
}
void preorder(bst *p)
{
	if(p==NULL)
		return;
	printf("%d\t",p->info);
	preorder(p->left);
	preorder(p->right);
}
void inorder(bst *p)
{
	if(p==NULL)
		return;
	inorder(p->left);
	printf("%d\t",p->info);
	inorder(p->right);
}
void postorder(bst *p)
{
	if(p==NULL)
		return;
	postorder(p->left);
	postorder(p->right);
	printf("%d\t",p->info);
	
}
void print(bst *p, int l)
{
	int i;
	if(p==NULL)
		return;
	print(p->right,l+1);
		for(i=0;i<l;i++) printf("\t");
	printf("%d\n",p->info);
	print(p->left,l+1);
	
}
int smallest(bst *p)
{
	if(p==NULL)
		return-1;
	else if(p->left==NULL)
		return p->info;
	else
		smallest(p->left);
}

void mirror(bst *p)
{
	bst *t;
	if(p)
	{
		mirror(p->left);
		mirror(p->right);
		t=p->left;
		p->left=p->right;
		p->right=t;
	}
}
int main()
{
	//bst *root=NULL;
	int n,i,item,l,op,s,c;
	do
	{
		printf("\n1.insert");
		printf("\n2.delete");
		printf("\n3.preopder");
		printf("\n4.inorder");
		printf("\n5.postorder");
		printf("\n6.search");
	
		printf("\nenter option \n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("enter nodes to insert : ");
				scanf("%d",&item);
				insert_nr(item);
				//root=insert(root,item);
				break;
			case 2:
				printf("enter nodes to delete : ");
				scanf("%d",&item);
				delet(item);
				break;
			case 3:
				printf("\nnodes are :\n");
				preorder(root);
				break;
			case 4:
				printf("\nnodes are :\n");
				inorder(root);
				printf("\ntree is :\n");
				
				print(root,0);
				break;
			case 5:
				printf("\nnodes are :\n");
				postorder(root);
				printf("mirror img is :\n");
				mirror(root);
				print(root,0);
			
				break;
			case 6:
				printf("enter nodes to search : ");
				scanf("%d",&item);
				l=search(root,item);
				if(l==-1)
					printf("%d is not found",item);
				else
					printf("%d is found at level %d",item,l);
				break;
			case 7:exit(0);
			default :printf("\ninvalid option\n");
				
		}
	}while(op!=7);
	return 0;
}
