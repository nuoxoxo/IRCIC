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

def insert(self, val):

    # make a node
    node = treenode(val)
    node.red = True # new node has to be red
    node.parent = None
    node.left = self.nil
    node.right = self.nil
    
    # class bst insertion ---> find the currect parent
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

    # fixing red black tree
    # self.fix(node)










