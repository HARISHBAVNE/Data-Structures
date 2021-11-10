class node:
    def __init__(self,Data):
        self.Data = Data
        self.Lchild = None
        self.Rchild = None

class Tree:
    Size = 0
    
    def __init__(self):
        self.Head = None   
    def InsertNode(self,Data):
        temp = self.Head
        Newn = node(Data)
        if (self.Head == None):
            self.Head = Newn
            Tree.Size += 1
        else:
            while True:
                if (Data < temp.Data):
                    if (temp.Lchild == None):
                        temp.Lchild = Newn
                        Tree.Size += 1
                        break
                    temp = temp.Lchild
                elif (Data > temp.Data):
                    if (temp.Rchild == None):
                        temp.Rchild = Newn
                        Tree.Size += 1
                        break
                    temp = temp.Rchild
                elif (Data == temp.Data):
                    print("Duplicate Entry")
                    break
    def Count(self):
        return Tree.Size
    def Inorder(self,Root):
        if (Root != None):
            self.Inorder(Root.Lchild)
            print(Root.Data,end=" ")
            self.Inorder(Root.Rchild)
    
    def Preorder(self,Root):
        if (Root != None):
            print(Root.Data,end=" ")
            self.Preorder(Root.Lchild)
            self.Preorder(Root.Rchild)
            
    def Postorder(self,Root):
        if (Root != None):
            self.Postorder(Root.Lchild)
            self.Postorder(Root.Rchild)        
            print(Root.Data,end=" ")
def main():
    Root = Tree()
    Root.InsertNode(21)
    Root.InsertNode(35)
    Root.InsertNode(30)
    Root.InsertNode(15)
    Root.InsertNode(32)
    Root.InsertNode(19)
    Root.InsertNode(20)
    

    Root.Inorder(Root.Head)

if __name__ == "__main__":
    main()
