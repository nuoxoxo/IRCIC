# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        def helper(node: Optional[TreeNode], curr: int) -> int:
            if not node:
                return 0
            res = 10 * curr + node.val
            if not node.left and not node.right:
                return res
            return helper(node.left, res) + helper(node.right, res)
        return helper(root, 0)
