class rbtnode:
    def __init__(self, val) :
        self.parent = None
        self.red = False # ie. black
        self.left = None
        self.right = None
        self.val = val

