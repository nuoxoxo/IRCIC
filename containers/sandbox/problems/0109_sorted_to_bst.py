class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        a = []
        p = head
        while p:
            a.append(p.val)
            p = p.next
        def make_tree(L: int, R: int):
            if L > R:
                return None
            mid = (L + R) // 2
            node = ListNode(a[mid])
            node.left = make_tree(L, mid - 1)
            node.right = make_tree(mid + 1, R)
            return node
        return make_tree(0, len(a) - 1)

