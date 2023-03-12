import random, time

class treenode :
    def __init__(self, val) :
        self.red = False # ie. black
        self.parent = None
        self.left = None
        self.right = None
        self.val = val

class tree :
    def __init__(self) :
        self.nil = treenode(0)
        self.nil.red = False # ie. black
        self.nil.left = None
        self.nil.right = None
        self.root = self.nil

    def __repr__(self) :
        a = []
        Inorder_Printer(self.root, a)
        return '\n'.join(a)

    def Rotate_Right(self, x):
        y = x.left
        x.left = y.right
        if y.right != self.nil:
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
        if y.left != self.nil:
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
        node.left = self.nil
        node.right = self.nil
        
        # classic binary search tree insertion ---> find correct parent
        parent = None
        current = self.root
        while current != self.nil:
            parent = current
            if current.val == node.val:
                return
            if current.val > node.val:
                current = current.left
            else:
                current = current.right
    
            # buggy part : fixed
            """
            if current.val == parent.val:
                return
            if current.val > parent.val:
                current = current.left
            else:
                current = current.right
            """

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
    bound = 64
    offset = 100
    random.seed(time.clock())
    # random.seed(0)
    rbt = tree()
    for _ in range(bound):
        rbt.Insert(random.randint(1, bound + offset))
    print(rbt)


# main()

if __name__ == "__main__":
    main()


