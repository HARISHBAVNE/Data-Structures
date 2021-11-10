/////////////////////////////////////////////////////////////////////////////////
// Application Name: SINGLYCL
// Description: It is a Singly Circular linked list (Data structure) application.
// Date: 21/09/2021.
// Author Name: Harish Vijay Bavne.
/////////////////////////////////////////////////////////////////////////////////

// Required Header files inclusion.
#include<stdio.h>
#include<stdlib.h>

// Creation of Node.
struct node
{
	int Data;
	struct node* Next;
};

// Required typedef's
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

// Function for insert node at first.
void InsertFirst(PPNODE Head,PPNODE Tail,int No)
{
	PNODE Newn = (PNODE)malloc(sizeof(NODE));
	Newn->Data = No;
	Newn->Next = NULL;
	
	if (*Head == NULL)
	{
		*Head = Newn;
		*Tail = Newn;
	}
	else
	{
		Newn->Next = *Head;
		*Head = Newn;
	}
	(*Tail)->Next = *Head;
}

// Function for insert node at last.
void InsertLast(PPNODE Head,PPNODE Tail,int No)
{
	PNODE Newn = (PNODE)malloc(sizeof(NODE));
	Newn->Data = No;
	Newn->Next = NULL;
	PNODE temp = *Head;
	if (*Head == NULL)
	{
		*Head = Newn;
		*Tail = Newn;
		(*Tail)->Next = *Head;
	}
	else
	{
		while(temp->Next != (*Head))
		{
			temp = temp->Next;
		}
		temp->Next = Newn;
		(*Tail) = Newn;
		(*Tail)->Next = *Head;
			
	}
}

// Function for display element's in Linked List.
void Display(PNODE Head)
{
	PNODE temp = Head;
	if (Head == NULL)
	{
		printf("Linked List is Empty.\n");
		return;
	}
	while(temp->Next != Head)
	{
		printf("|%d|->",temp->Data);
		temp = temp->Next;
	}
	printf("|%d|->",temp->Data);
	printf("|First|\n");
}

// Function for counting number of nodes present in Linked List.
int Count(PNODE Head)
{
	int iCnt = 0;
	if (Head == NULL)
	{
		return 0;
	}
	PNODE temp = Head;
	while(temp->Next != Head)
	{
		iCnt ++;
		temp = temp->Next;
	}
	iCnt ++;
	return iCnt;
}

// Function for inserting node at said position.
void InsertAtPosition(PPNODE Head,PPNODE Tail,int No,int Pos)
{
	PNODE Newn = (PNODE)malloc(sizeof(NODE));
	Newn->Data = No;
	Newn->Next = NULL;
	PNODE temp = *Head;
	int i = 0;
	int iSize = Count(*Head);
	
	if ((Pos < 1)||(Pos>iSize+1))
	{
		return;
	}
	else if(Pos == 1)
	{
		InsertFirst(Head,Tail,No);
	}
	else if(Pos == iSize+1)
	{
		InsertLast(Head,Tail,No);
	}
	else
	{
		for (i = 1;i<Pos-1;i++)
		{
			temp = temp->Next;
		}
		Newn->Next = temp->Next;
		temp->Next = Newn;
	}
}

// Function for delete first node.
void DeleteFirst(PPNODE Head,PPNODE Tail)
{
	PNODE temp = *Head;
	if (*Head == NULL)
	{
		return;
	}
	else if (temp->Next == (*Head))
	{
		free(temp);
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{
		*Head = temp->Next;
		free(temp);
		(*Tail)-> Next= *Head;
	}
}

// Function for delete last node.
void DeleteLast(PPNODE Head,PPNODE Tail)
{
	PNODE temp = *Head;
	if (*Head == NULL)
	{
		return;
	}
	else if (temp->Next == (*Head))
	{
		free(temp);
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{
		while(temp->Next->Next != *Head)
		{
			temp = temp->Next;
		}
		free(temp->Next);
		*Tail = temp;
		(*Tail)->Next = *Head;
	}
}

// Function for delete node at said position.
void DeleteAtPosition(PPNODE Head,PPNODE Tail,int Pos)
{
	int i = 0;
	int iSize = Count((*Head));
	PNODE temp = *Head;
	PNODE Target = NULL;
	if ((Pos < 1)||(Pos >iSize))
	{
		return;
	}
	else if(Pos == 1)
	{
		DeleteFirst(Head,Tail);
	}
	else if(Pos == iSize)
	{
		DeleteLast(Head,Tail);
	}
	else
	{
		for (i = 1;i<Pos-1;i++)
		{
			temp = temp->Next;
		}
		Target = temp->Next;
		temp->Next = Target->Next;
		free(Target);
	}
}

// Entry point function.
int main()
{
	int iRet = 0,choice = 1,Value = 0,Pos = 0;
	PNODE First = NULL;
	PNODE Tail = NULL;
	while (choice != 0)
	{
		printf("\n-----------------------------------------------------\n");
		printf("\n* Application of Singly Circular Linked List *\n\n");
		printf("1:Insert node at first\n");
		printf("2:Insert node at last\n");
		printf("3:Insert node at position\n");
		printf("4:Delete node at first\n");
		printf("5:Delete node at last\n");
		printf("6:Delete node at position\n");
		printf("7:Dispay node elements\n");
		printf("8:Count Number of nodes\n");
		printf("9:Exit the application\n");
		printf("\n-----------------------------------------------------\n");
		printf("Enter a choice:");
		scanf("%d",&choice);
		
		switch (choice)
		{
			case 1:
				printf("Enter a element:");
				scanf("%d",&Value);
				InsertFirst(&First,&Tail,Value);
				break;
			case 2:
				printf("Enter a element:");
				scanf("%d",&Value);
				InsertLast(&First,&Tail,Value);
				break;
			case 3:
				printf("Enter a element:");
				scanf("%d",&Value);
				
				printf("Enter a Position:");
				scanf("%d",&Pos);
				InsertAtPosition(&First,&Tail,Value,Pos);
				break;
			case 4:
				DeleteFirst(&First,&Tail);
				break;
			case 5:
				DeleteLast(&First,&Tail);
				break;
			case 6:
				printf("Enter a position:");
				scanf("%d",&Pos);
				DeleteAtPosition(&First,&Tail,Pos);
				break;
			case 7:
				Display(First);
				break;	
			case 8:
				iRet = Count(First);
				printf("Number of nodes are:%d\n",iRet);
				break;	
			case 9:
				printf("Thank you for using Apllication.");
				return 0;
			default:
				printf("Enter a correct choice.\n");
				break;	
		}
	}
	return 0;
}
