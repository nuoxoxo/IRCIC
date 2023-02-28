import random

class treenode :
    def __init__(self, val) :
        self.parent = None
        self.red = False # ie. black
        self.left = None
        self.right = None
        self.val = val

class tree :
    def __init__(self) :
        self.null = treenode(0)
        self.null.red = False # ie. black
        self.null.left = None
        self.null.right = None
        self.root = self.null

    def __repr__(self) :
        a = []
        Inorder_Printer(self.root, a)
        return '\n'.join(a)

    def Rotate_Right(self, x):
        y = x.left
        x.left = y.right
        if y.right != self.null:
            y.right.parent = x
        y.parent = x.parent # idem
        if x.parent == None:
            self.root = y
        elif x == x.parent.right:
            x.parent.right = y
        else:
            x.parent.left = y
        y.right = x
        x.parent = y

    def Rotate_Left(self, x):
        y = x.right
        x.right = y.left
        if y.left != self.null:
            y.left.parent = x
        y.parent = x.parent # idem
        if x.parent == None:
            self.root = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y

    def Fix(self, node):
        while node != self.root and node.parent.red == True:
            
            if node.parent == node.parent.parent.right: # if parent is a R node
                uncle = node.parent.parent.left
                
                if uncle.red == True:
                    uncle.red = False
                    node.parent.red = False
                    node.parent.parent.red = True
                    node = node.parent.parent
                else:
                    if node == node.parent.left:
                        node = node.parent
                        self.Rotate_Right(node) # Rotate Right
                    node.parent.red = False
                    node.parent.parent.red = True
                    self.Rotate_Left(node.parent.parent) # Rotate Left
            else:
                uncle = node.parent.parent.right

                if uncle.red == True:
                    uncle.red = False
                    node.parent.red = False
                    node.parent.parent.red = True
                    node = node.parent.parent
                else:
                    if node == node.parent.right:
                        node = node.parent
                        self.Rotate_Left(node) # Rotate Left
                    node.parent.red = False
                    node.parent.parent.red = True
                    self.Rotate_Right(node.parent.parent)
        self.root.red = False

    def Insert(self, val):

        # make a node
        node = treenode(val)
        node.red = True # new node has to be red
        node.parent = None
        node.left = self.null
        node.right = self.null
        
        # class bst Insertion ---> find the currect parent
        parent = None
        current = self.root
        while current != self.null:
            parent = current
            if current.val == parent.val:
                return
            if current.val > parent.val:
                current = current.left
            else:
                current = current.right
        node.parent = parent
        if parent == None:
            self.root = node
        elif parent.val > node.val:
            parent.left = node
        elif parent.val < node.val:
            parent.right = node

        # Fixing the tree
        self.Fix(node)

def Inorder_Printer(node, a, level = 0):
    if node.val != 0:
        Inorder_Printer(node.left, a, level + 1)
        a.append('-' * 4 * level + 
                '> ' + str(node.val) + 
                ' ' + ('Red' if node.red else 'Black'))
        Inorder_Printer(node.right, a, level + 1)

def Number_Generator(bound):
    random.seed(1)
    res = []
    for _ in range(bound):
        res.append(random.randint(1, bound - 1))
    return res


def main():
    bound = 256
    random.seed(1)
    tree_no_1 = tree()
    for _ in range(bound):
        tree_no_1.Insert(random.randint(1, bound + 1))
    print(tree_no_1)


main()




