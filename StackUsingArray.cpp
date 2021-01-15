#include<iostream>

using namespace std;


void pop();
void push();
int isempty();
int isfull();


int stack[4];
int static count=0;


int main()
{
    int r;
    while(1)

    	{
    	cout<<"Select An Operation : ";
    	cout<<endl<<"1. PUSH"<<endl<<"2. POP"<<endl<<"3. EXIT"<<endl;
   		cin>>r;
   		 switch (r)
   			 {
   			 case 1 : push();
   			 for(int i=0;i<count;i++)
   			 {
   			 	cout<<"in stack : "<<stack[i]<<endl;
   			}
   			     break;
   			 case 2 : pop();
      			  break;
   			 case 3:exit;
      			  break;
      		default : cout<<"Encorrect input"<<endl;
   			 }
   			/* for(int i=0;i<=4;i++)
   			 {
   			 	cout<<"in stack : "<<stack[i];
				}*/

		}


}



void push()
{
    int input;
    cout<<"Enter an no. ";
    cin>>input;
    int res=isfull();

    if(res == 1)
    	{
   		stack[count]=input;
   		count++;
		}


}

int isfull()
{
	if(count == 4)
	{
		cout<<"Stack is full"<<endl;
		return 0;
	}
	else
	{
		return 1;
	}

}

void pop()
{
    int input;
    int res=isempty();
    //cout<<"Enter an no. ";
    if(res == 0)
    	{
    		cout<<"Stack is Empty"<<endl;
		}
		else
		{
			count--;
			cout<<"Poped Elements "<<endl<<stack[count];

		}

}

int isempty()
{
	if(count == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}

}


