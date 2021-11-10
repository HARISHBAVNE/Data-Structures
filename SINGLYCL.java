
//////////////////////////////////////////////////////////////////////////////////
//
// Application Name: SINGLYCL.
// Description: It is a Singly Circular linked list (Data structure) application.
// Date: 06/10/2021.
// Author Name: Harish Vijay Bavne.
//
//////////////////////////////////////////////////////////////////////////////////

// Required packages
import java.util.*;


// class for Node creation.
class node
{
	public int Data;		// Variable for Element.
	public node next;		// For refrence to next node.
	public node(int no)
	{
		Data = no;
		next = null;
	}
}

// class for Linked list.
class LinkedList
{
	public node Head;		// To store first node reference.
	public node Tail;		// To store last node reference.
	private int Size;		// For number of elements in Linked list.
	{
		Size = 0;
		Head = null;
		Tail = null;
	}
	
	// Function for insert element at first position in Linked list.
	public void InsertFirst(int No)
	{
		node newn = new node(No);
		if (Head == null)
		{
			Head = newn;
			Tail = newn;
			Tail.next = Head;
			Size++;
		}
		else
		{
			newn.next = Head;
			Head = newn;
			Tail.next = Head;
			Size++;
		}
	}

	// Function for insert element at last position in Linked list.
	public void InsertLast(int No)
	{	
		node newn = new node(No);
		node temp = Head;
		if (Head == null)
		{
			Head = newn;
			Tail = newn;
			Tail.next = Head;
			Size++;
		}
		else
		{
			for (int i = 1;i<Size;i++)
			{
				temp = temp.next;
			}
			temp.next = newn;
			Tail = newn;
			Tail.next = Head;
			Size++;
		}
	}

	// Function for insert element at said position in linked list.
	public void InsertAtPosition(int No,int Pos)
	{
		node newn = new node(No);
		node temp = Head;
		if((Pos < 1)||(Pos >Size+1))
		{
			return;
		}
		else if(Pos == 1)
		{
			InsertFirst(No);
		}
		else if(Pos == Size+1)
		{
			InsertLast(No);
		}
		else
		{
			for(int i = 1;i<(Pos-1);i++)
			{
				temp = temp.next;
			}
			newn.next = temp.next;
			temp.next = newn;
			Size++;
		}
	}

	// Function for delete element at first position in Linked List.
	public void DeleteFirst()
	{
		//node temp = Head;
		if (Head == null)
		{
			return;
		}
		else
		{
			//Head = temp.next;
			Head = Head.next;
			Tail.next = Head;
			Size--;
		}
	}

	// Function for delete element at last position in Linked List.
	public void DeleteLast()
	{
		node temp = Head;
		if (Head == null)
		{
			return;
		}
		else if(temp.next == null)
		{
			Head = null;
			Tail = null;
			
			Size--;
		}	
		else
		{
			for (int i = 1;i<(Size-1);i++)
			{
				temp = temp.next;
			}
			temp.next = null;
			Tail = temp;
			Tail.next = Head;
			Size--;
		}
	}

	// Function for delete element at said position in Linked List.
	public void DeleteAtPosition(int Pos)
	{
		node temp = Head;
		if ((Pos < 1)||(Pos > Size))
		{
			return;
		}
		else if (Pos == 1)
		{
			DeleteFirst();
		}
		else if (Pos == Size)
		{
			DeleteLast();
		}
		else
		{
			for (int i = 1;i<(Pos-1);i++)
			{
				temp = temp.next;
			}
			temp.next = temp.next.next;
			Size--;
		}
	}

	// Function for Displaying elements in linked list.
	public void Display()
	{
		node temp = Head;
		for (int i = 1;i<=Size;i++)
		{
			System.out.print("|"+temp.Data+"|"+"=>");
			temp = temp.next;
		}
		System.out.println("null");
	}

	// Function for Counting number of elements in linked list.
	public int Count()
	{
		return Size;
	}
}

// Entry point main function.
class SINGLYCL
{
	public static int Choice;
	{
		Choice = 0;
	}
	public static void main(String arg[])
	{
		LinkedList obj = new LinkedList();
		Scanner sobj = new Scanner(System.in);
		SINGLYCL.menu();
		System.out.println("Enter a choice:");
		Choice = sobj.nextInt();
		while (true)
		{
			if (Choice ==1)
			{
				System.out.println("Enter a number:");
				int no = sobj.nextInt();
				obj.InsertFirst(no);
			}
			else if (Choice ==2)
			{
				System.out.println("Enter a number:");
				int no = sobj.nextInt();
				obj.InsertLast(no);	
			}
			else if (Choice ==3)
			{
				System.out.println("Enter a number:");
				int no = sobj.nextInt();
				System.out.println("Enter a position:");
				int Pos = sobj.nextInt();
				obj.InsertAtPosition(no,Pos);
				
			}
			else if (Choice ==4)
			{
				obj.DeleteFirst();
			}
			else if (Choice ==5)
			{
				obj.DeleteLast();
			}
			else if (Choice ==6)
			{
				System.out.println("Enter a position:");
				int Pos = sobj.nextInt();
				obj.DeleteAtPosition(Pos);
			}
			else if (Choice ==7)
			{
				obj.Display();
			}
			else if (Choice ==8)
			{
				System.out.println("Number of nodes are:"+obj.Count());
			}
			else if (Choice ==0)
			{
				System.out.println("Thank you for using application.");
				break;
			}
			else
			{
				System.out.println("Please provide Valid choice number.");
			}
			SINGLYCL.menu();
			System.out.println("Enter a choice:");
			Choice = sobj.nextInt();
		}	

	}
	public static void menu()
	{
		System.out.println("**********************************");
		System.out.println("     Singly Circular Linked List    ");
		System.out.println("1:Insert First");
		System.out.println("2:Insert Last");
		System.out.println("3:Insert At Position");
		System.out.println("4:Delete First");
		System.out.println("5:Delete Last");
		System.out.println("6:Delete At Position");
		System.out.println("7:Display Element");
		System.out.println("8:Count Number of nodes");
		System.out.println("0:Thank for using application.");
		System.out.println("**********************************");
	}
}