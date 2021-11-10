#include<iostream>
using namespace std;

template <class T>
struct node
{
	T Data;
	struct node *next;
};

template <class T>
class SinglyLL
{
	private:
		int Size;
		struct node<T>* Head;
	public:
	SinglyLL();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPosition(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPosition(int);
	void Display();
	int Count();
};

template <class T>
SinglyLL<T> :: SinglyLL()
{
	Size = 0;
	Head = NULL;
}
template <class T>
void SinglyLL<T>:: InsertFirst(T no)
{
	struct node<T>* newn = new struct node<T>;
	newn->Data = no;
	newn->next = NULL;
	if (Head == NULL)
	{
		Head = newn;
		Size ++;
	}
	else
	{
		newn->next = Head;
		Head = newn;
		Size ++;
	}
}
template <class T>
void SinglyLL<T> :: InsertLast(T no)
{
	struct node<T>* temp = Head;
	struct node<T>* newn = new struct node<T>;
	newn->Data = no;
	newn->next = NULL;
	if (Head == NULL)
	{
		Head = newn;
		Size++;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
		Size++;
	}
}
template <class T>
void SinglyLL<T>::InsertAtPosition(T no,int pos)
{
	struct node<T>* temp = Head;
	struct node<T>* newn = new struct node<T>;
	newn->Data = no;
	newn->next = NULL;
	
	if ((pos <1)||(pos>Size+1))
	{
		return;
	}
	else if (pos == 1)
	{
		InsertFirst(no);
	}
	else if(pos == Size+1)
	{
		InsertLast(no);
	}
	else
	{
		for (int i=1;i<pos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;
		Size++;
	}
}
template <class T>
void SinglyLL<T> :: DeleteFirst()
{
	struct node<T>* temp = Head;
	if(Head == NULL)
	{
		return;
	}
	if (Head->next == NULL)
	{
		delete(Head);
		Head = NULL;
		Size--;
	}
	else
	{
		Head = temp->next;
		delete(temp);
		Size--;
	}
}
template <class T>
void SinglyLL<T>::DeleteLast()
{
	struct node<T>* temp = Head;
	if(Head == NULL)
	{
		return;
	}
	if (Head->next == NULL)
	{
		delete(Head);
		Head = NULL;
		Size--;
	}
	else
	{
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		delete(temp->next);
		temp->next = NULL;
		Size--;
		
	}
}
template <class T>
void SinglyLL<T>:: DeleteAtPosition(int Pos)
{
	struct node<T>* target=NULL;
	struct node<T>* temp = Head;
	if ((Pos < 1)||(Pos > Size))
	{
		return;
	}
	else if(Pos == 1)
	{
		DeleteFirst();
	}
	else if(Pos == Size)
	{
		DeleteLast();
	}
	else
	{
		for (int i = 1;i<(Pos-1);i++)
		{
			temp = temp->next;
		}
		target = temp->next;
		temp->next = target->next;
		delete(target);
		Size--;
	}
}
template <class T>
void SinglyLL<T> :: Display()
{
	struct node<T>* temp = Head;
	while(temp != NULL)
	{
		cout<<"|"<<temp->Data<<"|=>";
		temp = temp->next;
	}
	cout<<"\n";
}
template <class T>
int SinglyLL<T> :: Count()
{
	return Size;
}

int main()
{
	SinglyLL <int>obj;
	int Value = 0;
	int Pos = 0,choice = 1,ret = 0;
	while(choice !=0)
	{
		cout<<"\n==============================\n";
		cout<<"SINGLY LINKED LIST\n";
		cout<<"1:InsertFirst \n";
		cout<<"2:InsertLast \n";
		cout<<"3:InsertAtPosition \n";
		cout<<"4:DeleteFirst \n";
		cout<<"5:DeleteLast \n";
		cout<<"6:DeleteAtPosition \n";
		cout<<"7:Display \n";
		cout<<"8:Count \n";
		cout<<"9:Exit \n";
		cout<<"\n==============================\n";
		cout<<"Please enter your choice:";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
			{
				cout<<"Enter a element:";
				cin>>Value;
				obj.InsertFirst(Value);
				break;
			}
			case 2:
			{
				cout<<"Enter a element:";
				cin>>Value;
				obj.InsertLast(Value);
				break;
			}
			case 3:
			{
				cout<<"Enter a element:";
				cin>>Value;
				cout<<"Enter a position:";
				cin>>Pos;
				obj.InsertAtPosition(Value,Pos);
				break;
			}
			case 4:
			{
				obj.DeleteFirst();
				break;
			}
			case 5:
			{
				obj.DeleteLast();
				break;
			}
			case 6:
			{
				cout<<"Enter position:";
				cin>>Pos;
				obj.DeleteAtPosition(Pos);
				break;
			}
			case 7:
			{
				obj.Display();
				break;
			}
			case 8:
			{
				ret = obj.Count();
				cout<<"Number of nodes in linked list:"<<ret<<"\n";
				break;
			}
			case 9:
			{
				cout<<"Thank your for using application\n";
				return 0;
			}
			default:
			{
				cout<<"Please eneter valid choice";
				break;
			}
		}
	}
	
	return 0;
	
}