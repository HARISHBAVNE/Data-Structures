/////////////////////////////////////////////////////////////////////////////////
// Application Name: DOUBLYLL
// Description: It is a Doubly circular linked list (Data structure) application.
//			    It is used to store data in linear format.
// Date: 29/09/2021.
// Author Name: Harish Vijay Bavne.
/////////////////////////////////////////////////////////////////////////////////


// Required Header file inclusion.
#include<stdio.h>
#include<stdlib.h>

// Node declaration using structure
struct node
{
	int Data;
	struct node * next;
	struct node * prev;
	
};
// Require typedef's
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

// Function for Insert Node at First in Linked List.
void InsertFirst(PPNODE Head,PPNODE Tail,int No)
{
	PNODE newn = (PNODE)malloc(sizeof(NODE));
	newn->Data = No;
	newn->next = NULL;
	newn->prev = NULL;
	
	if (*Head == NULL)
	{
		*Head = newn;
		*Tail = newn;
		(*Tail)->next = *Head;
		(*Head)->prev = *Tail;
	}
	else
	{
		newn->next = *Head;
		newn->next->prev = newn;
		*Head = newn;
	}
	(*Tail)->next = *Head;
	(*Head)->prev = *Tail;
}

// Function for Insert Node at Last in Linked List.
void InsertLast(PPNODE Head,PPNODE Tail,int No)
{
	PNODE newn = (PNODE)malloc(sizeof(NODE));
	newn->Data = No;
	newn->next = NULL;
	newn->prev = NULL;
	PNODE temp = *Head;
	
	if(*Head == NULL)
	{
		*Head = newn;
		*Tail = newn;
		(*Tail)->next = *Head;
		(*Head)->prev = *Tail;
	}
	else
	{
		while(temp->next != *Head)
		{
			temp = temp->next;
		}
		temp->next = newn;
		*Tail = newn;
		(*Tail)->prev = temp;
		(*Tail)->next = *Head;
		(*Head)->prev = *Tail;
	}
}

// Function for Count Number of Nodes in Linked List.
int Count(PNODE Head,PNODE Tail)
{
	int iCnt = 0;
	PNODE temp = Head;
	if (Head == NULL)
	{
		return 0;
	}
	else
	{
		while(temp->next != Head)
		{
			iCnt++;
			temp = temp->next;
		}
		iCnt ++;
		return iCnt;
	}
}

// Function for Insert node at said position in Linked List.
void InsertAtPosition(PPNODE Head,PPNODE Tail,int No,int Pos)
{
	PNODE newn = (PNODE)malloc(sizeof(NODE));
	newn->Data = No;
	newn->next = NULL;
	newn->prev = NULL;
	PNODE temp = *Head;
	int i = 0;
	int iSize = Count((*Head),(*Tail));
	if ((Pos < 1)||(Pos >iSize+1))
	{
		return;
	}
	if (Pos == 1)
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
			temp = temp->next;
		}
		newn->next = temp->next;
		newn->next->prev = newn;
		newn->prev = temp;
		temp->next = newn;
	}
	
}	

// Function for Delete Node at First in Linked List.
void DeleteFirst(PPNODE Head,PPNODE Tail)
{
	PNODE temp = *Head;
	if((*Head == NULL)||(*Tail == NULL))
	{
		return;
	}
	if ((*Head)->next == *Head)
	{
		free(*Head);
		free(*Tail);
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{
		*Head = temp->next;
		free(temp);
		(*Head)->prev = *Tail;
		(*Tail)->next = *Head;
	}
	
}

// Function for Delete Node at Last in Linked List.
void DeleteLast(PPNODE Head,PPNODE Tail)
{
	PNODE temp = *Tail;
	if((*Head == NULL)||(*Tail == NULL))
	{
		return;
	}
	if ((*Head)->next == *Head)
	{
		free(*Head);
		free(*Tail);
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{
		*Tail = temp->prev;
		free(temp);
		(*Head)->prev = *Tail;
		(*Tail)->next = *Head;
	}
	
}

// Function for Display Linked List Elements.
void Display(PNODE Head,PNODE Tail)
{
	PNODE temp = Head;
	if (Head == NULL)
	{
		printf("NULL");
	}
	else
	{
		printf("|Last|<=>");
		while(temp->next != Head)
		{
			printf("|%d|<=>",temp->Data);
			temp = temp->next;
		}
		printf("|%d|",temp->Data);
		printf("<=>|First|");
	}
}

// Function for Delete node at said position in Linked List.
void DeleteAtPosition(PPNODE Head,PPNODE Tail,int Pos)
{
	int iSize = Count((*Head),(*Tail));
	PNODE temp = *Head;
	if ((Pos<1)||(Pos>iSize))
	{
		return;
	}
	if (Pos == 1)
	{
		DeleteFirst(Head,Tail);
	}
	else if(Pos == iSize)
	{
		DeleteLast(Head,Tail);
	}
	else
	{
		int i = 0;
		for(i = 1;i<Pos-1;i++)
		{
			temp = temp->next;
		}
		temp->next = temp->next->next;
		free(temp->next->prev);
		temp->next->prev = temp;
	}
}

// Entry point function.
int main()
{
	int iRet = 0,choice = 1,Value = 0,Pos = 0;
	PNODE First = NULL;
	PNODE Last = NULL;
	while (choice != 0)
	{
		printf("\n-----------------------------------------------------\n");
		printf("\n* Application of Doubly Circular Linked List *\n\n");
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
				InsertFirst(&First,&Last,Value);
				break;
				
			case 2:
				printf("Enter a element:");
				scanf("%d",&Value);
				InsertLast(&First,&Last,Value);
				break;
				
			case 3:
				printf("Enter a element:");
				scanf("%d",&Value);
				
				printf("Enter a Position:");
				scanf("%d",&Pos);
				InsertAtPosition(&First,&Last,Value,Pos);
				break;
				
			case 4:
				DeleteFirst(&First,&Last);
				break;
				
			case 5:
				DeleteLast(&First,&Last);
				break;
				
			case 6:
				printf("Enter a position:");
				scanf("%d",&Pos);
				DeleteAtPosition(&First,&Last,Pos);
				break;
				
			case 7:
				Display(First,Last);
				break;
				
			case 8:
				iRet = Count(First,Last);
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