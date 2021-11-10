##############################################################################
# Application Name: SINGLYLL
# Description: It is a Singly linear linked list (Data structure) application.
# Date: 05/10/2021.
# Author Name: Harish Vijay Bavne
##############################################################################

# Node Declaration
class node:
    def __init__(self,no):
        self.Data = no
        self.next = None
        
# Class for Singly linear Linked list
class SinglyLL:
    # class variable private for node count
    __Size = 0                      
    
    def __init__(self):
        # Head is for first node reference
        self.Head = None            
        
        
    # Function for Insert elements in linked list at first position
    def InsertFirst(self,No):       
        newn = node(No)
        if (self.Head == None):
            self.Head = newn
            SinglyLL.__Size = SinglyLL.__Size + 1
        else:
            newn.next = self.Head
            self.Head = newn
            SinglyLL.__Size = SinglyLL.__Size + 1
    
    # Function for Insert element in linked list at last position
    def InsertLast(self,No):
        newn = node(No)
        if (self.Head == None):
            self.Head = newn
            SinglyLL.__Size = SinglyLL.__Size + 1
        else:
            temp = self.Head
            while(temp.next != None):
                temp = temp.next
            temp.next = newn    
            SinglyLL.__Size = SinglyLL.__Size + 1
    
    # Function for Insert element in linked list at said position
    def InsertAtPosition(self,No,Pos):
        newn = node(No)
        temp = self.Head
        iSize = SinglyLL.__Size
        if ((Pos < 1) or (Pos > iSize+1)):
            return
        if (Pos == 1):
            self.InsertFirst(No)
        elif (Pos == iSize+1):
            self.InsertLast(No)
        else:    
            print("P")
            for i in range(1,Pos-1):
                temp = temp.next
            newn.next = temp.next
            temp.next = newn
            SinglyLL.__Size = SinglyLL.__Size + 1
    
    # Function for Delete element in Linked list at first position
    def DeleteFirst(self):
        temp = self.Head
        if (self.Head == None):
            return
        elif (self.Head.next == None):
            del(temp)
            self.Head = None
            SinglyLL.__Size = SinglyLL.__Size - 1
        else:
            self.Head = temp.next
            del(temp)
            SinglyLL.__Size = SinglyLL.__Size - 1
    
    # Function for Delete element in Linked list at Last position
    def DeleteLast(self):
        temp = self.Head
        if (self.Head == None):
            return
        elif (self.Head.next == None):
            del(temp)
            self.Head = None
            SinglyLL.__Size = SinglyLL.__Size - 1
        else:
            for i in range(1,SinglyLL.__Size-1):
                temp = temp.next
            del(temp.next)
            temp.next = None
            SinglyLL.__Size = SinglyLL.__Size - 1
    
    # Function for Delete element at said position in Linked list
    def DeleteAtPosition(self,Pos):
        temp =self.Head
        iSize = SinglyLL.__Size
        target = None
        if ((Pos < 1)or(Pos > iSize)):
            return
        elif (Pos == 1):
            self.DeleteFirst()
        elif (Pos == iSize):
            self.DeleteLast()
        else:
            for i in range(1,Pos-1):
                temp = temp.next
            target = temp.next
            temp.next = target.next
            del(target)
            SinglyLL.__Size = SinglyLL.__Size - 1
    
    # Function for Display elements in linked list
    def Display(self):
        temp = self.Head
        while(temp != None):
            print(f"|{temp.Data}|=>",end="")
            temp = temp.next
        print("None")
        
    # Function for count number of Nodes in linked list
    def Count(self):
        return SinglyLL.__Size
    
# Entry point function main.
def main():
    obj = SinglyLL()
    def menu():
        print("*********************************")
        print("1:Insert First")
        print("2:Insert last")
        print("3:Insert at Position")
        print("4:DeleteFirst ")
        print("5:DeleteLast")
        print("6:DeleteAtPosition")
        print("7:Display element")
        print("8:Count Number of Nodes")
        print("0:Exit application")
        print("*********************************")
    menu()
    choice = int(input("Enter a your choice:"))
    while True:
        if (choice == 1):
            No = int(input("Enter Element:"))
            obj.InsertFirst(No)
        elif (choice == 2):
            No = int(input("Enter Element:"))
            obj.InsertLast(No)
        elif (choice == 3):
            No = int(input("Enter Element:"))
            Pos = int(input("Enter position:"))
            obj.InsertAtPosition(No,Pos)
        elif (choice == 4):
            obj.DeleteFirst()
        elif (choice == 5):
            obj.DeleteLast()
        elif (choice == 6):
            Pos = int(input("Enter a position:"))
            obj.DeleteAtPosition(Pos)
        elif (choice == 7):
            obj.Display()
        elif (choice == 8):
            Ret = obj.Count()
            print(f"Number of Nodes are:{Ret}")
        elif (choice == 0):
            print("Thank you for using application")
            break
        else:
            print("Enter a correct choice.")
        menu()
        choice = int(input("Enter a your choice:"))
# Starter
if __name__ == "__main__":
    main()