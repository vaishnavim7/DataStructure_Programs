#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;	
};

struct Node *head = NULL;

struct Node *CreateNode(int input)
{
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	node->data = input;
	node->next = NULL;
	node->prev = NULL;
}

void InserAtBeginning(int input)
{
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = input;
	newNode->prev = NULL;
	
	if(head == NULL)
	{
		newNode->next = NULL;
		head = newNode;
	}
	else 
	{
		newNode->next = head;
		head = newNode;
	}
	cout<<"Node Inserted at the Beginnig "<<newNode->data<<endl;
	
}

void InserAtEnd(int input)
{
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = input;
	newNode->next = NULL;
	
	if(head == NULL)
	{
		newNode->prev = NULL;
		head = newNode;
	}
	else 
	{
		struct Node *temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
	}
	cout<<"Node Inserted at the End "<<newNode->data<<endl;
}

int length()
{
	int count;
	struct Node *root;
	root = head;
	while(root != NULL)
	{
		count++;
		root = root->next; 
	} 
	return count;
}

void InsertNode()
{
	int input, loc, len, c = 1;
	cout<<"Enter Loction to Insert Node :"<<endl;
	cin>>loc;
	cout<<"Enter Value to Insert Node :"<<endl;
	cin>>input;
	
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = input;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	struct Node *node1, *node2;
	len = length();
	node1 = head;
	node2 = head;
	
	if(head == NULL)
	{
		head = newNode;
	}
	else if(loc > len)
	{
		cout<<"Invalid"<<endl;
	}
	else{
		while(c < loc)
		{
			node1 = node1->next;
			node2 = node1->next;
			c++;
		}
		newNode->next = node2;
		node2->prev = newNode;
		
		newNode->prev = node1;
		node1->next = newNode;
		 
	}
	
}

void DeleteNode()
{
	int loc, c = 1;
	cout<<"Enter Loction to Delete Node :"<<endl;
	cin>>loc;
	struct Node *node1, *node2, *root;
	node1 = head;
	node2 = head;
	root = head;
	if(root == NULL)
	{
		cout<<"No Node Available."<<endl;
	}
	else
	{
		while(c < loc-1)
		{
			node1 = node1->next;
			node2 = node1->next;
			root = node1->next;
			c++;
		}
		node1->next = node2->next;
		root->prev = node2->prev;
		node2->next = NULL;
		node2->prev = NULL;
		free(node2);
	}
	cout<<"Node Deleted."<<endl;
	
}

void Display()
{
	if(head == NULL)
	{
		cout<<"List is Empty."<<endl;
	}
	else
	{
		struct Node *temp = head;
		cout<<"List Data:"<<endl;
		while(temp != NULL)
		{
			cout<<temp->data<<endl;
			temp = temp->next;
		}
	}
}

int main()
{
	Display();
	
	InserAtBeginning(10);
	InserAtBeginning(20);
	InserAtBeginning(30);
	
	
	Display();
	
	InserAtEnd(50);
	InserAtEnd(60);
		
	Display();
	
	InsertNode();
	
	Display();
	
	InsertNode();
	
	Display();
	
	DeleteNode();
	
	Display();
	
	DeleteNode();
	
	Display();
	
	return 0;
}
