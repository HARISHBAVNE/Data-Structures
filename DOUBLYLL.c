/////////////////////////////////////////////////////////////////////////////////
// Application Name: DOUBLYLL
// Description: It is a Doubly linear linked list (Data structure) application.
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
void InsertFirst(PPNODE Head,int No)
{
	PNODE newn = (PNODE)malloc(sizeof(NODE));
	newn->Data = No;
	newn->next = NULL;
	newn->prev = NULL;
	
	if (*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		newn->next = *Head;
		newn->next->prev = newn;
		*Head = newn;
	}
}

// Function for Insert Node at Last in Linked List.
void InsertLast(PPNODE Head,int No)
{
	PNODE newn = (PNODE)malloc(sizeof(NODE));
	newn->Data = No;
	newn->next = NULL;
	newn->prev = NULL;
	PNODE temp = *Head;
	if (*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		while(temp->next !=NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
		newn->prev = temp;
	}
}

// Function for Count Number of Nodes in Linked List.
int Count(PNODE Head)
{
	int iCnt = 0;
	while(Head != NULL)
	{
		iCnt++;
		Head = Head->next;
	}
	return iCnt;
}

// Function for Insert node at said position in Linked List.
void InsertAtPosition(PPNODE Head,int No,int Pos)
{
	PNODE newn = (PNODE)malloc(sizeof(NODE));
	newn->Data = No;
	newn->next = NULL;
	newn->prev = NULL;
	PNODE temp = *Head;
	int iSize = Count((*Head));
	if ((Pos < 1)||(Pos >iSize+1))
	{
		return;
	}
	if (Pos == 1)
	{
		InsertFirst(Head,No);
	}
	else if(Pos == iSize+1)
	{
		InsertLast(Head,No);
	}
	else
	{
		int i = 0;
		for (i=1;i<Pos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		newn->next->prev = newn;
		temp->next = newn;
		newn->prev = temp;
	}
}	

// Function for Delete Node at First in Linked List.
void DeleteFirst(PPNODE Head)
{
	PNODE temp = *Head;
	if (*Head == NULL)
	{
		return;
	}
	else if((*Head)->next == NULL)
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{
		*Head = temp->next;
		temp->prev = NULL;
		free(temp);
	}
}

// Function for Delete Node at Last in Linked List.
void DeleteLast(PPNODE Head)
{
	PNODE temp = *Head;
	if (*Head == NULL)
	{
		return;
	}
	else if((*Head)->next == NULL)
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
	}
}

// Function for Display Linked List Elements.
void Display(PNODE Head)
{
	printf("NULL<=>");
	while(Head != NULL)
	{
		printf("|%d|<=>",Head->Data);
		Head = Head->next;
	}
	printf("NULL");
}

// Function for Insert node at said position in Linked List.
void DeleteAtPosition(PPNODE Head,int Pos)
{
	int i = 0;
	PNODE temp = *Head;
	int iSize = Count((*Head));
	if ((Pos < 1)||(Pos >iSize))
	{
		return;
	}
	else if(Pos == 1)
	{
		DeleteFirst(Head);
	}
	else if(Pos == iSize)
	{
		DeleteLast(Head);
	}
	else
	{
		for (i=1;i<Pos-1;i++)
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
	while (choice != 0)
	{
		printf("\n-----------------------------------------------------\n");
		printf("\n* Application of Doubly Linrear Linked List *\n\n");
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
				InsertFirst(&First,Value);
				break;
				
			case 2:
				printf("Enter a element:");
				scanf("%d",&Value);
				InsertLast(&First,Value);
				break;
				
			case 3:
				printf("Enter a element:");
				scanf("%d",&Value);
				
				printf("Enter a Position:");
				scanf("%d",&Pos);
				InsertAtPosition(&First,Value,Pos);
				break;
				
			case 4:
				DeleteFirst(&First);
				break;
				
			case 5:
				DeleteLast(&First);
				break;
				
			case 6:
				printf("Enter a position:");
				scanf("%d",&Pos);
				DeleteAtPosition(&First,Pos);
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