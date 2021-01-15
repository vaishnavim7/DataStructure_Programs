#include<iostream>
#include<stdlib.h>
using namespace std;


void Append();
void addBeg();
void insert();
void Display();
int length();
void remove();

struct Node
{
	int Data;
	struct Node* right= NULL;
	struct Node* left=NULL;
};

struct Node*root=NULL;
int len;
int main()
{
	
	int ch;
	while(1)
	{
		cout<<"1.Append"<<endl;
		cout<<"2.AddBeg"<<endl;
		cout<<"3.Insert"<<endl;
		cout<<"4.Remove"<<endl;
		cout<<"5.Length"<<endl;
		cout<<"6.Display"<<endl;
		cout<<"7.Exit"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:Append();
			break;
			
			case 2:addBeg();
			break;
			
			case 3:insert();
			break;
				
			case 4:remove();
			break;
				
			case 5:len= length();
					cout<<"Length ="<<len<<endl;
			break;
				
			case 6:Display();
			break;
			
			case 7:exit(0);
			break;
			
			Default:cout<<"Invalid Input";
			break;
		}
	}
		
return 0;
}

void Append()
{
	struct Node*temp;
	
	temp=(struct Node*)malloc(sizeof(struct Node));
	
	cout<<"Enter Node data"<<endl;
	cin>>temp->Data;
	temp->right=NULL;
	temp->left=NULL;
	
	
	if(root==NULL)
	{
		root=temp;	
	}
	else
	{
		struct Node*p;
		p=root;
		while(p->right!=NULL)
		{
			p=p->right;
		}
		p->right=temp;
		temp->left=p;
		
	}
	
}

void addBeg()
{
	struct Node*temp;
	temp=(struct Node*)malloc(sizeof(struct Node));
	cout<<"Enter Data to add at begining: ";
	cin>>temp->Data;
	temp->right=NULL;
	temp->left=NULL;
	
	if(root==NULL)
	{
		temp=root;
	}
	else
	{
		temp->right=root;
		root->left=temp;
		root=temp;
	}
}
void Display()
{
	struct Node* p;
	p=root;
	while(p!=NULL)
	{
		cout<<"=>"<<p->Data<<endl;
		p=p->right;
	}
}
int length()
{	int Count= 0;
	struct Node* p;
	p=root;

	while(p!=NULL)
	{
		Count++;
		p=p->right;
	}
	return Count;
}

void insert()
{	int loc,i=1;
	cout<<"Enter location to insert value:";
	cin>>loc;
	struct Node* temp;
	temp=(struct Node*)malloc(sizeof(struct Node));
	cout<<"Enter Data:";
	cin>>temp->Data;
	temp->right=NULL;
	temp->left=NULL;
	struct Node*p ,*q;
	len=length();
	p=root;
	q=root;
	if(root==NULL)
	{
		root=temp;
	}
	else if(loc>len)
	{
		cout<<"Invalid Input";
	}
	else 
	{
		while(i<loc)
		{
			p=p->right;	
			q=p->right;
			i++;
		}
		
		temp->right=q; //right connections
		q->left=temp;//right connections
		
		temp->left=p;
		p->right=temp;
	}
}

void remove()
{
	int loc,i=1;
	cout<<"Enter location to remove node:";
	cin>>loc;
	struct Node *p,*q,*r;
	p=root;
	q=root;
	r=root;
	if(root==NULL)
	{
		cout<<"No Nodes available";
	}
	else
	{
		while(i<loc-1)
		{
			p=p->right;
			q=p->right;
			r=p->right;
			
			i++;	
		}
		
		p->right=q->right;
		r->left=q->left;
		q->right=NULL;
		q->left=NULL;
		free(q);
		
	}
	
}












