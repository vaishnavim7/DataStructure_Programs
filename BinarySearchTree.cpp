#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;	
};

struct Node* CreateNode(int input)
{
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	node->data = input;
	node->left = NULL;
	node->right = NULL;
	return node;
}

struct Node* InsertNode(struct Node* root, int input)
{
	if(root == NULL)
	{
		return CreateNode(input);
	}
	else if(input < root->data)
	{
		root->left = InsertNode(root->left, input);
	}
	else if(input > root->data)	
	{
		root->right = InsertNode(root->right, input);
	}
	return root;
}

int CountNode(struct Node *root)
{
	int count = 1;
	if(root == NULL)
	{
		return 0;
	}
	else
	{
		count += CountNode(root->left);
		count += CountNode(root->right);
		return count;
	}
}

struct Node* DeleteNode(struct Node *root, int input)
{
	if(root == NULL)
	{
		return root;
	}
	else if(input < root->data)
	{
		root->left = DeleteNode(root->left, input);
	}
	else if(input > root->data)
	{
		root->right = DeleteNode(root->right, input);
	}
	else
	{
		if(root->left == NULL)
		{
			struct Node *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL)
		{
			struct Node *temp = root->left;
			free(root);
			return temp;
		}
	}
	return root;
}

void InOrder(struct Node* root)
{
	if(root!=NULL)
	{
		InOrder(root->left);
		cout<<root->data<<endl;
		InOrder(root->right);	
	}
}
void PreOrder(struct Node* root)
{
	if(root!=NULL)
	{
		cout<<root->data<<endl;
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
void PostOrder(struct Node* root)
{
	if(root!=NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		cout<<root->data<<endl;
	}
}


int main()
{
	struct Node* root = NULL;
	root = InsertNode(root, 8);
	root = InsertNode(root, 3);
	root = InsertNode(root, 1);
	root = InsertNode(root, 6);
	root = InsertNode(root, 4);
	root = InsertNode(root, 7);
	root = InsertNode(root, 10);
	root = InsertNode(root, 14);
	root = InsertNode(root, 13);
	
	cout<<"InOrder Traverse : "<<endl;
	InOrder(root);
	
	cout<<"PreOrder Traverse : "<<endl;
	PreOrder(root);
	
	cout<<"PostOrder Traverse : "<<endl;
	PostOrder(root);
	
	int totalCount = CountNode(root);
	cout<<"Total Num of Nodes : "<<totalCount<<endl;
		
	DeleteNode(root, 1);
	cout<<"Node Deleted."<<endl;
	
	return 0;
}
