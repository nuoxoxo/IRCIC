function sortedListToBST(head: ListNode | null): TreeNode | null {
    let a = []
    let p = head
    while (p) {
        a.push(p.val)
        p = p.next
    }
    return make_tree(a, 0, a.length - 1)
};

function make_tree(a, L, R): TreeNode { // Ts
    if (L > R)
        return null
    let mid = Math.floor((R - L) / 2) + L
    let node = new TreeNode(a[mid])
    node.left = make_tree(a, L, mid - 1)
    node.right = make_tree(a, mid + 1, R)
    return node
}
