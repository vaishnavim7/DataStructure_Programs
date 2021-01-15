#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node*createnode(int input);

struct Node
{
	int data;
	struct Node* left, *right;
};
struct Node* insertnode(struct Node* root, int input)
{
	if(root==NULL)
	{
		
		return createnode(input);	
	}
	if(input<root->data)
	{
		root->left=insertnode(root->left,input);
	}
	else if(input>root->data)
	{
		root->right=insertnode(root->right,input);
	}
	return root;
}


struct Node*createnode(int input)
{
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=input;
	temp->right=NULL;
	temp->left=NULL;
	return temp;
}
void Preorder(struct Node* root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		Preorder(root->left);
		Preorder(root->right);
	}
}
int countTotalNumberNode(struct Node * root)
{
	int c=1;
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		c+=countTotalNumberNode(root->left);
		c+=countTotalNumberNode(root->right);
		return c;
	}
}
struct Node* deletenode(struct Node* root, int input)
{
	if(root==NULL)
	{
		return root;
	}
	if(input<root->data)
	{
		root->left=deletenode(root->left,input);
	}
	else if(input>root->data)
	{
		root->right=deletenode(root->right,input);
	}
	else
	{
		if(root->left==NULL)
		{
			struct Node *temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			struct Node *temp=root->left;
			free(root);
			return temp;
		}
	}
	return root;
}


int main()
{

	struct Node* root=NULL;
	root=insertnode(root,8);
	root=insertnode(root,3);
	root=insertnode(root,1);
	root=insertnode(root,6);
	root=insertnode(root,4);
	root=insertnode(root,7);
	root=insertnode(root,10);
	root=insertnode(root,14);
	root=insertnode(root,13);
	
	cout<<"preorder traversal"<<endl;
	Preorder(root);
	
	cout<<endl;
	int count=countTotalNumberNode(root);
	cout<<"total number of nodes="<<count<<endl;
	
	cout<<"deletion of node"<<endl;
	deletenode(root,3);
	cout<<"deletion of 3 sucessful"<<endl;
	

	
	return 0;
}





