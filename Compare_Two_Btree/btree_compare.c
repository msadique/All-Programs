#include<stdio.h>
#include<stdlib.h>
#define N 1000
struct node
{
	int data;
	struct node * right;
	struct node *left;
}btree;
struct node * insert(int data,struct node *root);
int display(struct node *root1, struct node *root2);
int display_pre(struct node *root);
int display_post(struct node *root);
int display_in(struct node *root);
int match_btree(struct node *root1, struct node *root2);
int delete( struct node *root);
int test_data( int tree1[ N ], int tree2[ N ],int n1, int n2 );

int main()
{
	int n1,n2;
	n1 = 7;
	n2 = 7;
	int a1[N] = {5,3,2,4,7,6,8};
	int b1[N] = {5,3,2,4,7,6,8};
	test_data(a1,b1,n1,n2);
	
	
	n1 = 7;
	n2 = 6;
	int a2[N] = {5,3,2,4,7,6,8};
	int b2[N] = {5,3,2,4,7,6};
	test_data(a2,b2,n1,n2);
	
	
	n1 = 7;
	n2 = 7;
	int a3[N] = {5,3,2,4,7,6,8};
	int b3[N] = {4,3,1,5,8,6,7};
	test_data(a3,b3,n1,n2);
	
	
	n1 = 14;
	n2 = 14;
	int a4[N] = {9,6,15,3,8,12,17,1,5,7,11,13,16,18};
	int b4[N] = {9,6,3,1,5,8,7,15,12,11,13,17,16,18};
	test_data(a4,b4,n1,n2);
	
	return 0;
}

int test_data( int tree1[ N ], int tree2[ N ],int n1, int n2 )
{
	
	printf("\n--------------------------------------------------------------------\n");

	int i;
	struct node *btree1=NULL, *btree2 = NULL;
	i=0;
	printf("Data1 :-");
	while( i < n1 )
	{ 
		printf(" %d ",tree1[i]);
		btree1 = insert(tree1[i++],btree1);
	}
        i=0;
	printf("\nData2 :-");
        while( i < n2)
        {
		printf(" %d ",tree2[i]);
		btree2 = insert(tree2[i++],btree2);
        }
	// Both tree in pre post and inoder traversal
	display(btree1,btree2);
	// Match both tree
	if( match(btree1,btree2))
	{
		printf("\n\n**********\t Both Binary tree are Equal\t************\n ");
	}
	else
	{
		printf("\n\n***********\t Both Binary tree are not Equal\t*************\n");
	}
	delete(btree1);    // delete btree1
	delete(btree2);    // delete btree2
	printf("\n------------------------------------------------------------------------\n");
	return 1;
}
int delete(struct node *root)
{
	if(root==NULL)
	{
		return 1;
	}
	delete(root->right);
	delete(root->left);
	free(root);
	return 1;
}
int match( struct node *root1, struct node *root2)
{
	int b1, b2;
	if( root1 == NULL && root2 == NULL )
	{
		return 1;
	}
	else if ( (root1 == NULL && root2 != NULL  ) ||
		  (root1 != NULL && root2 == NULL ))
	{
		return 0;
	}
	if(root1->data == root2->data)
	{
		b1 = match(root1->left,root2->left);
		b2 = match(root1->right,root2->right);
	}
	else
	{
		return 0;
	}
	if( b1 == 0 || b2 == 0 )
	{
		return 0;
	}
	else
	{
		return 1;
	}
	

	
}
struct node *insert(int data, struct node *root)
{
	struct node *temp2;
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->right = NULL;
	temp->left = NULL;
	temp->data = data;
	if( root == NULL)
	{
	  root = temp;
	}
	else 
	{
		temp2 = root;
		while(temp2)
		{
			if(data > temp2->data)
			{	
				if(temp2->right ==NULL)
				{
					temp2->right = temp;
					break;
				}
				else
				{
					temp2 = temp2->right;
				}
	
			}
			else
			{	
				if(temp2->left == NULL)
				{
					temp2->left = temp;
					break;
				}
				else
				{
					temp2 = temp2->left;
				}
			}	
		}
	}
	return root;
}
int display( struct node *root1, struct node *root2)
{
	printf("\n\n Pre-order Traversal :-");
	printf("\nTree1 :- ");
	display_pre(root1);
	printf("\nTree2 :- ");
	display_pre(root2);

	printf("\n\n Post-order Traversal :-");
	printf("\nTree1 :- ");
	display_post(root1);
	printf("\nTree2 :- ");
	display_post(root2);
	
	printf("\n\n In-order Traversal :-");
	printf("\nTree1 :- ");
	display_in(root1);
	printf("\nTree2 :- ");
	display_in(root2);
	
}
int display_pre(struct node *root)
{
	if(!root)
	{
		return 1;
	}
	else
	{
		printf(" %d ",root->data);
		display_pre(root->left);
		display_pre(root->right);
	}
}

int display_in(struct node *root)
{
	if(!root)
	{
		return 1;
	}
	else
	{
		display_pre(root->left);
		printf(" %d ",root->data);
		display_pre(root->right);
	}
}
int display_post(struct node *root)
{
	if(!root)
	{
		return 1;
	}
	else
	{
		display_pre(root->left);
		display_pre(root->right);
		printf(" %d ",root->data);
	}
}
