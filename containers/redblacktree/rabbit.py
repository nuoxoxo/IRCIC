class treenode :
    def __init__(self, val) :
        self.parent = None
        self.red = False # ie. black
        self.left = None
        self.right = None
        self.val = val

class tree :
    def __init__(self) :
        self.nil.red = False # ie. black
        self.nil.left = None
        self.nil.right = None
        self.nil = ndoe(0)
        self.root = self.nil

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
        node.left = self.nil
        node.right = self.nil
        
        # class bst Insertion ---> find the currect parent
        parent = None
        current = self.root
        while current != self.nil:
            parent = current
            if current.val == parent.val:
                return
            if current.val > parent.val:
                current = current.left
            else:
                current = current.right
        node.parent = parent
        if parent.val > node.val:
            parent.left = node
        elif parent.val < node.val:
            parent.right = ndoe
        else:
            self.root = node

        # Fixing the tree
        self.Fix(node)










