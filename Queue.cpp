#include<iostream>
# include<stdbool.h>
using namespace std;

typedef struct node
{
	int Data;
	struct node *next;
	
}NODE , *PNODE;

class Queue
{
private:
	PNODE Head;
	int iSize;
public:
	
	Queue();					// COnstructor
	~ Queue();					// Destructor
	void EnQueue(int);			// Inserting element
	int DeQueue();				// Removing element
	int Front();				//Dispaly First element without removing 	
	int Count();				//Number of element in Queue
	int IsEmptyQueue();			// Check whether queue is empty or not
	void Display();
};
Queue::Queue()
{
	cout<<"Inside constructor\n";
	this->Head = NULL;
	this->iSize = 0;
}
Queue::~Queue()
{
	
}
void Queue::EnQueue(int No)
{
	PNODE newn = NULL;
	newn = new (NODE);
	newn->Data = No;
	newn->next = NULL;
	if(iSize == 0)
	{
		Head = newn;
		iSize ++;
	}
	else
	{
		PNODE temp = Head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
		iSize ++;
	}
}
int Queue::DeQueue()
{
	int iRet = -1;
	if (iSize == 0)
	{
		cout<<"Queue is Empty\n";
	}
	else
	{
		PNODE temp = Head;
		Head = temp->next;
		iRet =  temp->Data;
		delete (temp);
		iSize --;
	}
	return iRet;
}
int Queue::Front()
{
	if (iSize == 0)
	{
		cout<<"Queue is Empty\n";
		return 0;
	}
	else
	{
		return Head->Data;
	}
	
}
int Queue::Count()
{
	if (iSize == 0)
	{
		return -1;
	}
	else
	{
		return iSize;
	}
}
int Queue::IsEmptyQueue()
{
	if (iSize == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Queue::Display()
{
	PNODE temp = Head;
	while(temp != NULL)
	{
		cout<<temp->Data<<"\t";
		temp = temp->next;
	}
	cout<<"\n";
}
int main()
{
	Queue qobj;
	int option = 1,iRet = 0,No = 0;
	while (option != 0)
	{
		cout<<"Enter your option\n";
		cout<<"1:Insert Element in Queue\n";
		cout<<"2:Remove Element from Queue\n";
		cout<<"3:Dispaly First Element\n";
		cout<<"4:Number of Element present in Queue\n";
		cout<<"5:Check Queue is empty or not\n";
		cout<<"6:Dispaly Elements\n";
		cout<<"0:Exit the application\n";
		
		cin>>option;
		
		switch(option)
		{
			case 1:
				cout<<"Enter a number\n";
				cin>>No;
				qobj.EnQueue(No);
				break;
			case 2:
				iRet = qobj.DeQueue();
				cout<<"Element removed whose value is:"<<iRet<<"\n";
				
				break;
			case 3:
				iRet = qobj.Front();
				cout<<"First element in queue is:"<<iRet<<"\n";
				break;
			case 4:
				iRet = qobj.Count();
				cout<<"Number of elements in queue are:"<<iRet<<"\n";
				break;
				
			case 5:
				iRet =qobj.IsEmptyQueue();
				if (iRet == true)
				{
					cout<<"Queue is Empty\n";
				}
				else
				{
					cout<<"Queue is not Empty\n";
				}
				break;
			case 6:
				qobj.Display();
				break;
				
			case 0:
				cout<<"Thank you for using application\n";
				break;
			default:
				cout<<"Enter a valid option\n";
				break;
		}
		
	}
	
	
	return 0;
}